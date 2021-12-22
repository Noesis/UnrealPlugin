////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRuntimeModule.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/CoreDelegates.h"
#include "Modules/ModuleManager.h"
#include "Stats/Stats.h"
#include "Stats/Stats2.h"
#include "UObject/UObjectBaseUtility.h"

// RenderCore includes
#include "ShaderCore.h"

// ApplicationCore includes
#include "HAL/PlatformApplicationMisc.h"

// Slate includes
#include "Widgets/Input/IVirtualKeyboardEntry.h"
#include "Framework/Application/SlateApplication.h"

// Engine includes
#include "ActiveSound.h"
#include "AudioDevice.h"

// Projects includes
#include "Interfaces/IPluginManager.h"

// NoesisRuntime includes
#include "NoesisResourceProvider.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisTypeClass.h"
#include "NoesisSettings.h"
#include "NoesisSupport.h"
#include "NoesisMediaPlayer.h"
#include "Extensions/LocTableExtension.h"
#include "Extensions/LocTextExtension.h"

// Noesis includes
#include "NoesisSDK.h"
#include "NsApp/MediaElement.h"

#if WITH_EDITOR
// AssetRegistry includes
#include "AssetRegistryModule.h"

// UnrealEd includes
#include "Editor.h"
#include "Kismet2/EnumEditorUtils.h"
#include "Kismet2/StructureEditorUtils.h"
#endif

extern "C" void NsRegisterReflectionAppInteractivity();
extern "C" void NsRegisterReflectionAppMediaElement();

#if UE_BUILD_SHIPPING + UE_BUILD_SHIPPING_WITH_EDITOR == 0
static void NoesisLogHandler(const char* File, uint32_t Line, uint32_t Level, const char* Channel, const char* Message)
{
	if (UObjectInitialized())
	{
		// LEVEL: [0=Off] [1=Error] [2=Warning] [3==Information] [4=Debug]
		ENoesisLoggingSettings refLevel = FCStringAnsi::Strcmp(Channel, "Binding") == 0 ?
			GetDefault<UNoesisSettings>()->BindingLogLevel :
			GetDefault<UNoesisSettings>()->GeneralLogLevel;

		bool filter = true;
		switch (refLevel)
		{
			case ENoesisLoggingSettings::Off: filter = true; break;
			case ENoesisLoggingSettings::Error: filter = Level < NS_LOG_LEVEL_ERROR; break;
			case ENoesisLoggingSettings::Warning: filter = Level < NS_LOG_LEVEL_WARNING; break;
			case ENoesisLoggingSettings::Information: filter = Level < NS_LOG_LEVEL_INFO; break;
			case ENoesisLoggingSettings::Debug: filter = false; break;
		}

		if (!filter)
		{
			switch (Level)
			{
				case 0: UE_LOG(LogNoesis, VeryVerbose, TEXT("%s"), *NsStringToFString(Message)); break;
				case 1: UE_LOG(LogNoesis, Verbose, TEXT("%s"), *NsStringToFString(Message)); break;
				case 2: UE_LOG(LogNoesis, Log, TEXT("%s"), *NsStringToFString(Message)); break;
				case 3: UE_LOG(LogNoesis, Warning, TEXT("%s"), *NsStringToFString(Message)); break;
				case 4: UE_LOG(LogNoesis, Error, TEXT("%s"), *NsStringToFString(Message)); break;
			}
		}
	}
}

void NoesisLog(const char* File, uint32_t Line, uint32_t Level, const char* Channel, const char* Format, ...)
{
	char Message[1024];

	va_list Args;
	va_start(Args, Format);
	vsnprintf(Message, sizeof(Message), Format, Args);
	va_end(Args);

	NoesisLogHandler(File, Line, Level, Channel, Message);
}
#endif

static void NoesisErrorHandler(const char* Filename, uint32 Line, const char* Desc, bool Fatal)
{
	if (Fatal)
	{
#if ENGINE_MAJOR_VERSION >= 5
		FDebug::FFailureInfo LlfeInfo = { "NoesisErrorHandler", Filename, (int32)Line, PLATFORM_RETURN_ADDRESS() };
		LowLevelFatalErrorHandler(LlfeInfo, TEXT("%s"), *NsStringToFString(Desc));
#else
		LowLevelFatalErrorHandler(Filename, Line, TEXT("%s"), *NsStringToFString(Desc));
#endif
	}

	NS_LOG("%s", Desc);
}

