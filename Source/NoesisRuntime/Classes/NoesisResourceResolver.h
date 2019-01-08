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
#include "NoesisResourceResolver.generated.h"

UENUM()
enum class ENoesisResourceType : uint8
{
	NRT_Unknown = 0,
	NRT_FontFace,
	NRT_Font,
	NRT_Texture,
	NRT_Xaml
};

UCLASS(BlueprintType, Blueprintable)
class NOESISRUNTIME_API UNoesisResourceResolver : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual FString ResolveName(const FString& Name, const ENoesisResourceType ResourceType = ENoesisResourceType::NRT_Unknown) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual FString ResolvePath(const FString& Path, const ENoesisResourceType ResourceType = ENoesisResourceType::NRT_Unknown) const;
};
