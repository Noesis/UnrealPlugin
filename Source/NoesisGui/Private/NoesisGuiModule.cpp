////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiModule.h"

// NoesisGui includes
#include "NoesisGuiResourceManager.h"
#include "Render/NoesisRenderDevice.h"

#if PLATFORM_WINDOWS
#include "AllowWindowsPlatformTypes.h"
#include <DelayImp.h>
#include "HideWindowsPlatformTypes.h"
#endif

static void NoesisErrorHandler(const NsChar* Filename, NsSize Line, const NsChar* Desc, NsBool Fatal)
{
	if (Fatal)
	{
		FPlatformMisc::RequestExit(true);
	}
}

class FNoesisGuiResourceProvider : public Noesis::XamlProvider, public Noesis::TextureProvider, public Noesis::CachedFontProvider
{
public:

	FNoesisGuiResourceProvider()
	{
		//check(IsInGameThread());
	}

	UNoesisXaml* GetXaml(FString XamlPath);
	UTexture2D* GetTexture(FString TexturePath);

	// XamlProvider interface
	virtual Noesis::Ptr<Noesis::Core::Stream> LoadXaml(const NsChar* Filename) override;
	// End of XamlProvider interface

	// TextureProvider interface
	virtual Noesis::Drawing::TextureInfo GetTextureInfo(const NsChar* Path) override;
	virtual Noesis::Ptr<Noesis::Render::Texture> LoadTexture(const NsChar* Path, Noesis::Render::RenderDevice* RenderDevice) override;
	// End of TextureProvider interface

	// CachedFontProvider interface
	virtual void ScanFolder(const NsChar* Folder) override;
	virtual Noesis::Ptr<Noesis::Core::Stream> OpenFont(const NsChar* Folder, const NsChar* Filename) const override;
	// End of CachedFontProvider interface
};

UNoesisXaml* FNoesisGuiResourceProvider::GetXaml(FString XamlPath)
{
	FString ObjectIDString, Path;
	ensure(XamlPath.Split(TEXT("/"), &ObjectIDString, &Path));
	uint32 ObjectID = FCString::Atoi64(*ObjectIDString);
	FUObjectItem* ObjectItem = GUObjectArray.IndexToObject(ObjectID);
	UNoesisXaml* BaseXaml = Cast<UNoesisXaml>((UObject*)ObjectItem->Object);
	if (BaseXaml)
	{
		UNoesisXaml** XamlPtr = BaseXaml->XamlMap.Find(Path);
		if (XamlPtr)
		{
			UNoesisXaml* Xaml = *XamlPtr;
			return Xaml;
		}
	}
	return nullptr;
}

Noesis::Ptr<Noesis::Core::Stream> FNoesisGuiResourceProvider::LoadXaml(const NsChar* Path)
{
	UNoesisXaml* Xaml = GetXaml(Path);
	if (Xaml)
	{
		return Noesis::Ptr<Noesis::Core::Stream>(*new Noesis::Core::MemoryStream(Xaml->XamlText.GetData(), (NsSize)Xaml->XamlText.Num()));
	}

	return Noesis::Ptr<Noesis::Core::Stream>();
};

UTexture2D* FNoesisGuiResourceProvider::GetTexture(FString TexturePath)
{
	FString ObjectIDString, Path;
	ensure(TexturePath.Split(TEXT("/"), &ObjectIDString, &Path));
	uint32 ObjectID = FCString::Atoi64(*ObjectIDString);
	FUObjectItem* ObjectItem = GUObjectArray.IndexToObject(ObjectID);
	UNoesisXaml* BaseXaml = Cast<UNoesisXaml>((UObject*)ObjectItem->Object);
	if (BaseXaml)
	{
		UTexture2D** TexturePtr = BaseXaml->TextureMap.Find(Path);
		if (TexturePtr)
		{
			UTexture2D* Texture = *TexturePtr;
			return Texture;
		}
	}
	return nullptr;
}

Noesis::Drawing::TextureInfo FNoesisGuiResourceProvider::GetTextureInfo(const NsChar* Path)
{
	UTexture* Texture = GetTexture(Path);
	UTexture2D* Texture2D = CastChecked<UTexture2D>(Texture);
	if (Texture2D)
	{
		return Noesis::Drawing::TextureInfo{ (NsSize)Texture2D->GetSizeX(), (NsSize)Texture2D->GetSizeY() };
	}

	return Noesis::Drawing::TextureInfo{};
}

