////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRuntimeModule.h"

// NoesisRuntime includes
#include "NoesisResourceProvider.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisTypeClass.h"
#include "NoesisSettings.h"

#if PLATFORM_WINDOWS
#include "AllowWindowsPlatformTypes.h"
#include <DelayImp.h>
#include "HideWindowsPlatformTypes.h"
#endif

static void NoesisErrorHandler(const char* Filename, uint32 Line, const char* Desc, bool Fatal)
{
	if (Fatal)
	{
		FPlatformMisc::RequestExit(true);
	}
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
		FString NoesisDllPath = FPaths::EngineDir() / TEXT(NOESISGUI_DLL_PATH);
		FPlatformProcess::PushDllDirectory(*FPaths::GetPath(NoesisDllPath));
		void* DllHandle = FPlatformProcess::GetDllHandle(*NoesisDllPath);
		FPlatformProcess::PopDllDirectory(*FPaths::GetPath(NoesisDllPath));
		return (FARPROC)DllHandle;
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
}

void OnAssetRenamed(const FAssetData&, const FString&)
{
	NoesisDestroyAllTypes();
}
#endif

void AddOnBlueprintPreCompileDelegate()
{
#if WITH_EDITOR
	GEditor->OnBlueprintPreCompile().AddStatic(OnBlueprintPreCompile);
	FEnumEditorUtils::FEnumEditorManager::Get().AddListener(new NotifyEnumChanged);
	FStructureEditorUtils::FStructEditorManager::Get().AddListener(new NotifyStructChanged);

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
	AssetRegistry.OnAssetRenamed().AddStatic(&OnAssetRenamed);
#endif
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

		NoesisRuntimeModuleInterface = this;

		PostGarbageCollectConditionalBeginDestroyDelegateHandle = FCoreUObjectDelegates::PostGarbageCollectConditionalBeginDestroy.AddStatic(NoesisGarbageCollected);

		PostEngineInitDelegateHandle = FCoreDelegates::OnPostEngineInit.AddStatic(AddOnBlueprintPreCompileDelegate);
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
