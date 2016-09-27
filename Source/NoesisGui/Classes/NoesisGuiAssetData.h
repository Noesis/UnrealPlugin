////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// CoreUObject includes
#include "Object.h"

// Generated header include
#include "NoesisGuiAssetData.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiAssetData : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	FString XamlFilename;

	UPROPERTY()
	TMap<FString, int64> FileInfoMap;

	UPROPERTY()
	TArray<uint8> BulkData;
};