DECLARE_MEMORY_STAT(TEXT("CPU Memory"), STAT_NoesisMemory, STATGROUP_Noesis);
void* NoesisAllocationCallbackUserData = nullptr;
void* NoesisAlloc(void* UserData, size_t Size)
{
	void* Result = FMemory::Malloc(Size);
	SET_MEMORY_STAT(STAT_NoesisMemory, Noesis::GetAllocatedMemory());
	return Result;
}

void* NoesisRealloc(void* UserData, void* Ptr, size_t Size)
{
	void* Result = FMemory::Realloc(Ptr, Size);
	SET_MEMORY_STAT(STAT_NoesisMemory, Noesis::GetAllocatedMemory());
	return Result;
}

void NoesisDealloc(void* UserData, void* Ptr)
{
	FMemory::Free(Ptr);
	SET_MEMORY_STAT(STAT_NoesisMemory, Noesis::GetAllocatedMemory());
}

size_t NoesisAllocSize(void* UserData, void* Ptr)
{
	return FMemory::GetAllocSize(Ptr);
}

#if WITH_EDITOR
class NotifyEnumChanged : public FEnumEditorUtils::INotifyOnEnumChanged
{
public:
	virtual void PreChange(const UUserDefinedEnum* Changed, FEnumEditorUtils::EEnumEditorChangeInfo ChangedType) override { }
	virtual void PostChange(const UUserDefinedEnum* Changed, FEnumEditorUtils::EEnumEditorChangeInfo ChangedType) override
	{
		NoesisDestroyTypeClassForEnum((UUserDefinedEnum*)Changed);
	}
};

class NotifyStructChanged : public FStructureEditorUtils::INotifyOnStructChanged
{
public:
	virtual void PreChange(const UUserDefinedStruct* Changed, FStructureEditorUtils::EStructureEditorChangeInfo ChangedType) override { }
	virtual void PostChange(const UUserDefinedStruct* Changed, FStructureEditorUtils::EStructureEditorChangeInfo ChangedType) override
	{
		NoesisDestroyTypeClassForStruct((UUserDefinedStruct*)Changed);
	}
};

void OnBlueprintPreCompile(UBlueprint* Blueprint)
{
	NoesisDestroyTypeClassForBlueprint(Blueprint);
}

void OnAssetRenamed(const FAssetData& AssetData, const FString& OldPath)
{
	UObject* NewObject = AssetData.GetAsset();
	NoesisAssetRenamed(NewObject, OldPath);
}
#endif

void OnPostEngineInit()
{
	NoesisInitTypeTables();

	const UNoesisSettings* Settings = GetDefault<UNoesisSettings>();
	Settings->SetLicense();
	Settings->SetApplicationResources();
	Settings->SetFontFallbacks();
	Settings->SetFontDefaultProperties();

	// This check is not done inside SetLicense because that is also invoked when user is typing the license and would spam the console
	if (Settings->LicenseName == "" || Settings->LicenseKey == "")
	{
		UE_LOG(LogNoesis, Warning, TEXT("License not set. Get one at https://www.noesisengine.com/trial"));
	}

#if WITH_EDITOR
	if (GEditor)
	{
		GEditor->OnBlueprintPreCompile().AddStatic(OnBlueprintPreCompile);
		FEnumEditorUtils::FEnumEditorManager::Get().AddListener(new NotifyEnumChanged);
		FStructureEditorUtils::FStructEditorManager::Get().AddListener(new NotifyStructChanged);

		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
		AssetRegistry.OnAssetRenamed().AddStatic(&OnAssetRenamed);
	}

	// https://answers.unrealengine.com/questions/526745/413-plugin-custom-kismet-bp-node-standalone-game-c.html
	// Workaround: Standalone mode doesn't load the editor modules, so blueprints that use the set and notify don't work correctly.
	FModuleManager::Get().LoadModule("NoesisEditor");
#endif
}

void ShowTextBoxVirtualKeyboard(Noesis::TextBox*);
void ShowPasswordBoxVirtualKeyboard(Noesis::PasswordBox*);

static Noesis::Ptr<Noesis::TextBox> LastSelectedTextBox;
static Noesis::Ptr<Noesis::PasswordBox> LastSelectedPasswordBox;

