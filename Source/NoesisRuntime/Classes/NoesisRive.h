////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"

// Noesis includes
#include "NoesisSDK.h"

// RHI includes
#include "RHI.h"
#include "RHIResources.h"

// Generated header include
#include "NoesisRive.generated.h"

UCLASS(BlueprintType)
class NOESISRUNTIME_API UNoesisRive : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	TArray<uint8> Content;

	UPROPERTY()
	TArray<class UTexture2D*> Textures;

	UPROPERTY()
	TArray<class UFontFace*> FontFaces;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Instanced, Category = ImportSettings)
	class UAssetImportData* AssetImportData;

	// UObject interface
	virtual void PostInitProperties() override;
#if UE_VERSION_OLDER_THAN(5, 4, 0)
	virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;
#else
	virtual void GetAssetRegistryTags(FAssetRegistryTagsContext Context) const override;
#endif
	// End of UObject interface
#endif

#if WITH_EDITOR
	void RenderThumbnail(FIntRect ViewportRect, const FTexture2DRHIRef& BackBuffer);
	void DestroyThumbnailRenderData();
#endif

#if WITH_EDITORONLY_DATA
	Noesis::Ptr<Noesis::IView> ThumbnailView;
#endif
};
