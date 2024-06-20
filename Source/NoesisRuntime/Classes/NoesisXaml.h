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
#include "NoesisXaml.generated.h"

UCLASS(BlueprintType)
class NOESISRUNTIME_API UNoesisXaml : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	TArray<uint8> XamlText;

	UPROPERTY()
	TArray<UNoesisXaml*> Xamls;

	UPROPERTY()
	TArray<class UTexture2D*> Textures;

	UPROPERTY()
	TArray<class UFont*> Fonts;

	UPROPERTY()
	TArray<class UFontFace*> FontFaces;

	UPROPERTY()
	TArray<class USoundWave*> Sounds;

	UPROPERTY()
	TArray<class UMediaSource*> Videos;

	UPROPERTY()
	TArray<class UNoesisRive*> Rives;

	UPROPERTY()
	TArray<class UMaterialInterface*> Materials;

	UPROPERTY()
	TArray<FText> Texts;

	Noesis::Ptr<Noesis::BaseComponent> LoadXaml();
	void LoadComponent(Noesis::BaseComponent* Component);
	uint32 GetContentHash() const;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Instanced, Category=ImportSettings)
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

	void RegisterDependencies();
	FString GetXamlUri() const;

#if WITH_EDITOR
	void RenderThumbnail(FIntRect, const FTexture2DRHIRef&);
	void DestroyThumbnailRenderData();
#endif

#if WITH_EDITORONLY_DATA
	Noesis::Ptr<Noesis::IView> ThumbnailView;
#endif
};