void OnTouchUpShowTextBoxVirtualKeyboard(Noesis::BaseComponent*, const Noesis::TouchEventArgs&)
{
	if (LastSelectedTextBox)
	{
		ShowTextBoxVirtualKeyboard(LastSelectedTextBox);
	}
}

void OnTouchUpShowPasswordBoxVirtualKeyboard(Noesis::BaseComponent*, const Noesis::TouchEventArgs&)
{
	if (LastSelectedPasswordBox)
	{
		ShowPasswordBoxVirtualKeyboard(LastSelectedPasswordBox);
	}
}

class NoesisTextBoxVirtualKeyboardEntry : public IVirtualKeyboardEntry
{
public:
	NoesisTextBoxVirtualKeyboardEntry(Noesis::TextBox* InTextBox)
		: TextBox(InTextBox)
	{
		TextBox->SelectAll();
		InitialText = FText::FromString(NsStringToFString(TextBox->GetSelectedText()));
		IsMultiline = TextBox->GetMaxLines() > 1;
		BeginIndex = TextBox->GetSelectionStart();
	}

	virtual void SetTextFromVirtualKeyboard(const FText& InNewText, ETextEntryType TextEntryType) override
	{
		if (TextEntryType == ETextEntryType::TextEntryCanceled || TextEntryType == ETextEntryType::TextEntryAccepted)
		{
			FString CurrentText = InitialText.ToString();
			int32 Length = CurrentText.Len();
			FString NewString = InNewText.ToString();
			FString NewText = CurrentText.Left(BeginIndex) + NewString + CurrentText.RightChop(BeginIndex + Length);
			TextBox->SetText(TCHARToNsString(*NewText).Str());
			int32 NewLength = NewString.Len();
			TextBox->SetSelectionStart(BeginIndex);
			TextBox->SetSelectionLength(NewLength);
		}
		else if (TextEntryType == ETextEntryType::TextEntryUpdated)
		{
			FString CurrentText = InitialText.ToString();
			int32 Length = CurrentText.Len();
			FString NewString = InNewText.ToString();
			FString NewText = CurrentText.Left(BeginIndex) + NewString + CurrentText.RightChop(BeginIndex + Length);
			TextBox->SetText(TCHARToNsString(*NewText).Str());
			int32 NewLength = NewString.Len();
			TextBox->SetSelectionStart(BeginIndex);
			TextBox->SetSelectionLength(NewLength);
		}

		if (LastSelectedTextBox != TextBox)
		{
			LastSelectedTextBox.Reset(TextBox);
			LastSelectedTextBox->TouchUp() += OnTouchUpShowTextBoxVirtualKeyboard;
		}
	}

	virtual void SetSelectionFromVirtualKeyboard(int InSelStart, int SelEnd) override
	{
		TextBox->SetSelectionStart(InSelStart);
		TextBox->SetSelectionLength(SelEnd - InSelStart);
	}

	virtual FText GetText() const override
	{
		return InitialText;
	}

	virtual FText GetHintText() const override
	{
		return FText();
	}

	virtual EKeyboardType GetVirtualKeyboardType() const override
	{
		Noesis::InputScope InputScope = TextBox->GetInputScope();
		switch (InputScope)
		{
		case Noesis::InputScope_Number:
		case Noesis::InputScope_DateMonth:
		case Noesis::InputScope_DateDay:
		case Noesis::InputScope_DateYear:
		case Noesis::InputScope_Digits:
		case Noesis::InputScope_TelephoneNumber:
		case Noesis::InputScope_TelephoneCountryCode:
		case Noesis::InputScope_TelephoneAreaCode:
		case Noesis::InputScope_TelephoneLocalNumber:
		case Noesis::InputScope_TimeHour:
		case Noesis::InputScope_TimeMinorSec:
			return Keyboard_Number;
		case Noesis::InputScope_Url:
		case Noesis::InputScope_EmailSmtpAddress:
			return Keyboard_Web;
		case Noesis::InputScope_EmailUserName:
			return Keyboard_Email;
		case Noesis::InputScope_Password:
			return Keyboard_Password;
		case Noesis::InputScope_AlphanumericHalfWidth:
		case Noesis::InputScope_AlphanumericFullWidth:
			return Keyboard_AlphaNumeric;
		default:
			return Keyboard_Default;
		}
	}

