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

// NoesisRuntime includes
#include "NoesisThumbnailRenderer.h"

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

	UPROPERTY(Meta = (DeprecatedProperty))
	TArray<TObjectPtr<UNoesisXaml>> Xamls_DEPRECATED;

	UPROPERTY(Meta = (DeprecatedProperty))
	TArray<TObjectPtr<class UTexture2D>> Textures_DEPRECATED;

	UPROPERTY(Meta = (DeprecatedProperty))
	TArray<TObjectPtr<class UFont>> Fonts_DEPRECATED;

	UPROPERTY(Meta = (DeprecatedProperty))
	TArray<TObjectPtr<class UFontFace>> FontFaces_DEPRECATED;

	UPROPERTY(Meta = (DeprecatedProperty))
	TArray<TObjectPtr<class USoundWave>> Sounds_DEPRECATED;

	UPROPERTY(Meta = (DeprecatedProperty))
	TArray<TObjectPtr<class UMediaSource>> Videos_DEPRECATED;

	UPROPERTY(Meta = (DeprecatedProperty))
	TArray<TObjectPtr<class UNoesisRive>> Rives_DEPRECATED;

	UPROPERTY(Meta = (DeprecatedProperty))
	TArray<TObjectPtr<class UMaterialInterface>> Materials_DEPRECATED;

	UPROPERTY()
	TArray<TObjectPtr<UObject>> Dependencies;

	UPROPERTY()
	TArray<FText> Texts;

	Noesis::Ptr<Noesis::BaseComponent> LoadXaml();
	void LoadComponent(Noesis::BaseComponent* Component);
	uint32 GetContentHash() const;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Instanced, Category=ImportSettings)
	TObjectPtr<class UAssetImportData> AssetImportData;

	// UObject interface
	virtual void PostLoad();
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
	void RenderThumbnail(FIntRect, const FTextureRHIRef&);
	void DestroyThumbnailRenderData();
#endif

#if WITH_EDITORONLY_DATA
	FNoesisThumbnailRenderer ThumbnailRenderer;
#endif
};
