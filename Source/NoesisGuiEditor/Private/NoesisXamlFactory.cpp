////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiEditorPrivatePCH.h"
#include "NoesisBlueprintFactory.h"

// Core includes
#include "Misc/Paths.h"

// UnrealEd includes
#include "Kismet2/KismetEditorUtilities.h"

// BlueprintGraph includes
#include "EdGraphSchema_K2.h"

// NoesisGui includes
#include "NoesisGuiSupport.h"
#include "NoesisBlueprintGeneratedClass.h"
#include "NoesisBlueprint.h"
#include "NoesisGeneratedClasses.h"
#include "NoesisCreateClass.h"

// NoesisGuiEditor includes
#include "NoesisGuiEditorModule.h"

#define LOCTEXT_NAMESPACE "UNoesisBlueprintFactory"

UNoesisXamlFactory::UNoesisXamlFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bEditorImport = true;
	bEditAfterNew = true;
	SupportedClass = UNoesisXaml::StaticClass();
	Formats.Add(TEXT("xaml;NoesisGui Xaml"));
}

class FNoesisGuiEditorResourceProvider : public Noesis::XamlProvider, public Noesis::TextureProvider, public Noesis::FontProvider
{
public:

	FNoesisGuiEditorResourceProvider(FString InRootFolder, UNoesisXaml* InNoesisXaml)
		: RootFolder(InRootFolder), NoesisXaml(InNoesisXaml)
	{
		Noesis::Gui::Provider Provider = { this, this, this };
		Noesis::GUI::SetResourceProvider(Provider);
	}

	~FNoesisGuiEditorResourceProvider()
	{
		Noesis::Gui::Provider Provider = { nullptr, nullptr, nullptr };
		Noesis::GUI::SetResourceProvider(Provider);
	}

	UNoesisXaml* ImportXaml(FString XamlPath);
	UTexture2D* ImportTexture(FString TexturePath);
	UFont* ImportFont(FString FontPath);

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

	FString RootFolder;
	UNoesisXaml* NoesisXaml;
};

UNoesisXaml* FNoesisGuiEditorResourceProvider::ImportXaml(FString XamlPath)
{
	UNoesisXaml* Xaml = NULL;

	FString BasePackageName = FPackageName::GetLongPackagePath(NoesisXaml->GetOutermost()->GetPathName());
	FString Extension = FPaths::GetExtension(XamlPath).ToLower();
	FString XamlName = FPaths::GetBaseFilename(XamlPath);
	FString RelativePath = FPaths::GetPath(XamlPath);

	XamlName = ObjectTools::SanitizeObjectName(XamlName);

	FString XamlObjectPath = BasePackageName / RelativePath / XamlName + TEXT(".") + XamlName;
	Xaml = LoadObject<UNoesisXaml>(NULL, *XamlObjectPath);

	if (!Xaml)
	{
		const FString Suffix(TEXT(""));

		FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
		FString FinalPackageName;
		AssetToolsModule.Get().CreateUniqueAssetName(BasePackageName / RelativePath / XamlName, Suffix, FinalPackageName, XamlName);

		UPackage* XamlPackage = CreatePackage(NULL, *FinalPackageName);
		Xaml = NewObject<UNoesisXaml>(XamlPackage, FName(*XamlName));
	}

	FString FullFilename = RootFolder + TEXT("/") + XamlPath;
	TArray<uint8> DataBinary;
	FFileHelper::LoadFileToArray(DataBinary, *FullFilename);

	if (DataBinary.Num())
	{

		Xaml->XamlText = DataBinary;
	}

	NoesisXaml->XamlMap.Add(XamlPath, Xaml);
	return Xaml;
}

Noesis::Ptr<Noesis::Core::Stream> FNoesisGuiEditorResourceProvider::LoadXaml(const NsChar* Path)
{
	UNoesisXaml* Xaml = ImportXaml(Path);
	if (Xaml)
	{
		return Noesis::Ptr<Noesis::Core::Stream>(*new Noesis::Core::MemoryStream(Xaml->XamlText.GetData(), (NsSize)Xaml->XamlText.Num()));
	}

	return Noesis::Ptr<Noesis::Core::Stream>();
};

