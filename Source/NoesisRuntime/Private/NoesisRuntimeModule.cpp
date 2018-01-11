////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRuntimeModule.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/CoreDelegates.h"
#include "Modules/ModuleManager.h"

// ApplicationCore includes
#include "HAL/PlatformApplicationMisc.h"

// Slate includes
#include "Widgets/Input/IVirtualKeyboardEntry.h"
#include "Framework/Application/SlateApplication.h"

// NoesisRuntime includes
#include "NoesisResourceProvider.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisTypeClass.h"
#include "NoesisSettings.h"
#include "NoesisSupport.h"

// Noesis includes
#include "NoesisSDK.h"

#if PLATFORM_WINDOWS
#include "AllowWindowsPlatformTypes.h"
#include <DelayImp.h>
#include "HideWindowsPlatformTypes.h"
#endif

static void NoesisErrorHandler(const char* Filename, uint32 Line, const char* Desc, bool Fatal)
{
	if (Fatal)
	{
		UE_LOG(LogNoesis, Error, TEXT("%s"), *NsStringToFString(Desc));
		FPlatformMisc::RequestExit(true);
	}
	UE_LOG(LogNoesis, Warning, TEXT("%s"), *NsStringToFString(Desc));
}

static void NoesisLogHandler(const char* File, uint32_t Line, uint32_t Level, const char* Channel, const char* Message)
{
	if (UObjectInitialized())
	{
		ENoesisLoggingSettings LogVerbosity = GetDefault<UNoesisSettings>()->LogVerbosity;
		if (LogVerbosity == ENoesisLoggingSettings::Bindings || (LogVerbosity == ENoesisLoggingSettings::Normal && FCStringAnsi::Strcmp(Channel, "Bindings") != 0))
		{
			switch (Level)
			{
			case 0:
				UE_LOG(LogNoesis, VeryVerbose, TEXT("%s"), *NsStringToFString(Message));
				break;
			case 1:
				UE_LOG(LogNoesis, Verbose, TEXT("%s"), *NsStringToFString(Message));
				break;
			case 2:
				UE_LOG(LogNoesis, Log, TEXT("%s"), *NsStringToFString(Message));
				break;
			case 3:
				UE_LOG(LogNoesis, Warning, TEXT("%s"), *NsStringToFString(Message));
				break;
			case 4:
				UE_LOG(LogNoesis, Error, TEXT("%s"), *NsStringToFString(Message));
				break;
			}
		}
	}
}

#if PLATFORM_WINDOWS
extern "C" FARPROC WINAPI delayLoadHook(uint32 dliNotify, PDelayLoadInfo pdli)
{
	if (dliNotify == dliNotePreLoadLibrary && FCStringAnsi::Stricmp(pdli->szDll, "Noesis.dll") == 0)
	{
		FString BaseDirs[] = { FPaths::EnginePluginsDir(), FPaths::EnterprisePluginsDir(), FPaths::ProjectPluginsDir() };
		for (auto BaseDir : BaseDirs)
		{
			FString NoesisDllPath = BaseDir / TEXT(NOESISGUI_DLL_PATH);
			if (FPaths::DirectoryExists(*FPaths::GetPath(NoesisDllPath)))
			{
				FPlatformProcess::PushDllDirectory(*FPaths::GetPath(NoesisDllPath));
				void* DllHandle = FPlatformProcess::GetDllHandle(*NoesisDllPath);
				FPlatformProcess::PopDllDirectory(*FPaths::GetPath(NoesisDllPath));
				if (DllHandle)
				{
					return (FARPROC)DllHandle;
				}
			}
		}
	}

	return NULL;
}

void* DllHandle = FPlatformProcess::GetDllHandle(*(FPaths::EngineDir() / TEXT(NOESISGUI_DLL_PATH)));

const PfnDliHook __pfnDliNotifyHook2 = delayLoadHook;
#endif

