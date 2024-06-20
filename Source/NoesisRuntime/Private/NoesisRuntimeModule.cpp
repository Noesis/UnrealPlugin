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
#include "Misc/EngineVersionComparison.h"

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
#include "Engine/Texture2D.h"

// Projects includes
#include "Interfaces/IPluginManager.h"

// NoesisRuntime includes
#include "NoesisResourceProvider.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisTypeClass.h"
#include "NoesisSettings.h"
#include "NoesisSupport.h"
#include "NoesisMediaPlayer.h"
#include "Extensions/BackgroundImage.h"
#include "Extensions/EnhancedInputActionTrigger.h"
#include "Extensions/LocTableExtension.h"
#include "Extensions/LocTextExtension.h"
#include "Extensions/RichText.h"
#include "Extensions/InputActionTrigger.h"
#include "Extensions/WorldTransformConverter.h"

// Noesis includes
#include "NoesisSDK.h"
#include "NsApp/MediaElement.h"

#if WITH_EDITOR
// AssetRegistry includes
#include "AssetRegistry/AssetRegistryModule.h"

// UnrealEd includes
#include "Editor.h"
#include "Kismet2/EnumEditorUtils.h"
#include "Kismet2/StructureEditorUtils.h"

// LangServer includes
#include "NsApp/LangServer.h"
#include "NoesisLangServerRenderer.h"
#endif

extern "C" void NsRegisterReflectionAppInteractivity();
extern "C" void NsRegisterReflectionAppMediaElement();
extern "C" void NsRegisterReflectionAppRiveBase();
extern "C" void NsRegisterReflectionAppRive();

extern "C" void NsInitPackageAppInteractivity();
extern "C" void NsInitPackageAppMediaElement();
extern "C" void NsInitPackageAppRiveBase();
extern "C" void NsInitPackageAppRive();

extern "C" void NsShutdownPackageAppInteractivity();
extern "C" void NsShutdownPackageAppMediaElement();
extern "C" void NsShutdownPackageAppRiveBase();
extern "C" void NsShutdownPackageAppRive();

void NoesisInitTypeTables();
void NoesisGarbageCollected();
void NoesisCultureChanged();
void NoesisReflectionRegistryCallback(Noesis::Symbol TypeId);


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

#if WITH_EDITOR
static void SetLangServerRenderCallback()
{
	NoesisApp::LangServer::SetRenderCallback(0, [](void*, Noesis::UIElement* content, int renderWidth, int renderHeight, double renderTime, const char* savePath)
	{
		Noesis::NoesisLangServerRenderer::Capture(content, renderWidth, renderHeight, renderTime, savePath);
	});
}
#endif

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
#if UE_VERSION_OLDER_THAN(5, 0, 0)
		LowLevelFatalErrorHandler(Filename, Line, TEXT("%s"), *NsStringToFString(Desc));
#elif UE_VERSION_OLDER_THAN(5, 4, 0)
		LowLevelFatalErrorHandler(Filename, (int32)Line, PLATFORM_RETURN_ADDRESS(), TEXT("%s"), *NsStringToFString(Desc));
#else
		LowLevelFatalErrorHandler(Filename, (int32)Line, TEXT("%s"), *NsStringToFString(Desc));
#endif
	}

	NS_LOG("%s", Desc);
}

DECLARE_MEMORY_STAT(TEXT("CPU Memory"), STAT_NoesisMemory, STATGROUP_Noesis);
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

void OnObjectPropertyChanged(UObject* Object, struct FPropertyChangedEvent& Event)
{
	if (!IsValid(Object)) // Don't think this is possible, but better safe than sorry
		return;

	static uint32 ReentryGuard = 0;
	if (!ReentryGuard)
	{
		ReentryGuard = 1;
		if (Object->IsA<UTexture2D>())
		{
			UTexture2D* Texture = (UTexture2D*)Object;
			Noesis::Ptr<Noesis::TextureSource> TextureSource = Noesis::StaticPtrCast<Noesis::TextureSource>(NoesisFindComponentForUObject(Texture));
			if (TextureSource != nullptr)
			{
				TextureSource->SetTexture(NoesisCreateTexture(Texture));
			}
			INoesisRuntimeModuleInterface::Get().OnTextureChanged(Texture);
		}

		ReentryGuard = 0;
	}
}

