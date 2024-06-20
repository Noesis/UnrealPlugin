////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXaml.h"

// CoreUObject includes
#include "Misc/PackageName.h"
#include "UObject/Package.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"
#include "Engine/Font.h"
#include "Engine/FontFace.h"
#include "Engine/World.h"

// NoesisRuntime includes
#include "NoesisRuntimeModule.h"
#include "NoesisThumbnailRenderer.h"

UNoesisXaml::UNoesisXaml(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

Noesis::Ptr<Noesis::BaseComponent> UNoesisXaml::LoadXaml()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
		return nullptr;

	FString Uri = GetXamlUri();
	return Noesis::GUI::LoadXaml(TCHAR_TO_UTF8(*Uri));
}

void UNoesisXaml::LoadComponent(Noesis::BaseComponent* Component)
{
	FString Uri = GetXamlUri();
	Noesis::GUI::LoadComponent(Component, TCHAR_TO_UTF8(*Uri));
}

uint32 UNoesisXaml::GetContentHash() const
{
	uint32 Hash = Noesis::HashBytes(XamlText.GetData(), XamlText.Num());

	for (auto Xaml : Xamls)
	{
		if (Xaml != nullptr)
		{
			Hash ^= Xaml->GetContentHash();
		}
	}

	return Hash;
}

#if WITH_EDITORONLY_DATA
void UNoesisXaml::PostInitProperties()
{
	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		AssetImportData = NewObject<UAssetImportData>(this, TEXT("AssetImportData"));
	}

	Super::PostInitProperties();
}

#if UE_VERSION_OLDER_THAN(5, 4, 0)
void UNoesisXaml::GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const
{
	if (AssetImportData)
	{
		OutTags.Add(FAssetRegistryTag(SourceFileTagName(), AssetImportData->GetSourceData().ToJson(), FAssetRegistryTag::TT_Hidden));
	}

	Super::GetAssetRegistryTags(OutTags);
}
#else
void UNoesisXaml::GetAssetRegistryTags(FAssetRegistryTagsContext Context) const
{
	if (AssetImportData)
	{
		Context.AddTag(FAssetRegistryTag(SourceFileTagName(), AssetImportData->GetSourceData().ToJson(), FAssetRegistryTag::TT_Hidden));
	}

	Super::GetAssetRegistryTags(Context);
}
#endif
#endif // WITH_EDITORONLY_DATA

void UNoesisXaml::RegisterDependencies()
{
	INoesisRuntimeModuleInterface& NoesisRuntime = INoesisRuntimeModuleInterface::Get();
	for (auto Font : Fonts)
	{
		for (auto TypefaceEntry : Font->CompositeFont.DefaultTypeface.Fonts)
		{
			const FFontData* FontData = &TypefaceEntry.Font;
			const UFontFace* FontFace = Cast<UFontFace>(FontData->GetFontFaceAsset());
			NoesisRuntime.RegisterFont(FontFace);
		}
	}

	for (auto FontFace : FontFaces)
	{
		NoesisRuntime.RegisterFont(FontFace);
	}
}

FString UNoesisXaml::GetXamlUri() const
{
	UObject* Package = GetOutermost();
	FString PackageRoot, PackagePath, PackageName;
	FPackageName::SplitLongPackageName(Package->GetPathName(), PackageRoot, PackagePath, PackageName, false);
	return PackageRoot.LeftChop(1) + TEXT(";component/") + PackagePath + PackageName + TEXT(".xaml");
}

#if WITH_EDITOR
void UNoesisXaml::RenderThumbnail(FIntRect ViewportRect, const FTexture2DRHIRef& BackBuffer)
{
	if (ThumbnailView == nullptr)
	{
		Noesis::Ptr<Noesis::BaseComponent> Root = UNoesisXaml::LoadXaml();
		Noesis::FrameworkElement* Content = Noesis::DynamicCast<Noesis::FrameworkElement*>(Root.GetPtr());
		ThumbnailView = FNoesisThumbnailRenderer::CreateView(Content);
	}

	UWorld* World = GetWorld();
	if (World == nullptr) World = GWorld.GetReference();
	FNoesisThumbnailRenderer::RenderView(ThumbnailView, World, ViewportRect, BackBuffer);
}

void UNoesisXaml::DestroyThumbnailRenderData()
{
	ThumbnailView.Reset();
}
#endif