#if WITH_EDITOR
class NotifyEnumChanged : public FEnumEditorUtils::INotifyOnEnumChanged
{
public:
	virtual void PreChange(const UUserDefinedEnum* Changed, FEnumEditorUtils::EEnumEditorChangeInfo ChangedType) override
	{

	}
	virtual void PostChange(const UUserDefinedEnum* Changed, FEnumEditorUtils::EEnumEditorChangeInfo ChangedType) override
	{
		NoesisDestroyAllTypes();
	}
};

class NotifyStructChanged : public FStructureEditorUtils::INotifyOnStructChanged
{
public:
	virtual void PreChange(const UUserDefinedStruct* Changed, FStructureEditorUtils::EStructureEditorChangeInfo ChangedType) override
	{

	}
	virtual void PostChange(const UUserDefinedStruct* Changed, FStructureEditorUtils::EStructureEditorChangeInfo ChangedType) override
	{
		NoesisDestroyAllTypes();
	}
};

void OnBlueprintPreCompile(UBlueprint* Blueprint)
{
	NoesisDestroyTypeClassForBlueprint(Blueprint);

	extern COREUOBJECT_API bool GBlueprintUseCompilationManager;
	if (Blueprint->IsA<UNoesisBlueprint>() && GBlueprintUseCompilationManager)
	{
		FPlatformMisc::MessageBoxExt(EAppMsgType::Ok, TEXT("The Blueprint Compilation Manager is enabled. Please disable it to be able to compile NoesisViews."), TEXT("Error"));
	}
}

void OnAssetRenamed(const FAssetData&, const FString&)
{
	NoesisDestroyAllTypes();
}
#endif