#endif

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
bool GNoesisIsEnteringText = false;

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

	FString SoundPath = NsProviderUriToAssetPath(Uri);
	USoundWave* Sound = LoadObject<USoundWave>(nullptr, *SoundPath, nullptr, LOAD_NoWarn);

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

		Noesis::MemoryCallbacks MemoryCallbacks { 0, &NoesisAlloc, &NoesisRealloc, &NoesisDealloc, &NoesisAllocSize };
		Noesis::GUI::SetMemoryCallbacks(MemoryCallbacks);

		Noesis::GUI::SetErrorHandler(&NoesisErrorHandler);
#if UE_BUILD_SHIPPING + UE_BUILD_SHIPPING_WITH_EDITOR == 0
		Noesis::GUI::SetLogHandler(&NoesisLogHandler);
#else
		Noesis::GUI::DisableHotReload();
		Noesis::GUI::DisableInspector();
#endif
		Noesis::GUI::DisableSocketInit();

		Noesis::GUI::Init();

#if WITH_EDITOR
		SetLangServerRenderCallback();
#endif

		NsRegisterReflectionAppInteractivity();
		NsRegisterReflectionAppMediaElement();
		NsRegisterReflectionAppRiveBase();
		NsRegisterReflectionAppRive();

		NsInitPackageAppInteractivity();
		NsInitPackageAppMediaElement();
		NsInitPackageAppRiveBase();
		NsInitPackageAppRive();

		Noesis::RegisterComponent<LocTextExtension>();
		Noesis::RegisterComponent<LocTableExtension>();
		Noesis::RegisterComponent<InputActionTrigger>();
		Noesis::RegisterComponent<WorldTransformConverter>();
		Noesis::RegisterComponent<BackgroundImage>();
		Noesis::RegisterComponent<Noesis::EnumConverter<InputActionType>>();
#if WITH_ENHANCED_INPUT
		Noesis::RegisterComponent<EnhancedInputActionTrigger>();
		Noesis::RegisterComponent<Noesis::EnumConverter<TriggerEvent>>();
#endif
		Noesis::TypeOf<RichText>();

		NoesisXamlProvider = *new FNoesisXamlProvider();
		NoesisTextureProvider = *new FNoesisTextureProvider();
		NoesisFontProvider = *new FNoesisFontProvider();
		Noesis::GUI::SetXamlProvider(NoesisXamlProvider);
		Noesis::GUI::SetTextureProvider(NoesisTextureProvider);
		Noesis::GUI::SetFontProvider(NoesisFontProvider);

		LastSelectedTextBox.Reset();
		LastSelectedPasswordBox.Reset();
		Noesis::GUI::SetSoftwareKeyboardCallback(this, &FNoesisRuntimeModule::NoesisSoftwareKeyboardCallback);

		Noesis::GUI::SetPlayAudioCallback(nullptr, &NoesisPlaySoundCallback);
		NoesisApp::MediaElement::SetCreateMediaPlayerCallback(NoesisCreateMediaPlayerCallback, nullptr);

		PostGarbageCollectConditionalBeginDestroyDelegateHandle = FCoreUObjectDelegates::PostGarbageCollectConditionalBeginDestroy.AddStatic(NoesisGarbageCollected);

		PostEngineInitDelegateHandle = FCoreDelegates::OnPostEngineInit.AddRaw(this, &FNoesisRuntimeModule::OnPostEngineInit);
		EnginePreExitDelegateHandle = FCoreDelegates::OnEnginePreExit.AddRaw(this, &FNoesisRuntimeModule::OnEnginePreExit);

		Noesis::Reflection::SetFallbackHandler(&NoesisReflectionRegistryCallback);

		FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("NoesisGUI"))->GetBaseDir(), TEXT("Shaders"));
		AddShaderSourceDirectoryMapping(TEXT("/Plugin/NoesisGUI"), PluginShaderDir);

		CultureChangedHandle = FTextLocalizationManager::Get().OnTextRevisionChangedEvent.AddStatic(&NoesisCultureChanged);

		OverlayRenderDelegateHandle = NoesisRegisterOverlayRender();
	}

	static void NoesisSoftwareKeyboardCallback(void* UserData, Noesis::UIElement* FocusedElement, bool Open)
	{
		GNoesisIsEnteringText = Open && !FPlatformApplicationMisc::RequiresVirtualKeyboard();
		FNoesisRuntimeModule* ThisModule = (FNoesisRuntimeModule*)UserData;

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

			ThisModule->KeyboardRequested.Broadcast();
		}
		else
		{
			if (FSlateApplication::IsInitialized() && FPlatformApplicationMisc::RequiresVirtualKeyboard())
			{
				FSlateApplication::Get().ShowVirtualKeyboard(false, FSlateApplication::Get().GetUserIndexForKeyboard());
			}

			ThisModule->KeyboardDismissed.Broadcast();
		}
	}

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
			UE_LOG(LogNoesis, Warning, TEXT("No license detected. Noesis views will stop rendering after 10 minutes"));
			UE_LOG(LogNoesis, Warning, TEXT("More info at https://noesisengine.com/trial"));
		}

