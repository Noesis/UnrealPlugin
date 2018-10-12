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

static void NoesisErrorHandler(const char* Filename, uint32 Line, const char* Desc, bool Fatal)
{
	if (Fatal)
	{
		UE_LOG(LogNoesis, Error, TEXT("%s"), *NsStringToFString(Desc));
		FPlatformMisc::RequestExit(true);
	}
	UE_LOG(LogNoesis, Warning, TEXT("%s"), *NsStringToFString(Desc));
}

DECLARE_DWORD_COUNTER_STAT(TEXT("NoesisMemory"), STAT_NoesisMemory, STATGROUP_Noesis);
class NoesisMemoryAllocator : public Noesis::MemoryAllocator
{
public:

	virtual void* Alloc(SIZE_T Size) override
	{
		void* Result = FMemory::Malloc(Size);
		INC_DWORD_STAT_BY(STAT_NoesisMemory, FMemory::GetAllocSize(Result));
		return Result;
	}

	virtual void* Realloc(void* Ptr, SIZE_T Size) override
	{
		return FMemory::Realloc(Ptr, Size);
	}

	virtual void Dealloc(void* Ptr)
	{
		DEC_DWORD_STAT_BY(STAT_NoesisMemory, FMemory::GetAllocSize(Ptr));
		FMemory::Free(Ptr);
	}
};

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
}

void OnAssetRenamed(const FAssetData&, const FString&)
{
	NoesisDestroyAllTypes();
}
#endif

void OnPostEngineInit()
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

	NoesisRegisterTypes();
}

void ShowTextBoxVirtualKeyboard(Noesis::TextBox*);
void ShowPasswordBoxVirtualKeyboard(Noesis::PasswordBox*);

static Noesis::Ptr<Noesis::TextBox> LastSelectedTextBox;
static Noesis::Ptr<Noesis::PasswordBox> LastSelectedPasswordBox;

void OnTouchUpShowTextBoxVirtualKeyboard(Noesis::BaseComponent*, const Noesis::TouchEventArgs&)
{
	if (LastSelectedTextBox)
	{
		ShowTextBoxVirtualKeyboard(LastSelectedTextBox.GetPtr());
	}
}

void OnTouchUpShowPasswordBoxVirtualKeyboard(Noesis::BaseComponent*, const Noesis::TouchEventArgs&)
{
	if (LastSelectedPasswordBox)
	{
		ShowPasswordBoxVirtualKeyboard(LastSelectedPasswordBox.GetPtr());
	}
}

class NoesisTextBoxVirtualKeyboardEntry : public IVirtualKeyboardEntry
{
public:
	NoesisTextBoxVirtualKeyboardEntry(Noesis::TextBox* InTextBox)
		: TextBox(InTextBox)
	{
		TextBox->SelectAll();
		InitialText = NsStringToFString(TextBox->GetSelectedText());
		IsMultiline = TextBox->GetMaxLines() > 1;
		BeginIndex = TextBox->GetSelectionStart();
	}

