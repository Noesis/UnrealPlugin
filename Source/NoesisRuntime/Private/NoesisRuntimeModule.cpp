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
#if UE_VERSION_OLDER_THAN(5, 6, 0)
#include "Stats/Stats2.h"
#endif
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
#include "UnrealClient.h"
#include "Engine/Engine.h"

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
#include "Extensions/BoxShadow.h"
#include "Extensions/ChromaticAberrationEffect.h"
#include "Extensions/DirectionalBlurEffect.h"
#include "Extensions/NoiseEffect.h"
#include "Extensions/PinchEffect.h"
#include "Extensions/PixelateEffect.h"
#include "Extensions/SaturationEffect.h"
#include "Extensions/TintEffect.h"
#include "Extensions/VignetteEffect.h"
#include "Extensions/AbyssBrush.h"
#include "Extensions/ConicGradientBrush.h"
#include "Extensions/CrossFadeBrush.h"
#include "Extensions/PlasmaBrush.h"
#include "Extensions/SaturationBrush.h"
#include "Extensions/TintBrush.h"
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
#include "NsGui/LangServer.h"
#include "NoesisLangServerRenderer.h"
#endif

extern "C" void NsRegisterReflectionAppInteractivity();
extern "C" void NsRegisterReflectionAppMediaElement();
extern "C" void NsRegisterReflectionAppRiveBase();
extern "C" void NsRegisterReflectionAppRive();
extern "C" void NsRegisterReflectionAppToolkit();

extern "C" void NsInitPackageAppInteractivity();
extern "C" void NsInitPackageAppMediaElement();
extern "C" void NsInitPackageAppRiveBase();
extern "C" void NsInitPackageAppRive();
extern "C" void NsInitPackageAppToolkit();

extern "C" void NsShutdownPackageAppInteractivity();
extern "C" void NsShutdownPackageAppMediaElement();
extern "C" void NsShutdownPackageAppRiveBase();
extern "C" void NsShutdownPackageAppRive();
extern "C" void NsShutdownPackageAppToolkit();

void NoesisInitTypeTables();
void NoesisGarbageCollected();
void NoesisCultureChanged();
void NoesisReflectionRegistryCallback(Noesis::Symbol TypeId);


#if NO_LOGGING == 0
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
				case 0: UE_LOG(LogNoesisEngine, VeryVerbose, TEXT("%s"), StringCast<TCHAR>((UTF8CHAR*)Message).Get()); break;
				case 1: UE_LOG(LogNoesisEngine, Verbose, TEXT("%s"), StringCast<TCHAR>((UTF8CHAR*)Message).Get()); break;
				case 2: UE_LOG(LogNoesisEngine, Log, TEXT("%s"), StringCast<TCHAR>((UTF8CHAR*)Message).Get()); break;
				case 3: UE_LOG(LogNoesisEngine, Warning, TEXT("%s"), StringCast<TCHAR>((UTF8CHAR*)Message).Get()); break;
				case 4: UE_LOG(LogNoesisEngine, Error, TEXT("%s"), StringCast<TCHAR>((UTF8CHAR*)Message).Get()); break;
			}
		}
	}
}

#if WITH_EDITOR
static void SetLangServerRenderCallback()
{
	Noesis::LangServer::SetRenderCallback(0, [](void*, Noesis::UIElement* content, int renderWidth, int renderHeight, double renderTime, const char* savePath)
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
		LowLevelFatalErrorHandler(Filename, (int32)Line, PLATFORM_RETURN_ADDRESS(), TEXT("%s"), StringCast<TCHAR>((UTF8CHAR*)Desc).Get());
#elif UE_VERSION_OLDER_THAN(5, 7, 0)
		LowLevelFatalErrorHandler(Filename, (int32)Line, TEXT("%s"), StringCast<TCHAR>((UTF8CHAR*)Desc).Get());
#else
		LowLevelFatalError(TEXT("%s"), StringCast<TCHAR>((UTF8CHAR*)Desc).Get());
#endif
	}

	NS_LOG("%s", (UTF8CHAR*)Desc);
}

DECLARE_MEMORY_STAT(TEXT("CPU Memory"), STAT_NoesisMemory, STATGROUP_Noesis);

#define NOESIS_USE_STOMP_ALLOCATOR 0

