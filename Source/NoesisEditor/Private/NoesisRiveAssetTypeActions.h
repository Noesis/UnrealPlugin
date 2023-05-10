////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// AssetTools includes
#include "AssetTypeActions_Base.h"

class FNoesisRiveAssetTypeActions : public FAssetTypeActions_Base
{
public:
	FNoesisRiveAssetTypeActions(EAssetTypeCategories::Type Categories);

	// IAssetTypeActions interface
	virtual UClass* GetSupportedClass() const override;
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual bool IsImportedAsset() const override;
	virtual void GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const override;
	// End of IAssetTypeActions interface

private:
	EAssetTypeCategories::Type Categories;
};