UTexture2D* FNoesisGuiEditorResourceProvider::ImportTexture(FString TexturePath)
{
	UTexture2D* Texture = NULL;

	FString BasePackageName = FPackageName::GetLongPackagePath(NoesisXaml->GetOutermost()->GetPathName());
	FString Extension = FPaths::GetExtension(TexturePath).ToLower();
	FString TextureName = FPaths::GetBaseFilename(TexturePath);
	FString RelativePath = FPaths::GetPath(TexturePath);

	TextureName = ObjectTools::SanitizeObjectName(TextureName);

	UPackage* TexturePackage = NULL;

	FString TextureObjectPath = BasePackageName / RelativePath / TextureName + TEXT(".") + TextureName;
	UTexture2D* ExistingTexture = LoadObject<UTexture2D>(NULL, *TextureObjectPath);

	if (!ExistingTexture)
	{
		const FString Suffix(TEXT(""));

		FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
		FString FinalPackageName;
		AssetToolsModule.Get().CreateUniqueAssetName(BasePackageName / RelativePath / TextureName, Suffix, FinalPackageName, TextureName);

		TexturePackage = CreatePackage(NULL, *FinalPackageName);
	}
	else
	{
		TexturePackage = ExistingTexture->GetOutermost();
	}

	auto TextureFact = NewObject<UTextureFactory>();
	TextureFact->AddToRoot();

	TextureFact->SuppressImportOverwriteDialog();

	FString FullFilename = RootFolder + TEXT("/") + TexturePath;
	bool Cancelled = false;
	Texture = (UTexture2D*)TextureFact->ImportObject(UTexture2D::StaticClass(), TexturePackage, *TextureName, RF_Standalone | RF_Public, FullFilename, nullptr, Cancelled);

	if (Texture != NULL)
	{
		// Notify the asset registry
		FAssetRegistryModule::AssetCreated(Texture);

		// Set the dirty flag so this package will get saved later
		TexturePackage->SetDirtyFlag(true);
	}
	TextureFact->RemoveFromRoot();

	NoesisXaml->TextureMap.Add(TexturePath, Texture);
	return Texture;
}

Noesis::Drawing::TextureInfo FNoesisGuiEditorResourceProvider::GetTextureInfo(const NsChar* Path)
{
	UTexture2D* Texture = ImportTexture(Path);
	if (Texture)
	{
		return Noesis::Drawing::TextureInfo{ (NsSize)Texture->GetSizeX(), (NsSize)Texture->GetSizeY() };
	}

	return Noesis::Drawing::TextureInfo{};
}

Noesis::Ptr<Noesis::Render::Texture> FNoesisGuiEditorResourceProvider::LoadTexture(const NsChar* Path, Noesis::Render::RenderDevice* RenderDevice)
{
	UTexture2D* Texture = ImportTexture(Path);

	return Noesis::Ptr<Noesis::Render::Texture>(nullptr);
};

UFont* FNoesisGuiEditorResourceProvider::ImportFont(FString FontPath)
{
	UFont* Font = NULL;

	FString BasePackageName = FPackageName::GetLongPackagePath(NoesisXaml->GetOutermost()->GetPathName());
	FString Extension = FPaths::GetExtension(FontPath).ToLower();
	FString FontName = FPaths::GetBaseFilename(FontPath);
	FString RelativePath = FPaths::GetPath(FontPath);

	FontName = ObjectTools::SanitizeObjectName(FontName);

	UPackage* FontPackage = NULL;

	FString FontObjectPath = BasePackageName / RelativePath / FontName + TEXT(".") + FontName;
	UFont* ExistingFont = LoadObject<UFont>(NULL, *FontObjectPath);

	if (!ExistingFont)
	{
		const FString Suffix(TEXT(""));

		FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
		FString FinalPackageName;
		AssetToolsModule.Get().CreateUniqueAssetName(BasePackageName / RelativePath / FontName, Suffix, FinalPackageName, FontName);

		FontPackage = CreatePackage(NULL, *FinalPackageName);
	}
	else
	{
		FontPackage = ExistingFont->GetOutermost();
	}

	auto FontFactory = NewObject<UFontFileImportFactory>();
	FontFactory->AddToRoot();

	FString FullFilename = RootFolder + TEXT("/") + FontPath;
	bool Cancelled;
	Font = (UFont*)FontFactory->ImportObject(UFont::StaticClass(), FontPackage, *FontName, RF_Standalone | RF_Public, FullFilename, nullptr, Cancelled);

	if (Font != NULL)
	{
		// Notify the asset registry
		FAssetRegistryModule::AssetCreated(Font);

		// Set the dirty flag so this package will get saved later
		FontPackage->SetDirtyFlag(true);
	}
	FontFactory->RemoveFromRoot();

	NoesisXaml->FontMap.Add(FontPath, Font);
	return Font;
}

