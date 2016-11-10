////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiModule.h"

// NoesisGui includes
#include "NoesisGuiResourceManager.h"
#include "Render/NoesisRenderDevice.h"

static void NoesisErrorHandler(const NsChar* Filename, NsInt Line, const NsChar* Desc)
{
	FPlatformMisc::RequestExit(true);
}

class FNoesisGuiResourceProvider : public Noesis::XamlProvider, public Noesis::TextureProvider, public Noesis::FontProvider
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

	// FontProvider interface
	virtual Noesis::Drawing::FontSource MatchFont(const NsChar* BaseUri, const NsChar* FamilyName, Noesis::Drawing::FontWeight Weight, Noesis::Drawing::FontStretch Stretch, Noesis::Drawing::FontStyle Style) override;
	// End of FontProvider interface

	UNoesisXaml* NoesisXaml;
};

UNoesisXaml* FNoesisGuiResourceProvider::GetXaml(FString XamlPath)
{
	//UNoesisXaml** Xaml = NoesisXaml->XamlMap.Find(XamlPath);
	UNoesisXaml* Xaml = LoadObject<UNoesisXaml>(NULL, *FPaths::GetBaseFilename(XamlPath, false));
	return Xaml;
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
	//UTexture2D** Texture = NoesisXaml->TextureMap.Find(TexturePath);
	UTexture2D* Texture = LoadObject<UTexture2D>(NULL, *FPaths::GetBaseFilename(TexturePath, false));
	return Texture;
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

Noesis::Drawing::FontSource FNoesisGuiResourceProvider::MatchFont(const NsChar* BaseUri, const NsChar* FamilyName, Noesis::Drawing::FontWeight Weight, Noesis::Drawing::FontStretch Stretch, Noesis::Drawing::FontStyle Style)
{
	Noesis::Drawing::FontSource Source;
	Source.file = Noesis::Ptr<Noesis::Core::Stream>(nullptr);
	UFont* Font = LoadObject<UFont>(NULL, *FPaths::GetBaseFilename((FString(BaseUri) + FamilyName).Replace(TEXT(" "), TEXT("_")), false));
	if (!Font)
	{
		Font = GEngine->GetMediumFont();
	}
	const FCompositeFont* CompositeFont = Font->GetCompositeFont();
	const FTypeface* Typeface = &CompositeFont->DefaultTypeface;
	const FTypefaceEntry* TypefaceEntry = &Typeface->Fonts[0];
	const FFontData* FontData = &TypefaceEntry->Font;
	const UFontBulkData* FontBulkData = FontData->BulkDataPtr;
	int32 FontDataSize = 0;
	const void* FontDataBytes = FontBulkData->Lock(FontDataSize);
	Source.file = Noesis::Ptr<Noesis::Core::Stream>(*new Noesis::Core::MemoryStream(FontDataBytes, (NsSize)FontDataSize));
	FontBulkData->Unlock();
	Source.faceIndex = 0;
	return Source;
}

class FNoesisGuiModule : public INoesisGuiModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		FString NoesisDllPath = FPaths::EngineDir() / TEXT(NOESISGUI_DLL_PATH);
		FPlatformProcess::PushDllDirectory(*FPaths::GetPath(NoesisDllPath));
		FPlatformProcess::GetDllHandle(*NoesisDllPath);
		FPlatformProcess::PopDllDirectory(*FPaths::GetPath(NoesisDllPath));
		Noesis::GUI::Init(&NoesisErrorHandler);

		NoesisGuiResourceProvider = new FNoesisGuiResourceProvider();
		SetResourceProvider(nullptr);

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
	virtual void SetResourceProvider(UNoesisXaml* NoesisXaml) override
	{
		NoesisGuiResourceProvider->NoesisXaml = NoesisXaml;
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