void AddOnBlueprintPreCompileDelegate()
{
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

void ShowTextBoxVirtualKeyboard();
void ShowPasswordBoxVirtualKeyboard();

void OnPreviewTouchDownShowTextBoxVirtualKeyboard(Noesis::BaseComponent*, const Noesis::TouchEventArgs&)
{
	ShowTextBoxVirtualKeyboard();
}

void OnPreviewTouchDownShowPasswordBoxVirtualKeyboard(Noesis::BaseComponent*, const Noesis::TouchEventArgs&)
{
	ShowPasswordBoxVirtualKeyboard();
}

class NoesisTextBoxVirtualKeyboardEntry : public IVirtualKeyboardEntry
{
public:
	NoesisTextBoxVirtualKeyboardEntry()
		: TextBox(nullptr)
	{
	}

	void SetTextBox(Noesis::TextBox* InTextBox)
	{
		if (TextBox)
		{
			TextBox->PreviewTouchDown() -= OnPreviewTouchDownShowTextBoxVirtualKeyboard;
		}
		TextBox = InTextBox;
		if (TextBox)
		{
			TextBox->PreviewTouchDown() += OnPreviewTouchDownShowTextBoxVirtualKeyboard;
			InitialText = FText::FromString(NsStringToFString(TextBox->GetText()));
			IsMultiline = TextBox->GetMaxLines() > 1;
		}
		else
		{
			InitialText = FText();
			IsMultiline = false;
		}
	}

	virtual void SetTextFromVirtualKeyboard(const FText& InNewText, ETextEntryType TextEntryType) override
	{
		if (TextBox)
		{
			if (TextEntryType == ETextEntryType::TextEntryCanceled || TextEntryType == ETextEntryType::TextEntryAccepted)
			{
				int32 BeginIndex = TextBox->GetSelectionStart();
				int32 Length = TextBox->GetSelectionLength();
				FString CurrentText = NsStringToFString(TextBox->GetText());
				FString NewString = InNewText.ToString();
				FString NewText = CurrentText.Left(BeginIndex) + NewString + CurrentText.RightChop(BeginIndex + Length);
				TextBox->SetText(TCHARToNsString(*NewText).c_str());
				int32 NewLength = NewString.Len();
				TextBox->SetSelectionStart(BeginIndex + NewLength);
				TextBox->SetSelectionLength(0);
			}
			else if (TextEntryType == ETextEntryType::TextEntryUpdated)
			{
				int32 BeginIndex = TextBox->GetSelectionStart();
				int32 Length = TextBox->GetSelectionLength();
				FString CurrentText = NsStringToFString(TextBox->GetText());
				FString NewString = InNewText.ToString();
				FString NewText = CurrentText.Left(BeginIndex) + NewString + CurrentText.RightChop(BeginIndex + Length);
				TextBox->SetText(TCHARToNsString(*NewText).c_str());
				int32 NewLength = NewString.Len();
				TextBox->SetSelectionLength(NewLength);
			}
		}
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
		return Keyboard_Default;
	}

	virtual bool IsMultilineEntry() const override
	{
		return IsMultiline;
	}

private:
	Noesis::TextBox* TextBox;
	FText InitialText;
	bool IsMultiline;
};

class NoesisPasswordBoxVirtualKeyboardEntry : public IVirtualKeyboardEntry
{
public:
	NoesisPasswordBoxVirtualKeyboardEntry()
		: PasswordBox(nullptr)
	{
	}

	void SetPasswordBox(Noesis::PasswordBox* InPasswordBox)
	{
		if (PasswordBox)
		{
			PasswordBox->PreviewTouchDown() -= OnPreviewTouchDownShowPasswordBoxVirtualKeyboard;
		}
		PasswordBox = InPasswordBox;
		InitialText = FText();
		if (PasswordBox)
		{

			PasswordBox->PreviewTouchDown() += OnPreviewTouchDownShowPasswordBoxVirtualKeyboard;
			InitialText = FText::FromString(NsStringToFString(PasswordBox->GetPassword()));
		}
	}

	virtual void SetTextFromVirtualKeyboard(const FText& InNewText, ETextEntryType TextEntryType) override
	{
		if (PasswordBox)
		{
			FString NewString = InNewText.ToString();
			PasswordBox->SetPassword(TCHARToNsString(*NewString).c_str());
		}
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

	virtual bool IsMultilineEntry() const override
	{
		return false;
	}

private:
	Noesis::PasswordBox* PasswordBox;
	FText InitialText;
};

TSharedPtr<NoesisTextBoxVirtualKeyboardEntry> TextBoxVirtualKeyboardEntry;
TSharedPtr<NoesisPasswordBoxVirtualKeyboardEntry> PasswordBoxVirtualKeyboardEntry;

void ShowTextBoxVirtualKeyboard()
{
	FSlateApplication::Get().ShowVirtualKeyboard(true, FSlateApplication::Get().GetUserIndexForKeyboard(), TextBoxVirtualKeyboardEntry);
}

void ShowPasswordBoxVirtualKeyboard()
{
	FSlateApplication::Get().ShowVirtualKeyboard(true, FSlateApplication::Get().GetUserIndexForKeyboard(), PasswordBoxVirtualKeyboardEntry);
}

bool NoesisShowSoftwareKeyboard(void* UserData, Noesis::UIElement* FocusedElement)
{
	if (FocusedElement)
	{
		const Noesis::TypeClass* NewFocusClass = FocusedElement->GetClassType();
		const Noesis::TypeClass* TextBoxClass = Noesis::TextBox::StaticGetClassType();
		const Noesis::TypeClass* PasswordBoxClass = Noesis::PasswordBox::StaticGetClassType();
		if (FPlatformApplicationMisc::RequiresVirtualKeyboard())
		{
			if (NewFocusClass == TextBoxClass || NewFocusClass->IsDescendantOf(TextBoxClass))
			{
				PasswordBoxVirtualKeyboardEntry->SetPasswordBox(nullptr);
				TextBoxVirtualKeyboardEntry->SetTextBox((Noesis::TextBox*)FocusedElement);

				ShowTextBoxVirtualKeyboard();
			}
			else if (NewFocusClass == PasswordBoxClass || NewFocusClass->IsDescendantOf(PasswordBoxClass))
			{
				TextBoxVirtualKeyboardEntry->SetTextBox(nullptr);	
				PasswordBoxVirtualKeyboardEntry->SetPasswordBox((Noesis::PasswordBox*)FocusedElement);

				ShowPasswordBoxVirtualKeyboard();
			}
		}
	}

	return false;
}

void NoesisHideSoftwareKeyboard(void* UserData)
{
	FSlateApplication::Get().ShowVirtualKeyboard(false, FSlateApplication::Get().GetUserIndexForKeyboard());
}

class FNoesisRuntimeModule : public INoesisRuntimeModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		Noesis::GUI::Init(&NoesisErrorHandler, &NoesisLogHandler);

		NoesisResourceProvider = new FNoesisResourceProvider();
		Noesis::GUI::SetXamlProvider(NoesisResourceProvider);
		Noesis::GUI::SetTextureProvider(NoesisResourceProvider);
		Noesis::GUI::SetFontProvider(NoesisResourceProvider);

		Noesis::GUI::SetSoftwareKeyboardCallbacks(nullptr, &NoesisShowSoftwareKeyboard, &NoesisHideSoftwareKeyboard);

		NoesisRuntimeModuleInterface = this;

		PostGarbageCollectConditionalBeginDestroyDelegateHandle = FCoreUObjectDelegates::PostGarbageCollectConditionalBeginDestroy.AddStatic(NoesisGarbageCollected);

		PostEngineInitDelegateHandle = FCoreDelegates::OnPostEngineInit.AddStatic(AddOnBlueprintPreCompileDelegate);

		TextBoxVirtualKeyboardEntry = MakeShared<NoesisTextBoxVirtualKeyboardEntry>();
		PasswordBoxVirtualKeyboardEntry = MakeShared<NoesisPasswordBoxVirtualKeyboardEntry>();
	}

	virtual void ShutdownModule() override
	{
		FCoreDelegates::OnPostEngineInit.Remove(PostEngineInitDelegateHandle);

		FCoreUObjectDelegates::PostGarbageCollectConditionalBeginDestroy.Remove(PostGarbageCollectConditionalBeginDestroyDelegateHandle);

		void NoesisDeleteMaps();
		NoesisDeleteMaps();

		FNoesisRenderDevice::Destroy();

		Noesis::GUI::SetXamlProvider(nullptr);
		Noesis::GUI::SetTextureProvider(nullptr);
		Noesis::GUI::SetFontProvider(nullptr);
		delete NoesisResourceProvider;
		NoesisResourceProvider = nullptr;

		NoesisRuntimeModuleInterface = 0;
		Noesis::GUI::Shutdown();

		TextBoxVirtualKeyboardEntry.Reset();
		PasswordBoxVirtualKeyboardEntry.Reset();
	}
	// End of IModuleInterface interface

	// INoesisRuntimeModuleInterface interface
	// End of INoesisRuntimeModuleInterface interface

	static INoesisRuntimeModuleInterface* NoesisRuntimeModuleInterface;
	FNoesisResourceProvider* NoesisResourceProvider;
	FDelegateHandle PostGarbageCollectConditionalBeginDestroyDelegateHandle;
	FDelegateHandle PostEngineInitDelegateHandle;
};

INoesisRuntimeModuleInterface* FNoesisRuntimeModule::NoesisRuntimeModuleInterface = 0;

INoesisRuntimeModuleInterface& INoesisRuntimeModuleInterface::Get()
{
	return *FNoesisRuntimeModule::NoesisRuntimeModuleInterface;
}

IMPLEMENT_MODULE(FNoesisRuntimeModule, NoesisRuntime);
DEFINE_LOG_CATEGORY(LogNoesis);
