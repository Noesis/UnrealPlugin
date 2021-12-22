////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// AssetTools includes
#include "AssetTypeActions_Base.h"

class FNoesisXamlAssetTypeActions : public FAssetTypeActions_Base
{
public:
	FNoesisXamlAssetTypeActions(EAssetTypeCategories::Type Categories);

	// IAssetTypeActions interface
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override;
	virtual void GetActions(const TArray<UObject*>& InObjects, struct FToolMenuSection& Section);
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual void GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const override;
	virtual TSharedPtr<class SWidget> GetThumbnailOverlay(const FAssetData& AssetData) const override;
	virtual bool IsImportedAsset() const override { return true; }
	// End of IAssetTypeActions interface

private:
	void AddToViewport(TArray<TWeakObjectPtr<class UNoesisXaml>> Objects);

	EAssetTypeCategories::Type Categories;
};