	virtual FVirtualKeyboardOptions GetVirtualKeyboardOptions() const
	{
		return FVirtualKeyboardOptions();
	}

	virtual bool IsMultilineEntry() const override
	{
		return IsMultiline;
	}

	bool GetSelection(int& OutSelStart, int& OutSelEnd) override
	{
		OutSelStart = TextBox->GetSelectionStart();
		OutSelEnd = OutSelStart + TextBox->GetSelectionLength();
		return true;
	}

private:
	Noesis::TextBox* TextBox;
	FText InitialText;
	int32 BeginIndex;
	bool IsMultiline;
};

class NoesisPasswordBoxVirtualKeyboardEntry : public IVirtualKeyboardEntry
{
public:
	NoesisPasswordBoxVirtualKeyboardEntry(Noesis::PasswordBox* InPasswordBox)
		: PasswordBox(InPasswordBox)
	{
		InitialText = FText::FromString(NsStringToFString(PasswordBox->GetPassword()));
	}

	virtual void SetTextFromVirtualKeyboard(const FText& InNewText, ETextEntryType TextEntryType) override
	{
		FString NewString = InNewText.ToString();
		PasswordBox->SetPassword(TCHARToNsString(*NewString).Str());

		if (LastSelectedPasswordBox != PasswordBox)
		{
			LastSelectedPasswordBox.Reset(PasswordBox);
			LastSelectedPasswordBox->TouchUp() += OnTouchUpShowPasswordBoxVirtualKeyboard;
		}
	}

	virtual void SetSelectionFromVirtualKeyboard(int InSelStart, int SelEnd) override
	{
	}

	virtual FText GetText() const override
	{
		return InitialText;
	}

	virtual FText GetHintText() const override
	{
		return FText();
	}

	virtual EKeyboardType GetVirtualKeyboardType() const override
	{
		return Keyboard_Password;
	}

	virtual FVirtualKeyboardOptions GetVirtualKeyboardOptions() const
	{
		return FVirtualKeyboardOptions();
	}

	virtual bool IsMultilineEntry() const override
	{
		return false;
	}

	bool GetSelection(int& OutSelStart, int& OutSelEnd) override
	{
		
		return false;
	}

private:
	Noesis::PasswordBox* PasswordBox;
	FText InitialText;
};

TSharedPtr<NoesisTextBoxVirtualKeyboardEntry> TextBoxVirtualKeyboardEntry;
TSharedPtr<NoesisPasswordBoxVirtualKeyboardEntry> PasswordBoxVirtualKeyboardEntry;

void ShowTextBoxVirtualKeyboard(Noesis::TextBox* TextBox)
{
	if (LastSelectedTextBox)
	{
		LastSelectedTextBox->TouchUp() -= OnTouchUpShowTextBoxVirtualKeyboard;
		LastSelectedTextBox.Reset();
	}
	TSharedPtr<NoesisTextBoxVirtualKeyboardEntry> NewTextBoxVirtualKeyboardEntry = MakeShared<NoesisTextBoxVirtualKeyboardEntry>(TextBox);
	FSlateApplication::Get().ShowVirtualKeyboard(true, FSlateApplication::Get().GetUserIndexForKeyboard(), NewTextBoxVirtualKeyboardEntry);
	TextBoxVirtualKeyboardEntry = NewTextBoxVirtualKeyboardEntry;
}

void ShowPasswordBoxVirtualKeyboard(Noesis::PasswordBox* PasswordBox)
{
	if (LastSelectedPasswordBox)
	{
		LastSelectedPasswordBox->TouchUp() -= OnTouchUpShowPasswordBoxVirtualKeyboard;
		LastSelectedPasswordBox.Reset();
	}
	TSharedPtr<NoesisPasswordBoxVirtualKeyboardEntry> NewPasswordBoxVirtualKeyboardEntry = MakeShared<NoesisPasswordBoxVirtualKeyboardEntry>(PasswordBox);
	FSlateApplication::Get().ShowVirtualKeyboard(true, FSlateApplication::Get().GetUserIndexForKeyboard(), NewPasswordBoxVirtualKeyboardEntry);
	PasswordBoxVirtualKeyboardEntry = NewPasswordBoxVirtualKeyboardEntry;
}

