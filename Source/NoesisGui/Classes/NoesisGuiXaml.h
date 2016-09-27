////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Generated header include
#include "NoesisGuiXaml.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiXaml : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	TArray<uint8> XamlText;

	UPROPERTY()
	TMap<FString, UNoesisGuiXaml*> XamlMap;

	UPROPERTY()
	TMap<FString, UTexture2D*> TextureMap;

	UPROPERTY()
	TMap<FString, UFont*> FontMap;

	UPROPERTY()
	TArray<class UNoesisGuiBaseComponent*> Components;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	class UAssetImportData* AssetImportData;
#endif
};
