////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

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

	Noesis::Ptr<Noesis::BaseComponent> LoadXaml();
	void LoadComponent(Noesis::BaseComponent* Component);
	uint32 GetContentHash() const;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Instanced, Category=ImportSettings)
	class UAssetImportData* AssetImportData;

	// UObject interface
	virtual void PostInitProperties() override;
	virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;
	// End of UObject interface
#endif

	void RegisterDependencies();

#if WITH_EDITOR
	bool CanRenderThumbnail();
	void RenderThumbnail(FIntRect, const FTexture2DRHIRef&);
	void DestroyThumbnailRenderData();
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	class UNoesisInstance* ThumbnailRenderInstance;
#endif
};