#if NOESIS_USE_STOMP_ALLOCATOR
#include "HAL/IConsoleManager.h"
#include "HAL/MallocStomp.h"
#if !IS_MONOLITHIC
// What's all this about?
// MallocStomp.OverrunTest is registered in the Core module
// and then the ConsoleCommand object is destroyed by calling Release
// when we include MallocStomp.cpp below and re-register it.
// So what this does is it replaces the vtable of the original
// object with one that implements an empty Release, so that the
// memory is not freed and we don't get a crash at shutdown
// when the object is auto released.
// This needs to be done before MallocStomp.cpp re-registers
// the command, hence the variable NoesisUnregisterStompAllocConsoleObject.
class FNoReleaseConsoleObject : public IConsoleCommand
{
	virtual const TCHAR* GetHelp() const { return TEXT(""); }
	virtual void SetHelp(const TCHAR* Value) {}
	virtual EConsoleVariableFlags GetFlags() const { return EConsoleVariableFlags::ECVF_Unregistered; }
	virtual void SetFlags(const EConsoleVariableFlags Value) {}
	virtual void Release() {}
	virtual struct IConsoleCommand* AsCommand() { return this; }
	virtual bool Execute(const TArray< FString >& Args, UWorld* InWorld, class FOutputDevice& OutputDevice) { return false; }
};
static struct NoesisUnregisterStompAllocConsoleObject
{
	NoesisUnregisterStompAllocConsoleObject()
	{
		auto CVar = IConsoleManager::Get().FindConsoleObject(TEXT("MallocStomp.OverrunTest"));
		new(CVar) FNoReleaseConsoleObject();
	}
} NoesisUnregisterStompAllocConsoleObject;
extern FAutoConsoleCommand MallocStompTestCommand;
#include "HAL/MallocStomp.cpp"
#endif // !IS_MONOLITHIC

void* NoesisAlloc(void* UserData, size_t Size)
{
	auto Allocator = (FMallocStomp*)UserData;
	void* Result = Allocator->Malloc(Size, 8);
	SET_MEMORY_STAT(STAT_NoesisMemory, Noesis::GetAllocatedMemory());
	return Result;
}

void* NoesisRealloc(void* UserData, void* Ptr, size_t Size)
{
	auto Allocator = (FMallocStomp*)UserData;
	void* Result = Allocator->Realloc(Ptr, Size, 8);
	SET_MEMORY_STAT(STAT_NoesisMemory, Noesis::GetAllocatedMemory());
	return Result;
}

void NoesisDealloc(void* UserData, void* Ptr)
{
	auto Allocator = (FMallocStomp*)UserData;
	Allocator->Free(Ptr);

#if STATS
	// Avoid collecting stats if the system has already been shut down.
	if (FThreadStats::WillEverCollectData())
	{
		SET_MEMORY_STAT(STAT_NoesisMemory, Noesis::GetAllocatedMemory());
	}
#endif
}

size_t NoesisAllocSize(void* UserData, void* Ptr)
{
	auto Allocator = (FMallocStomp*)UserData;
	size_t AllocationSize = 0;
	Allocator->GetAllocationSize(Ptr, AllocationSize);
	return AllocationSize;
}

#else

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

#if STATS
	// Avoid collecting stats if the system has already been shut down.
	if (FThreadStats::WillEverCollectData())
	{
		SET_MEMORY_STAT(STAT_NoesisMemory, Noesis::GetAllocatedMemory());
	}
#endif
}

size_t NoesisAllocSize(void* UserData, void* Ptr)
{
	return FMemory::GetAllocSize(Ptr);
}

#endif

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

void OnAssetsAdded(TConstArrayView<FAssetData> Assets)
{
	NoesisRegisterMaterials(Assets);
}

void OnAssetsRemoved(TConstArrayView<FAssetData> Assets)
{
	NoesisUnregisterMaterials(Assets);
}