Noesis::Drawing::FontSource FNoesisGuiEditorResourceProvider::MatchFont(const NsChar* BaseUri, const NsChar* FamilyName, Noesis::Drawing::FontWeight Weight, Noesis::Drawing::FontStretch Stretch, Noesis::Drawing::FontStyle Style)
{
	Noesis::Drawing::FontSource Source;
	Source.file = Noesis::Ptr<Noesis::Core::Stream>(nullptr);
	UFont* Font = ImportFont(FString(BaseUri) + FamilyName + TEXT(".ttf"));
	if (Font)
	{
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
	return Source;
}

class FNoesisGuiNullTexture : public Noesis::Render::Texture
{
public:

	// Texture interface
	virtual NsSize GetWidth() const override
	{
		return 16 * 1024;
	}

	virtual NsSize GetHeight() const override
	{
		return 16 * 1024;
	}

	virtual Noesis::Render::TextureFormat::Enum GetFormat() const override
	{
		return Noesis::Render::TextureFormat::BGRA8;
	}

	virtual NsBool HasMipMaps() const override
	{
		return false;
	}

	virtual NsBool IsInverted() const override
	{
		return (NsBool)false;
	}
	// End of Texture interface
};

class FNoesisGuiNullRenderTarget : public Noesis::Render::RenderTarget
{
public:

	// RenderTarget interface
	virtual Noesis::Render::Texture* GetTexture() override
	{
		return NoesisGuiTexture.GetPtr();
	}
	// End of RenderTarget interface

	Noesis::Ptr<FNoesisGuiNullTexture> NoesisGuiTexture;
};

class FNoesisGuiNullRenderDevice : public Noesis::Render::RenderDevice
{
	// RenderDevice interface
	virtual const Noesis::Render::DeviceCaps& GetCaps() const override { static Noesis::Render::DeviceCaps Caps = { 0.f, 1024 * 1024, 1024 * 1024, true, false, { true, true } }; return Caps; }
	virtual Noesis::Ptr<Noesis::Render::RenderTarget> CreateRenderTarget(const NsChar* Label, NsSize Width, NsSize Height, NsSize SampleCount) override { FNoesisGuiNullRenderTarget* RT = new FNoesisGuiNullRenderTarget(); RT->NoesisGuiTexture = *new FNoesisGuiNullTexture(); return Noesis::Ptr<Noesis::Render::RenderTarget>(*RT); }
	virtual Noesis::Ptr<Noesis::Render::RenderTarget> CloneRenderTarget(const NsChar* Label, Noesis::Render::RenderTarget* SharedRenderTarget) override { FNoesisGuiNullRenderTarget* RT = new FNoesisGuiNullRenderTarget(); RT->NoesisGuiTexture = ((FNoesisGuiNullRenderTarget*)SharedRenderTarget)->NoesisGuiTexture; return Noesis::Ptr<Noesis::Render::RenderTarget>(*RT); }
	virtual Noesis::Ptr<Noesis::Render::Texture> CreateTexture(const NsChar* Label, NsSize Width, NsSize Height, NsSize NumLevels, Noesis::Render::TextureFormat::Enum TextureFormat) override { return Noesis::Ptr<Noesis::Render::Texture>(*new FNoesisGuiNullTexture()); }
	virtual void UpdateTexture(Noesis::Render::Texture* Texture, NsSize Level, NsSize X, NsSize Y, NsSize Width, NsSize Height, const void* Data) override {}
	virtual void BeginRender(NsBool Offscreen) override {}
	virtual void SetRenderTarget(Noesis::Render::RenderTarget* Surface) override {}
	virtual void BeginTile(const Noesis::Render::Tile& Tile, NsSize SurfaceWidth, NsSize SurfaceHeight) override {}
	virtual void EndTile() override {}
	virtual void ResolveRenderTarget(Noesis::Render::RenderTarget* Surface, const Noesis::Render::Tile* Tiles, NsSize NumTiles) override {}
	virtual void EndRender() override {}
	virtual void* MapVertices(NsSize Bytes) override { return Buffer; }
	virtual void UnmapVertices() override {}
	virtual void* MapIndices(NsSize Bytes) override { return Buffer; }
	virtual void UnmapIndices() override {}
	virtual void DrawBatch(const Noesis::Render::Batch& Batch) override {}
	// End of RenderDevice interface

	uint8 Buffer[1024 * 1024];
};

UObject* UNoesisXamlFactory::FactoryCreateBinary(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn)
{
	UNoesisXaml* NoesisXaml = NewObject<UNoesisXaml>(Parent, Class, Name, Flags);

	FString Filename = FPaths::ConvertRelativePathToFull(GetCurrentFilename());
	FPaths::MakePlatformFilename(Filename);
	FString NoesisGuiAssetName = FPaths::GetCleanFilename(Filename);
	FNoesisGuiEditorResourceProvider NoesisGuiEditorResourceProvider(*FPaths::GetPath(Filename), NoesisXaml);
	Noesis::Ptr<Noesis::Core::BaseComponent> Xaml = Noesis::GUI::LoadXaml(StringCast<NsChar>(*NoesisGuiAssetName).Get());
	Noesis::Ptr<Noesis::FrameworkElement> FrameworkElement = NsDynamicCast<Noesis::Ptr<Noesis::FrameworkElement>>(Xaml);
	Noesis::Ptr<Noesis::ResourceDictionary> ResourceDictionary = NsDynamicCast<Noesis::Ptr<Noesis::ResourceDictionary>>(Xaml);

	// Creating a view causes more assets to be requested.
	FNoesisGuiNullRenderDevice NoesisGuiNullRenderDevice;
	Noesis::Gui::VGOptions VgOptions;
	VgOptions.offscreenWidth = 1024;
	VgOptions.offscreenHeight = 1024;
	VgOptions.offscreenSampleCount = 1;
	VgOptions.offscreenDefaultNumSurfaces = 1;
	VgOptions.offscreenMaxNumSurfaces = 2;
	VgOptions.glyphCacheTextureWidth = 1024;
	VgOptions.glyphCacheTextureHeight = 1024;
	VgOptions.glyphCacheMeshTreshold = 1024;
	Noesis::Ptr<Noesis::Gui::VGContext> VgContext = Noesis::GUI::CreateVGContext(&NoesisGuiNullRenderDevice, VgOptions);
	Noesis::Ptr<Noesis::Gui::IView> XamlView = Noesis::GUI::CreateView(FrameworkElement.GetPtr());
	Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
	Renderer->Init(VgContext.GetPtr());
	XamlView->SetSize(16384, 16384);
	XamlView->Update(0);
	Renderer->UpdateRenderTree();
	if (Renderer->NeedsOffscreen())
	{
		Renderer->RenderOffscreen();
	}
	Renderer->Render();
	Renderer->Shutdown();

	TArray<Noesis::FrameworkElement*> Elements;
	CollectElements(FrameworkElement.GetPtr(), Elements);
	for (auto Element : Elements)
	{
		const NsChar* ElementName = Element->GetName();
		UNoesisBaseComponent* NoesisGuiComponent = CreateClassFor(Element, NoesisXaml);
		NoesisGuiComponent->ElementName = ElementName ? NsStringToFName(ElementName) : NAME_None;
		NoesisXaml->Components.Add(NoesisGuiComponent);
	}

	return NoesisXaml;
}