#if WITH_EDITOR
		if (GEditor)
		{
			BlueprintPreCompileHandle = GEditor->OnBlueprintPreCompile().AddStatic(OnBlueprintPreCompile);

			NotifyEnumChangedListener = new NotifyEnumChanged;
			FEnumEditorUtils::FEnumEditorManager::Get().AddListener(NotifyEnumChangedListener);
			NotifyStructChangedListener = new NotifyStructChanged;
			FStructureEditorUtils::FStructEditorManager::Get().AddListener(NotifyStructChangedListener);

			FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
			IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
			AssetRenamedHandle = AssetRegistry.OnAssetRenamed().AddStatic(&OnAssetRenamed);
		}

		ObjectPropertyChangedHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.AddStatic(&OnObjectPropertyChanged);
#endif

		InputPreProcessor = NoesisRegisterInputPreProcessor();

		ViewExtension = NoesisRegisterSceneViewExtension();

		// The D3D11 viewport complains if there are extra references to its back buffer.
		if (FSlateApplication::IsInitialized())
		{
			FSlateRenderer* SlateRenderer = FSlateApplication::Get().GetRenderer();
			SlateRenderer->OnPreResizeWindowBackBuffer().AddLambda([](void*)
			{
				BackgroundImage::SetBackgroundImageTexture(nullptr);
			});
		}

		// Avoid creating the DynamicTextureSource in BackgroundImage with a 0x0 size.
		FViewport::ViewportResizedEvent.AddLambda([](FViewport* Viewport, uint32)
		{
			if (Viewport != nullptr)
			{
				const FIntPoint ViewportSize = Viewport->GetSizeXY();
				BackgroundImage::SetBackgroundImageSize(ViewportSize);
			}
		});
	}

	void OnEnginePreExit()
	{
#if WITH_EDITOR
		if (GEditor)
		{
			FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(ObjectPropertyChangedHandle);

			FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
			IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
			AssetRegistry.OnAssetRenamed().Remove(AssetRenamedHandle);

			FEnumEditorUtils::FEnumEditorManager::Get().RemoveListener(NotifyEnumChangedListener);
			delete NotifyEnumChangedListener;
			FStructureEditorUtils::FStructEditorManager::Get().RemoveListener(NotifyStructChangedListener);
			delete NotifyStructChangedListener;

			GEditor->OnBlueprintPreCompile().Remove(BlueprintPreCompileHandle);
		}
#endif

		NoesisUnregisterInputPreProcessor(InputPreProcessor);
		InputPreProcessor.Reset();

		NoesisUnregisterSceneViewExtension(ViewExtension);
		ViewExtension.Reset();
	}

	virtual void ShutdownModule() override
	{
		NoesisRuntimeModuleInterface = nullptr;

		Noesis::GUI::SetApplicationResources(nullptr);

		BackgroundImage::SetBackgroundImageTexture(nullptr);

		NoesisUnregisterOverlayRender(OverlayRenderDelegateHandle);

		FTextLocalizationManager::Get().OnTextRevisionChangedEvent.Remove(CultureChangedHandle);

		Noesis::Reflection::SetFallbackHandler(nullptr);

		FCoreDelegates::OnEnginePreExit.Remove(EnginePreExitDelegateHandle);
		FCoreDelegates::OnPostEngineInit.Remove(PostEngineInitDelegateHandle);

		FCoreUObjectDelegates::PostGarbageCollectConditionalBeginDestroy.Remove(PostGarbageCollectConditionalBeginDestroyDelegateHandle);

		void NoesisDeleteMaps();
		NoesisDeleteMaps();

		FNoesisRenderDevice::Destroy();

		NoesisXamlProvider.Reset();
		NoesisTextureProvider.Reset();
		NoesisFontProvider.Reset();

		NsShutdownPackageAppInteractivity();
		NsShutdownPackageAppMediaElement();
		NsShutdownPackageAppRiveBase();
		NsShutdownPackageAppRive();

#if WITH_ENHANCED_INPUT
		Noesis::UnregisterComponent<Noesis::EnumConverter<TriggerEvent>>();
		Noesis::UnregisterComponent<EnhancedInputActionTrigger>();
#endif
		Noesis::UnregisterComponent<Noesis::EnumConverter<InputActionType>>();
		Noesis::UnregisterComponent<BackgroundImage>();
		Noesis::UnregisterComponent<WorldTransformConverter>();
		Noesis::UnregisterComponent<InputActionTrigger>();
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

	virtual FNoesisKeyboardRequest& OnKeyboardRequested() override
	{
		return KeyboardRequested;
	}

	virtual FNoesisKeyboardRequest& OnKeyboardDismissed() override
	{
		return KeyboardDismissed;
	}
	// End of INoesisRuntimeModuleInterface interface

	static INoesisRuntimeModuleInterface* NoesisRuntimeModuleInterface;
	Noesis::Ptr<FNoesisXamlProvider> NoesisXamlProvider;
	Noesis::Ptr<FNoesisTextureProvider> NoesisTextureProvider;
	Noesis::Ptr<FNoesisFontProvider> NoesisFontProvider;
	FDelegateHandle PostGarbageCollectConditionalBeginDestroyDelegateHandle;
	FDelegateHandle PostEngineInitDelegateHandle;
	FDelegateHandle EnginePreExitDelegateHandle;
	FDelegateHandle CultureChangedHandle;
	FDelegateHandle OverlayRenderDelegateHandle;
#if WITH_EDITOR
	FDelegateHandle BlueprintPreCompileHandle;
	NotifyEnumChanged* NotifyEnumChangedListener;
	NotifyStructChanged* NotifyStructChangedListener;
	FDelegateHandle AssetRenamedHandle;
	FDelegateHandle ObjectPropertyChangedHandle;
#endif
	TSharedPtr<class IInputProcessor> InputPreProcessor;
	TSharedPtr<class ISceneViewExtension> ViewExtension;
	FNoesisKeyboardRequest KeyboardRequested;
	FNoesisKeyboardRequest KeyboardDismissed;
};

INoesisRuntimeModuleInterface* FNoesisRuntimeModule::NoesisRuntimeModuleInterface = 0;

INoesisRuntimeModuleInterface& INoesisRuntimeModuleInterface::Get()
{
	return *FNoesisRuntimeModule::NoesisRuntimeModuleInterface;
}

IMPLEMENT_MODULE(FNoesisRuntimeModule, NoesisRuntime);
DEFINE_LOG_CATEGORY(LogNoesis);