void NoesisSoftwareKeyboardCallback(void* UserData, Noesis::UIElement* FocusedElement, bool Open)
{
	if (Open)
	{
		if (FocusedElement)
		{
			const Noesis::TypeClass* NewFocusClass = FocusedElement->GetClassType();
			const Noesis::TypeClass* TextBoxClass = Noesis::TextBox::StaticGetClassType(nullptr);
			const Noesis::TypeClass* PasswordBoxClass = Noesis::PasswordBox::StaticGetClassType(nullptr);
			if (FPlatformApplicationMisc::RequiresVirtualKeyboard())
			{
				if (NewFocusClass == TextBoxClass || NewFocusClass->IsDescendantOf(TextBoxClass))
				{
					Noesis::TextBox* TextBox = (Noesis::TextBox*)FocusedElement;

					ShowTextBoxVirtualKeyboard(TextBox);
				}
				else if (NewFocusClass == PasswordBoxClass || NewFocusClass->IsDescendantOf(PasswordBoxClass))
				{
					Noesis::PasswordBox* PasswordBox = (Noesis::PasswordBox*)FocusedElement;

					ShowPasswordBoxVirtualKeyboard(PasswordBox);
				}
			}
		}
	}
	else
	{
		if (FSlateApplication::IsInitialized() && FPlatformApplicationMisc::RequiresVirtualKeyboard())
		{
			FSlateApplication::Get().ShowVirtualKeyboard(false, FSlateApplication::Get().GetUserIndexForKeyboard());
		}
	}
}

void NoesisPlaySoundCallback(void* UserData, const Noesis::Uri& Uri, float Volume)
{
	if (!GIsRunning)
		return;

#if WITH_EDITOR
	if (GIsEditor)
	{
		bool IsInGame = false;
		for (const FWorldContext& Context : GEngine->GetWorldContexts())
		{
			if (Context.WorldType == EWorldType::PIE || Context.WorldType == EWorldType::Game)
			{
				IsInGame = true;
			}
		}

		if (!IsInGame)
			return;
	}
#endif

	Noesis::String Filename;
	Uri.GetPath(Filename);
	FString SoundPath = NsProviderPathToAssetPath(Filename.Str());
	USoundWave* Sound = LoadObject<USoundWave>(nullptr, *(FString(TEXT("/Game/")) + SoundPath), nullptr, LOAD_NoWarn);

	if (!Sound)
		return;

	if (GEngine)
	{
		FAudioDeviceHandle AudioDevice = GEngine->GetActiveAudioDevice();
		if (AudioDevice)
		{
			FActiveSound NewActiveSound;
			NewActiveSound.SetSound(Sound);
			NewActiveSound.bIsUISound = true;
			NewActiveSound.UserIndex = FSlateApplication::Get().GetUserIndexForKeyboard();
			NewActiveSound.Priority = Sound->Priority;
			NewActiveSound.VolumeMultiplier = Volume;

			AudioDevice->AddNewActiveSound(NewActiveSound);
		}
	}
}

static Noesis::Ptr<NoesisApp::MediaPlayer> NoesisCreateMediaPlayerCallback(NoesisApp::MediaElement* Owner, const Noesis::Uri& Uri, void* User)
{
	return *new NoesisMediaPlayer(Owner, Uri, User);
}

class FNoesisRuntimeModule : public INoesisRuntimeModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		NoesisRuntimeModuleInterface = this;

		Noesis::GUI::SetErrorHandler(&NoesisErrorHandler);
#if UE_BUILD_SHIPPING + UE_BUILD_SHIPPING_WITH_EDITOR == 0
		Noesis::GUI::SetLogHandler(&NoesisLogHandler);
#else
		Noesis::GUI::DisableInspector();