Noesis::Ptr<Noesis::Render::Texture> FNoesisGuiResourceProvider::LoadTexture(const NsChar* Path, Noesis::Render::RenderDevice* RenderDevice)
{
	return NoesisGuiCreateTexture(GetTexture(Path));
};

void FNoesisGuiResourceProvider::ScanFolder(const NsChar* InFolder)
{
	FString FontPath = FString(InFolder);
	FString ObjectIDString, Path;
	ensure(FontPath.Split(TEXT("/"), &ObjectIDString, &Path));
	uint32 ObjectID = FCString::Atoi64(*ObjectIDString);
	FUObjectItem* ObjectItem = GUObjectArray.IndexToObject(ObjectID);
	UNoesisXaml* BaseXaml = Cast<UNoesisXaml>((UObject*)ObjectItem->Object);
	for (auto Font : BaseXaml->FontMap)
	{
		RegisterFont(StringCast<NsChar>(*ObjectIDString).Get(), StringCast<NsChar>(*Font.Key).Get());
	}
}

Noesis::Ptr<Noesis::Core::Stream> FNoesisGuiResourceProvider::OpenFont(const NsChar* InFolder, const NsChar* InFilename) const
{
	uint32 ObjectID = FCString::Atoi64(*NsStringToFString(InFolder));
	FUObjectItem* ObjectItem = GUObjectArray.IndexToObject(ObjectID);
	UNoesisXaml* BaseXaml = Cast<UNoesisXaml>((UObject*)ObjectItem->Object);
	UFont* Font = *BaseXaml->FontMap.Find(NsStringToFString(InFilename));
	if (!Font)
	{
		Font = GEngine->GetMediumFont();
	}
	const FCompositeFont* CompositeFont = Font->GetCompositeFont();
	const FTypeface* Typeface = &CompositeFont->DefaultTypeface;
	const FTypefaceEntry* TypefaceEntry = &Typeface->Fonts[0];
	const FFontData* FontData = &TypefaceEntry->Font;
	const UFontBulkData* FontBulkData = FontData->BulkDataPtr;
	class FontBulkDataMemoryStream : public Noesis::Core::MemoryStream
	{
	public:
		FontBulkDataMemoryStream(const UFontBulkData* InFontBulkData)
			: Noesis::Core::MemoryStream(InFontBulkData->Lock(FontDataSize), (NsSize)InFontBulkData->GetBulkDataSize())
			, FontBulkData(InFontBulkData)
		{
		}

		virtual ~FontBulkDataMemoryStream()
		{
			FontBulkData->Unlock();
		}

	private:
		const UFontBulkData* FontBulkData;
		int32 FontDataSize;
	};
	return Noesis::Ptr<Noesis::Core::Stream>(*new FontBulkDataMemoryStream(FontBulkData));
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

const PfnDliHook __pfnDliNotifyHook2 = delayLoadHook;
#endif

class FNoesisGuiModule : public INoesisGuiModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		Noesis::GUI::Init(&NoesisErrorHandler);

		NoesisGuiResourceProvider = new FNoesisGuiResourceProvider();
		SetResourceProvider();

		NoesisGuiModuleInterface = this;
	}

	virtual void ShutdownModule() override
	{
		Noesis::Gui::Provider NoesisGuiProvider = { nullptr, nullptr, nullptr };
		Noesis::GUI::SetResourceProvider(NoesisGuiProvider);
		delete NoesisGuiResourceProvider;
		NoesisGuiResourceProvider = nullptr;

		NoesisGuiModuleInterface = 0;
		Noesis::GUI::Shutdown();
	}
	// End of IModuleInterface interface

	// INoesisGuiModuleInterface interface
	virtual void SetResourceProvider() override
	{
		Noesis::Gui::Provider NoesisGuiProvider = { NoesisGuiResourceProvider, NoesisGuiResourceProvider, NoesisGuiResourceProvider };
		Noesis::GUI::SetResourceProvider(NoesisGuiProvider);
	}
	// End of INoesisGuiModuleInterface interface

	static INoesisGuiModuleInterface* NoesisGuiModuleInterface;
	FNoesisGuiResourceProvider* NoesisGuiResourceProvider;
};

INoesisGuiModuleInterface* FNoesisGuiModule::NoesisGuiModuleInterface = 0;

INoesisGuiModuleInterface* INoesisGuiModuleInterface::Get()
{
	return FNoesisGuiModule::NoesisGuiModuleInterface;
}

IMPLEMENT_MODULE(FNoesisGuiModule, NoesisGui);
DEFINE_LOG_CATEGORY(LogNoesisGui);
