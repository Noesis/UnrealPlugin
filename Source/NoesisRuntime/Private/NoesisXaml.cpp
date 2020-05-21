////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXaml.h"

UNoesisXaml::UNoesisXaml(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

Noesis::Ptr<Noesis::BaseComponent> UNoesisXaml::LoadXaml()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
		return nullptr;
	return Noesis::GUI::LoadXaml(TCHARToNsString(*GetPathName()).Str());
}

void UNoesisXaml::LoadComponent(Noesis::BaseComponent* Component)
{
	Noesis::GUI::LoadComponent(Component, TCHARToNsString(*GetPathName()).Str());
}

uint32 UNoesisXaml::GetContentHash() const
{
	return Noesis::HashBytes(XamlText.GetData(), XamlText.Num());
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

void UNoesisXaml::GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const
{
	if (AssetImportData)
	{
		OutTags.Add(FAssetRegistryTag(SourceFileTagName(), AssetImportData->GetSourceData().ToJson(), FAssetRegistryTag::TT_Hidden));
	}

	Super::GetAssetRegistryTags(OutTags);
}
#endif // WITH_EDITORONLY_DATA

void UNoesisXaml::PostLoad()
{
	Super::PostLoad();

	INoesisRuntimeModuleInterface& NoesisRuntime = INoesisRuntimeModuleInterface::Get();
	for (auto Font : Fonts)
	{
		NoesisRuntime.RegisterFont(Font);
	}
}

#if WITH_EDITOR
void UNoesisXaml::PreloadDependencies()
{
	{
		auto Linker = GetLinker();
		if (Linker)
		{
			Linker->Preload(this);
		}
	}

	for (auto Xaml : Xamls)
	{
		if (Xaml != this)
		{
			Xaml->PreloadDependencies();
		}
	}

	for (auto Texture : Textures)
	{
		auto Linker = Texture->GetLinker();
		if (Linker)
		{
			Linker->Preload(Texture);
		}
	}

	for (auto Font : Fonts)
	{
		auto Linker = Font->GetLinker();
		if (Linker)
		{
			Linker->Preload(Font);
		}
	}
}

bool UNoesisXaml::CanRenderThumbnail()
{
	if (!ThumbnailRenderInstance)
	{
		ThumbnailRenderInstance = NewObject<UNoesisInstance>();
		ThumbnailRenderInstance->BaseXaml = this;
		ThumbnailRenderInstance->InitInstance();
	}

	return ThumbnailRenderInstance->XamlView != nullptr;
}

void UNoesisXaml::RenderThumbnail(FIntRect ViewportRect, const FTexture2DRHIRef& BackBuffer)
{
	if (!ThumbnailRenderInstance)
	{
		ThumbnailRenderInstance = NewObject<UNoesisInstance>();
		ThumbnailRenderInstance->BaseXaml = this;
		ThumbnailRenderInstance->InitInstance();
	}

	if (ThumbnailRenderInstance)
	{
		ThumbnailRenderInstance->DrawThumbnail(ViewportRect, BackBuffer);
	}
}

void UNoesisXaml::DestroyThumbnailRenderData()
{
	if (ThumbnailRenderInstance)
	{
		ThumbnailRenderInstance->TermInstance();
		ThumbnailRenderInstance = nullptr;
	}
}
#endif
