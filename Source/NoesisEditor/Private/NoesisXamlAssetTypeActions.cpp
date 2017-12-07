////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXamlAssetTypeActions.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

FNoesisXamlAssetTypeActions::FNoesisXamlAssetTypeActions(EAssetTypeCategories::Type InCategories)
	: Categories(InCategories)
{
};

FText FNoesisXamlAssetTypeActions::GetName() const
{
	return LOCTEXT("NoesisXamlAssetTypeActions_Name", "Noesis XAML");
}

UClass* FNoesisXamlAssetTypeActions::GetSupportedClass() const
{
	return UNoesisXaml::StaticClass();
}

FColor FNoesisXamlAssetTypeActions::GetTypeColor() const
{
	return FColor(42, 166, 226);
}

uint32 FNoesisXamlAssetTypeActions::GetCategories()
{
	return Categories;
}

// This is copied from SAssetThumbnail::ShouldRender
static bool ShouldRender(const FAssetData& AssetData)
{
	// Never render a thumbnail for an invalid asset
	if (!AssetData.IsValid())
	{
		return false;
	}

	if (AssetData.IsAssetLoaded())
	{
		// Loaded asset, return true if there is a rendering info for it
		UObject* Asset = AssetData.GetAsset();
		FThumbnailRenderingInfo* RenderInfo = GUnrealEd->GetThumbnailManager()->GetRenderingInfo(Asset);
		if (RenderInfo != NULL && RenderInfo->Renderer != NULL)
		{
			return true;
		}
	}

	const FObjectThumbnail* CachedThumbnail = ThumbnailTools::FindCachedThumbnail(*AssetData.GetFullName());
	if (CachedThumbnail != NULL)
	{
		// There is a cached thumbnail for this asset, we should render it
		return !CachedThumbnail->IsEmpty();
	}

	if (AssetData.AssetClass != UBlueprint::StaticClass()->GetFName())
	{
		// If we are not a blueprint, see if the CDO of the asset's class has a rendering info
		// Blueprints can't do this because the rendering info is based on the generated class
		UClass* AssetClass = FindObject<UClass>(ANY_PACKAGE, *AssetData.AssetClass.ToString());

		if (AssetClass)
		{
			FThumbnailRenderingInfo* RenderInfo = GUnrealEd->GetThumbnailManager()->GetRenderingInfo(AssetClass->GetDefaultObject());
			if (RenderInfo != NULL && RenderInfo->Renderer != NULL)
			{
				return true;
			}
		}
	}

	// Unloaded blueprint or asset that may have a custom thumbnail, check to see if there is a thumbnail in the package to render
	FString PackageFilename;
	if (FPackageName::DoesPackageExist(AssetData.PackageName.ToString(), NULL, &PackageFilename))
	{
		TSet<FName> ObjectFullNames;
		FThumbnailMap ThumbnailMap;

		FName ObjectFullName = FName(*AssetData.GetFullName());
		ObjectFullNames.Add(ObjectFullName);

		ThumbnailTools::LoadThumbnailsFromPackage(PackageFilename, ObjectFullNames, ThumbnailMap);

		const FObjectThumbnail* ThumbnailPtr = ThumbnailMap.Find(ObjectFullName);
		if (ThumbnailPtr)
		{
			const FObjectThumbnail& ObjectThumbnail = *ThumbnailPtr;
			return ObjectThumbnail.GetImageWidth() > 0 && ObjectThumbnail.GetImageHeight() > 0 && ObjectThumbnail.GetUncompressedImageData().Num() > 0;
		}
	}

	return false;
}

TSharedPtr<SWidget> FNoesisXamlAssetTypeActions::GetThumbnailOverlay(const FAssetData& AssetData) const
{
	/*if (!ShouldRender(AssetData))
	{
		return nullptr;
	}*/
	
	const FSlateBrush* Icon = FSlateIconFinder::FindIconBrushForClass(UNoesisXaml::StaticClass());

	return SNew(SBorder)
		.BorderImage(FEditorStyle::GetNoBrush())
		.Visibility(EVisibility::HitTestInvisible)
		.Padding(FMargin(0.0f, 0.0f, 0.0f, 3.0f))
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
			SNew(SImage)
			.Image(Icon)
		];
}

#undef LOCTEXT_NAMESPACE