void OnAssetRenamed(const FAssetData& AssetData, const FString& OldPath)
{
	UObject* NewObject = AssetData.GetAsset();
	NoesisAssetRenamed(NewObject, OldPath);
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
			TextBox->SetText((ANSICHAR*)StringCast<UTF8CHAR>(*NewText).Get());
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
			TextBox->SetText((ANSICHAR*)StringCast<UTF8CHAR>(*NewText).Get());
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
		PasswordBox->SetPassword((ANSICHAR*)StringCast<UTF8CHAR>(*NewString).Get());

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

////////////////////////////////////////////////////////////////////////////////////////////////////
static bool SetHardwareCursor(EMouseCursor::Type CursorShape, const Noesis::Uri& Src, float Scale)
{
	TSharedPtr<ICursor> PlatformCursor = FSlateApplication::Get().GetPlatformCursor();
	if (!PlatformCursor)
	{
		return false;
	}

	struct CURHeader
	{
		uint16_t reserved;
		uint16_t type;
		uint16_t count;
	};

	struct CURDirEntry
	{
		uint8_t width;
		uint8_t height;
		uint8_t colorCount;
		uint8_t reserved;
		uint16_t hotspotX;
		uint16_t hotspotY;
		uint32_t sizeInBytes;
		uint32_t imageOffset;
	};

	struct BMPInfoHeader
	{
		uint32_t headerSize;
		int32_t width;
		int32_t height;
		uint16_t planes;
		uint16_t bitCount;
		uint32_t compression;
		uint32_t imageSize;
		int32_t xPelsPerMeter;
		int32_t yPelsPerMeter;
		uint32_t colorsUsed;
		uint32_t colorsImportant;
	};

	Noesis::Ptr<Noesis::Stream> Stream = Noesis::GUI::LoadXamlResource(Src);

	if (Stream && Stream->GetMemoryBase())
	{
		const uint8_t* Buffer = (const uint8_t*)Stream->GetMemoryBase();
		int CursorSize = Noesis::Round(24 * Scale);

		// Find the closest cursor size entry
		int Distance = INT_MAX;
		CURHeader* CurHeader = (CURHeader*)Buffer;
		CURDirEntry* IconEntry = nullptr;

		CURDirEntry* CurEntry = (CURDirEntry*)(Buffer + sizeof(CURHeader));
		for (uint32_t i = 0; i < CurHeader->count; i++, CurEntry++)
		{
			int d = CurEntry->width - CursorSize;
			int d2 = d * d;

			if (d2 < Distance)
			{
				Distance = d2;
				IconEntry = CurEntry;
			}
		}

		if (IconEntry != nullptr)
		{
			uint8_t Width = IconEntry->width;
			uint8_t Height = IconEntry->height;

			const uint32_t Size = Width * Height;
			const uint8_t* Image = Buffer + IconEntry->imageOffset + sizeof(BMPInfoHeader);

			TArray<FColor> Pixels;
			Pixels.AddUninitialized(Size);

			// Unreal expects pixels in a Y-up
			for (uint32_t RowIndex = 0; RowIndex < Height; RowIndex++)
			{
				for (uint32_t ColIndex = 0; ColIndex < Width; ColIndex++)
				{
					uint32_t SrcIndex = ((Height - 1 - RowIndex) * Height + ColIndex) * 4;
					uint32_t DestIndex = RowIndex * Height + ColIndex;
					Pixels[DestIndex] = FColor(Image[SrcIndex + 0], Image[SrcIndex + 1], Image[SrcIndex + 2], Image[SrcIndex + 3]);
				}
			}

			void* HardwareCursor = PlatformCursor->CreateCursorFromRGBABuffer(Pixels.GetData(), Width, Height,
				FVector2D(IconEntry->hotspotX / Width, IconEntry->hotspotY / Height));
			if (!HardwareCursor)
			{
				return false;
			}

			PlatformCursor->SetTypeShape(CursorShape, HardwareCursor);
			PlatformCursor->SetType(CursorShape);

			return true;
		}
	}

	return false;
}

static float GetDPIScaleAtCursor()
{
	if (FSlateApplication::IsInitialized())
	{
		FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();
		return FPlatformApplicationMisc::GetDPIScaleFactorAtPoint(CursorPos.X, CursorPos.Y);
	}

	return 1.0f;
}

static void NoesisLaunchUrlCallback(void* UserData, const char* Url)
{
	if (Url != nullptr && GIsRunning)
	{
		FPlatformProcess::LaunchURL(StringCast<TCHAR>((UTF8CHAR*)Url).Get(), nullptr, nullptr);
	}
}

static void NoesisUpdateCursorCallback(void* UserData, Noesis::IView* View, Noesis::Cursor* Cursor)
{
	EMouseCursor::Type CursorType = EMouseCursor::Default;
	auto NoesisCursorType = Cursor->Type();
	switch (NoesisCursorType)
	{
	case Noesis::CursorType_None:
		CursorType = EMouseCursor::None;
		break;
	case Noesis::CursorType_No:
		CursorType = EMouseCursor::None;
		break;
	case Noesis::CursorType_Arrow:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_AppStarting:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_Cross:
		CursorType = EMouseCursor::Crosshairs;
		break;
	case Noesis::CursorType_Help:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_IBeam:
		CursorType = EMouseCursor::TextEditBeam;
		break;
	case Noesis::CursorType_SizeAll:
		CursorType = EMouseCursor::CardinalCross;
		break;
	case Noesis::CursorType_SizeNESW:
		CursorType = EMouseCursor::ResizeSouthWest;
		break;
	case Noesis::CursorType_SizeNS:
		CursorType = EMouseCursor::ResizeUpDown;
		break;
	case Noesis::CursorType_SizeNWSE:
		CursorType = EMouseCursor::ResizeSouthEast;
		break;
	case Noesis::CursorType_SizeWE:
		CursorType = EMouseCursor::ResizeLeftRight;
		break;
	case Noesis::CursorType_UpArrow:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_Wait:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_Hand:
		CursorType = EMouseCursor::Hand;
		break;
	case Noesis::CursorType_Pen:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollNS:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollWE:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollAll:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollN:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollS:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollW:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollE:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollNW:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollNE:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollSW:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ScrollSE:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_ArrowCD:
		CursorType = EMouseCursor::Default;
		break;
	case Noesis::CursorType_Custom:
		if (SetHardwareCursor(EMouseCursor::Custom, Cursor->Filename(), GetDPIScaleAtCursor()))
		{
			CursorType = EMouseCursor::Custom;
		}
		else
		{
			CursorType = EMouseCursor::Default;
		}
		break;
	default:
		CursorType = EMouseCursor::Default;
		break;
	}

	auto Instance = UNoesisInstance::FromView(View);
	if (Instance != nullptr)
	{
		Instance->SetCursor(CursorType);
	}
	else
	{
		UNoesisInstance::SetCursorForAll(CursorType);
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

#if NOESIS_USE_STOMP_ALLOCATOR
		Noesis::MemoryCallbacks MemoryCallbacks { new FMallocStomp(), &NoesisAlloc, &NoesisRealloc, &NoesisDealloc, &NoesisAllocSize};
#else
		Noesis::MemoryCallbacks MemoryCallbacks{ nullptr, &NoesisAlloc, &NoesisRealloc, &NoesisDealloc, &NoesisAllocSize };
#endif
		Noesis::GUI::SetMemoryCallbacks(MemoryCallbacks);

		Noesis::GUI::SetErrorHandler(&NoesisErrorHandler);
#if UE_BUILD_SHIPPING + UE_BUILD_SHIPPING_WITH_EDITOR == 0
		Noesis::GUI::SetLogHandler(&NoesisLogHandler);
#else
		Noesis::GUI::DisableHotReload();
		Noesis::GUI::DisableInspector();
#endif

#if !WITH_CASE_PRESERVING_NAME
		Noesis::SymbolManager::SetCaseSensitive(false);
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
		NsRegisterReflectionAppToolkit();

		NsInitPackageAppInteractivity();
		NsInitPackageAppMediaElement();
		NsInitPackageAppRiveBase();
		NsInitPackageAppRive();
		NsInitPackageAppToolkit();

		Noesis::RegisterComponent<LocTextExtension>();
		Noesis::RegisterComponent<LocTableExtension>();
		Noesis::RegisterComponent<InputActionTrigger>();
		Noesis::RegisterComponent<WorldTransformConverter>();
		Noesis::RegisterComponent<BackgroundImage>();
		Noesis::RegisterComponent<BoxShadow>();
		Noesis::RegisterComponent<ChromaticAberrationEffect>();
		Noesis::RegisterComponent<DirectionalBlurEffect>();
		Noesis::RegisterComponent<NoiseEffect>();
		Noesis::RegisterComponent<PinchEffect>();
		Noesis::RegisterComponent<PixelateEffect>();
		Noesis::RegisterComponent<SaturationEffect>();
		Noesis::RegisterComponent<TintEffect>();
		Noesis::RegisterComponent<VignetteEffect>();
		Noesis::RegisterComponent<AbyssBrush>();
		Noesis::RegisterComponent<ConicGradientBrush>();
		Noesis::RegisterComponent<CrossFadeBrush>();
		Noesis::RegisterComponent<PlasmaBrush>();
		Noesis::RegisterComponent<SaturationBrush>();
		Noesis::RegisterComponent<TintBrush>();
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

		Noesis::GUI::SetOpenUrlCallback(nullptr, NoesisLaunchUrlCallback);

		Noesis::GUI::SetCursorCallback(nullptr, &NoesisUpdateCursorCallback);

		PostGarbageCollectConditionalBeginDestroyDelegateHandle = FCoreUObjectDelegates::PostGarbageCollectConditionalBeginDestroy.AddStatic(NoesisGarbageCollected);

#if UE_VERSION_OLDER_THAN(5, 8, 0)
		PostEngineInitDelegateHandle = FCoreDelegates::OnPostEngineInit.AddRaw(this, &FNoesisRuntimeModule::OnPostEngineInit);
#else
		PostEngineInitDelegateHandle = FCoreDelegates::GetOnPostEngineInit().AddRaw(this, &FNoesisRuntimeModule::OnPostEngineInit);
#endif
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
		if (GEditor && !IsRunningCommandlet())
		{
			BlueprintPreCompileHandle = GEditor->OnBlueprintPreCompile().AddStatic(OnBlueprintPreCompile);

			NotifyEnumChangedListener = new NotifyEnumChanged;
			FEnumEditorUtils::FEnumEditorManager::Get().AddListener(NotifyEnumChangedListener);
			NotifyStructChangedListener = new NotifyStructChanged;
			FStructureEditorUtils::FStructEditorManager::Get().AddListener(NotifyStructChangedListener);

			FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
			IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
			AssetsAddedHandle = AssetRegistry.OnAssetsAdded().AddStatic(&OnAssetsAdded);
			AssetsRemovedHandle = AssetRegistry.OnAssetsRemoved().AddStatic(&OnAssetsRemoved);
			AssetRenamedHandle = AssetRegistry.OnAssetRenamed().AddStatic(&OnAssetRenamed);
		}
#endif

		InputPreProcessor = NoesisRegisterInputPreProcessor();

		ViewExtension = NoesisRegisterSceneViewExtension();

		// The D3D11 viewport complains if there are extra references to its back buffer.
#if UE_VERSION_OLDER_THAN(5, 8, 0)
		if (FSlateApplication::IsInitialized())
		{
			FSlateRenderer* SlateRenderer = FSlateApplication::Get().GetRenderer();
			SlateRenderer->OnPreResizeWindowBackBuffer().AddLambda([](void*)
			{
				BackgroundImage::SetBackgroundImageTexture(nullptr);
			});
		}
#else
		FCoreRenderDelegates::OnFlushRenderingCommandsEnd.AddLambda([]()
		{
			BackgroundImage::SetBackgroundImageTexture(nullptr);
		});
#endif

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
		if (GEditor && !IsRunningCommandlet())
		{
			FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
			IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
			AssetRegistry.OnAssetsAdded().Remove(AssetsAddedHandle);
			AssetRegistry.OnAssetsRemoved().Remove(AssetsRemovedHandle);
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

		BackgroundImage::Destroy();

		NoesisUnregisterOverlayRender(OverlayRenderDelegateHandle);

		FTextLocalizationManager::Get().OnTextRevisionChangedEvent.Remove(CultureChangedHandle);

		Noesis::Reflection::SetFallbackHandler(nullptr);

		FCoreDelegates::OnEnginePreExit.Remove(EnginePreExitDelegateHandle);
#if UE_VERSION_OLDER_THAN(5, 8, 0)
		FCoreDelegates::OnPostEngineInit.Remove(PostEngineInitDelegateHandle);
#else
		FCoreDelegates::GetOnPostEngineInit().Remove(PostEngineInitDelegateHandle);
#endif

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
		NsShutdownPackageAppToolkit();

#if WITH_ENHANCED_INPUT
		Noesis::UnregisterComponent<Noesis::EnumConverter<TriggerEvent>>();
		Noesis::UnregisterComponent<EnhancedInputActionTrigger>();
#endif
		Noesis::UnregisterComponent<Noesis::EnumConverter<InputActionType>>();
		Noesis::UnregisterComponent<ChromaticAberrationEffect>();
		Noesis::UnregisterComponent<DirectionalBlurEffect>();
		Noesis::UnregisterComponent<NoiseEffect>();
		Noesis::UnregisterComponent<PinchEffect>();
		Noesis::UnregisterComponent<PixelateEffect>();
		Noesis::UnregisterComponent<SaturationEffect>();
		Noesis::UnregisterComponent<TintEffect>();
		Noesis::UnregisterComponent<VignetteEffect>();
		Noesis::UnregisterComponent<AbyssBrush>();
		Noesis::UnregisterComponent<ConicGradientBrush>();
		Noesis::UnregisterComponent<CrossFadeBrush>();
		Noesis::UnregisterComponent<PlasmaBrush>();
		Noesis::UnregisterComponent<SaturationBrush>();
		Noesis::UnregisterComponent<TintBrush>();
		Noesis::UnregisterComponent<BoxShadow>();
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
	FDelegateHandle AssetsAddedHandle;
	FDelegateHandle AssetsRemovedHandle;
	FDelegateHandle AssetRenamedHandle;
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
DEFINE_LOG_CATEGORY(LogNoesisEngine);