#endif
		Noesis::MemoryCallbacks MemoryCallbacks{ NoesisAllocationCallbackUserData, &NoesisAlloc, &NoesisRealloc, &NoesisDealloc, &NoesisAllocSize };
		Noesis::GUI::SetMemoryCallbacks(MemoryCallbacks);
		Noesis::GUI::Init();
		NsRegisterReflectionAppInteractivity();
		NsRegisterReflectionAppMediaElement();
		Noesis::RegisterComponent<LocTextExtension>();
		Noesis::RegisterComponent<LocTableExtension>();

		NoesisXamlProvider = *new FNoesisXamlProvider();
		NoesisTextureProvider = *new FNoesisTextureProvider();
		NoesisFontProvider = *new FNoesisFontProvider();
		Noesis::GUI::SetXamlProvider(NoesisXamlProvider);
		Noesis::GUI::SetTextureProvider(NoesisTextureProvider);
		Noesis::GUI::SetFontProvider(NoesisFontProvider);

		LastSelectedTextBox.Reset();
		LastSelectedPasswordBox.Reset();
		Noesis::GUI::SetSoftwareKeyboardCallback(nullptr, &NoesisSoftwareKeyboardCallback);

		Noesis::GUI::SetPlayAudioCallback(nullptr, &NoesisPlaySoundCallback);
		NoesisApp::MediaElement::SetCreateMediaPlayerCallback(NoesisCreateMediaPlayerCallback, nullptr);

		PostGarbageCollectConditionalBeginDestroyDelegateHandle = FCoreUObjectDelegates::PostGarbageCollectConditionalBeginDestroy.AddStatic(NoesisGarbageCollected);

		PostEngineInitDelegateHandle = FCoreDelegates::OnPostEngineInit.AddStatic(OnPostEngineInit);

		Noesis::Reflection::SetFallbackHandler(&NoesisReflectionRegistryCallback);

		FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("NoesisGUI"))->GetBaseDir(), TEXT("Shaders"));
		AddShaderSourceDirectoryMapping(TEXT("/Plugin/NoesisGUI"), PluginShaderDir);

		CultureChangedHandle = FTextLocalizationManager::Get().OnTextRevisionChangedEvent.AddStatic(&NoesisCultureChanged);
	}

	virtual void ShutdownModule() override
	{
		NoesisRuntimeModuleInterface = nullptr;

		FTextLocalizationManager::Get().OnTextRevisionChangedEvent.Remove(CultureChangedHandle);

		Noesis::Reflection::SetFallbackHandler(nullptr);

		FCoreDelegates::OnPostEngineInit.Remove(PostEngineInitDelegateHandle);

		FCoreUObjectDelegates::PostGarbageCollectConditionalBeginDestroy.Remove(PostGarbageCollectConditionalBeginDestroyDelegateHandle);

		void NoesisDeleteMaps();
		NoesisDeleteMaps();

		FNoesisRenderDevice::Destroy();

		NoesisXamlProvider.Reset();
		NoesisTextureProvider.Reset();
		NoesisFontProvider.Reset();


		Noesis::UnregisterComponent<LocTextExtension>();
		Noesis::UnregisterComponent<LocTableExtension>();
		Noesis::GUI::Shutdown();
	}
	// End of IModuleInterface interface

	// INoesisRuntimeModuleInterface interface
	virtual void RegisterFont(const class UFontFace* FontFace) override
	{
		NoesisFontProvider->RegisterFont(FontFace);
	}

	virtual void OnXamlChanged(class UNoesisXaml* Xaml) override
	{
		NoesisXamlProvider->OnXamlChanged(Xaml);
	}

	virtual void OnTextureChanged(class UTexture2D* Texture) override
	{
		NoesisTextureProvider->OnTextureChanged(Texture);
	}
	// End of INoesisRuntimeModuleInterface interface

	static INoesisRuntimeModuleInterface* NoesisRuntimeModuleInterface;
	Noesis::Ptr<FNoesisXamlProvider> NoesisXamlProvider;
	Noesis::Ptr<FNoesisTextureProvider> NoesisTextureProvider;
	Noesis::Ptr<FNoesisFontProvider> NoesisFontProvider;
	FDelegateHandle PostGarbageCollectConditionalBeginDestroyDelegateHandle;
	FDelegateHandle PostEngineInitDelegateHandle;
	FDelegateHandle CultureChangedHandle;
};

INoesisRuntimeModuleInterface* FNoesisRuntimeModule::NoesisRuntimeModuleInterface = 0;

INoesisRuntimeModuleInterface& INoesisRuntimeModuleInterface::Get()
{
	return *FNoesisRuntimeModule::NoesisRuntimeModuleInterface;
}

IMPLEMENT_MODULE(FNoesisRuntimeModule, NoesisRuntime);
DEFINE_LOG_CATEGORY(LogNoesis);
