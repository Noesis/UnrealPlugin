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
#include "Materials/MaterialInterface.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundWave.h"

// MediaAssets includes
#include "MediaSource.h"

// NoesisRuntime includes
#include "NoesisRuntimeModule.h"
#include "NoesisRive.h"

UNoesisXaml::UNoesisXaml(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

Noesis::Ptr<Noesis::BaseComponent> UNoesisXaml::LoadXaml()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
		return nullptr;

	FString Uri = GetXamlUri();
	return Noesis::GUI::LoadXaml((ANSICHAR*)StringCast<UTF8CHAR>(*Uri).Get());
}

void UNoesisXaml::LoadComponent(Noesis::BaseComponent* Component)
{
	FString Uri = GetXamlUri();
	Noesis::GUI::LoadComponent(Component, (ANSICHAR*)StringCast<UTF8CHAR>(*Uri).Get());
}

uint32 UNoesisXaml::GetContentHash() const
{
	uint32 Hash = Noesis::HashBytes(XamlText.GetData(), XamlText.Num());

	return Hash;
}

#if WITH_EDITORONLY_DATA
void UNoesisXaml::PostLoad()
{
	Super::PostLoad();

	Dependencies.Append(MoveTemp(Xamls_DEPRECATED));
	Dependencies.Append(MoveTemp(Textures_DEPRECATED));
	Dependencies.Append(MoveTemp(Fonts_DEPRECATED));
	Dependencies.Append(MoveTemp(FontFaces_DEPRECATED));
	Dependencies.Append(MoveTemp(Sounds_DEPRECATED));
	Dependencies.Append(MoveTemp(Videos_DEPRECATED));
	Dependencies.Append(MoveTemp(Rives_DEPRECATED));
	Dependencies.Append(MoveTemp(Materials_DEPRECATED));
}

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
	for (auto Dependency : Dependencies)
	{
		if (auto Font = Cast<UFont>(Dependency))
		{
			auto CompositeFont = Font->GetCompositeFont();
			if (CompositeFont != nullptr)
			{
				for (auto TypefaceEntry : CompositeFont->DefaultTypeface.Fonts)
				{
					const FFontData* FontData = &TypefaceEntry.Font;
					const UFontFace* FontFace = Cast<UFontFace>(FontData->GetFontFaceAsset());
					NoesisRuntime.RegisterFont(FontFace);
				}
			}
		}
		else if (auto FontFace = Cast<UFontFace>(Dependency))
		{
			NoesisRuntime.RegisterFont(FontFace);
		}
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
void UNoesisXaml::RenderThumbnail(FIntRect ViewportRect, const FTextureRHIRef& BackBuffer)
{
	if (!ThumbnailRenderer.IsInitialized())
	{
		Noesis::Ptr<Noesis::BaseComponent> Root = UNoesisXaml::LoadXaml();
		Noesis::FrameworkElement* Content = Noesis::DynamicCast<Noesis::FrameworkElement*>(Root.GetPtr());
		ThumbnailRenderer.Initialize(Content);
	}

	UWorld* World = GetWorld();
	if (!IsValid(World)) World = GWorld.GetReference();
	if (IsValid(World))
	{
		ThumbnailRenderer.Render(World, ViewportRect, BackBuffer);
	}
}

void UNoesisXaml::DestroyThumbnailRenderData()
{
	ThumbnailRenderer.Destroy();
}
#endif
