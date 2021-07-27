////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// NoesisRuntime includes
#include "NoesisEnums.h"

// Noesis includes
#include "NoesisSDK.h"

// Generated header include
#include "NoesisStructs.generated.h"

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisSize
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float Width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float Height;

	FNoesisSize() : Width(0.f), Height(0.f) {}

	FNoesisSize(const Noesis::Size& Size);

	Noesis::Size ToNoesis() const;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisCornerRadius
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float TopLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float TopRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float BottomRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float BottomLeft;

	FNoesisCornerRadius() : TopLeft(0.f), TopRight(0.f), BottomRight(0.f), BottomLeft(0.f) {}

	FNoesisCornerRadius(const Noesis::CornerRadius& CornerRadius);
	
	Noesis::CornerRadius ToNoesis() const;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisThickness
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float Left;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float Top;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float Right;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	float Bottom;

	FNoesisThickness() : Left(0.f), Top(0.f), Right(0.f), Bottom(0.f) {}

	FNoesisThickness(const Noesis::Thickness& Thickness);
	
	Noesis::Thickness ToNoesis() const;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisDuration
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	ENoesisDurationType DurationType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoesisGUI")
	int32 Milliseconds;

	FNoesisDuration() : DurationType(ENoesisDurationType::Automatic), Milliseconds(0) {}

	FNoesisDuration(const Noesis::Duration& Duration);

	Noesis::Duration ToNoesis() const;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisKeyTime
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	FString TextForm;

	FNoesisKeyTime() {}

	FNoesisKeyTime(const Noesis::KeyTime& KeyTime);

	Noesis::KeyTime ToNoesis() const;
};