	virtual void SetTextFromVirtualKeyboard(const FText& InNewText, ETextEntryType TextEntryType) override
	{
		if (TextEntryType == ETextEntryType::TextEntryCanceled || TextEntryType == ETextEntryType::TextEntryAccepted)
		{
			int32 Length = InitialText.Len();
			FString CurrentText = InitialText;
			FString NewString = InNewText.ToString();
			FString NewText = CurrentText.Left(BeginIndex) + NewString + CurrentText.RightChop(BeginIndex + Length);
			TextBox->SetText(TCHARToNsString(*NewText).c_str());
			int32 NewLength = NewString.Len();
			TextBox->SetSelectionStart(BeginIndex);
			TextBox->SetSelectionLength(NewLength);
		}
		else if (TextEntryType == ETextEntryType::TextEntryUpdated)
		{
			int32 Length = InitialText.Len();
			FString CurrentText = InitialText;
			FString NewString = InNewText.ToString();
			FString NewText = CurrentText.Left(BeginIndex) + NewString + CurrentText.RightChop(BeginIndex + Length);
			TextBox->SetText(TCHARToNsString(*NewText).c_str());
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

	virtual FText GetText() const override
	{
		return FText::FromString(InitialText);
	}

	virtual FText GetHintText() const override
	{
		return FText();
	}

	virtual EKeyboardType GetVirtualKeyboardType() const override
	{
		return Keyboard_Default;
	}

	virtual FVirtualKeyboardOptions GetVirtualKeyboardOptions() const
	{
		return FVirtualKeyboardOptions();
	}

	virtual bool IsMultilineEntry() const override
	{
		return IsMultiline;
	}

private:
	Noesis::TextBox* TextBox;
	FString InitialText;
	int32 BeginIndex;
	bool IsMultiline;
};

class NoesisPasswordBoxVirtualKeyboardEntry : public IVirtualKeyboardEntry
{
public:
	NoesisPasswordBoxVirtualKeyboardEntry(Noesis::PasswordBox* InPasswordBox)
		: PasswordBox(InPasswordBox)
	{
		InitialText = NsStringToFString(PasswordBox->GetPassword());
	}

	virtual void SetTextFromVirtualKeyboard(const FText& InNewText, ETextEntryType TextEntryType) override
	{
		FString NewString = InNewText.ToString();
		PasswordBox->SetPassword(TCHARToNsString(*NewString).c_str());

		if (LastSelectedPasswordBox != PasswordBox)
		{
			LastSelectedPasswordBox.Reset(PasswordBox);
			LastSelectedPasswordBox->TouchUp() += OnTouchUpShowPasswordBoxVirtualKeyboard;
		}
	}

	virtual FText GetText() const override
	{
		return FText::FromString(InitialText);
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

private:
	Noesis::PasswordBox* PasswordBox;
	FString InitialText;
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

	return false;
}

void NoesisHideSoftwareKeyboard(void* UserData)
{
	if (FSlateApplication::IsInitialized() && FPlatformApplicationMisc::RequiresVirtualKeyboard())
	{
		FSlateApplication::Get().ShowVirtualKeyboard(false, FSlateApplication::Get().GetUserIndexForKeyboard());
	}
}

class FNoesisRuntimeModule : public INoesisRuntimeModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		Noesis::GUI::Init(&NoesisErrorHandler, &NoesisLogHandler, &Allocator);

		NoesisResourceProvider = new FNoesisResourceProvider();
		Noesis::GUI::SetXamlProvider(NoesisResourceProvider);
		Noesis::GUI::SetTextureProvider(NoesisResourceProvider);
		Noesis::GUI::SetFontProvider(NoesisResourceProvider);

		LastSelectedTextBox.Reset();
		LastSelectedPasswordBox.Reset();
		Noesis::GUI::SetSoftwareKeyboardCallbacks(nullptr, &NoesisShowSoftwareKeyboard, &NoesisHideSoftwareKeyboard);

		NoesisRuntimeModuleInterface = this;

		PostGarbageCollectConditionalBeginDestroyDelegateHandle = FCoreUObjectDelegates::PostGarbageCollectConditionalBeginDestroy.AddStatic(NoesisGarbageCollected);

		PostEngineInitDelegateHandle = FCoreDelegates::OnPostEngineInit.AddStatic(OnPostEngineInit);

		NsGetKernel()->GetReflectionRegistry()->SetFallbackHandler(&NoesisReflectionRegistryCallback);
	}

	virtual void ShutdownModule() override
	{
		NsGetKernel()->GetReflectionRegistry()->SetFallbackHandler(nullptr);

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
	}
	// End of IModuleInterface interface

	// INoesisRuntimeModuleInterface interface
	// End of INoesisRuntimeModuleInterface interface

	static INoesisRuntimeModuleInterface* NoesisRuntimeModuleInterface;
	FNoesisResourceProvider* NoesisResourceProvider;
	FDelegateHandle PostGarbageCollectConditionalBeginDestroyDelegateHandle;
	FDelegateHandle PostEngineInitDelegateHandle;
	NoesisMemoryAllocator Allocator;
};

INoesisRuntimeModuleInterface* FNoesisRuntimeModule::NoesisRuntimeModuleInterface = 0;

INoesisRuntimeModuleInterface& INoesisRuntimeModuleInterface::Get()
{
	return *FNoesisRuntimeModule::NoesisRuntimeModuleInterface;
}

IMPLEMENT_MODULE(FNoesisRuntimeModule, NoesisRuntime);
DEFINE_LOG_CATEGORY(LogNoesis);
