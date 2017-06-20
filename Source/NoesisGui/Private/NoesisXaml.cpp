////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXaml.h"

UNoesisXaml::UNoesisXaml(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
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

	for (auto XamlIter : XamlMap)
	{
		auto Xaml = XamlIter.Value;
		if (Xaml != this)
		{
			Xaml->PreloadDependencies();
		}
	}

	for (auto TextureIter : TextureMap)
	{
		auto Texture = TextureIter.Value;
		auto Linker = Texture->GetLinker();
		if (Linker)
		{
			Linker->Preload(Texture);
		}
	}

	for (auto FontIter : FontMap)
	{
		auto Font = FontIter.Value;
		auto Linker = Font->GetLinker();
		if (Linker)
		{
			Linker->Preload(Font);
		}
	}
}
#endif
