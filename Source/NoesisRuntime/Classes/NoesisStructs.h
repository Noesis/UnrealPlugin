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

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Height;

	FNoesisSize() {}

	FNoesisSize(const Noesis::Size& Size);

	Noesis::Size ToNoesis() const;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisRect
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Y;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Height;

	FNoesisRect() {}

	FNoesisRect(const Noesis::Rect& Rect);

	Noesis::Rect ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisPoint
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Y;

	FNoesisPoint() {}

	FNoesisPoint(const Noesis::Point& Point);
	
	Noesis::Point ToNoesis() const;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisCornerRadius
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float TopLeft;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float TopRight;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float BottomRight;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float BottomLeft;

	FNoesisCornerRadius() {}

	FNoesisCornerRadius(const Noesis::CornerRadius& CornerRadius);
	
	Noesis::CornerRadius ToNoesis() const;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisThickness
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Left;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Top;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Right;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Bottom;

	FNoesisThickness() {}

	FNoesisThickness(const Noesis::Thickness& Thickness);
	
	Noesis::Thickness ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisColor
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Red;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Green;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Blue;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Alpha;

	FNoesisColor() {}

	FNoesisColor(const Noesis::Color& Color);
	
	Noesis::Color ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisSizei
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Height;

	FNoesisSizei() {}

	FNoesisSizei(const Noesis::Sizei& Size);

	Noesis::Sizei ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisRecti
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Y;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Height;

	FNoesisRecti() {}

	FNoesisRecti(const Noesis::Recti& Rect);

	Noesis::Recti ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisPointi
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Y;

	FNoesisPointi() {}

	FNoesisPointi(const Noesis::Pointi& Point);
	
	Noesis::Pointi ToNoesis() const;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisDuration
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	ENoesisDurationType DurationType;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Milliseconds;

	FNoesisDuration() {}

	FNoesisDuration(const Noesis::Duration& Duration);

	Noesis::Duration ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisRepeatBehavior
{
	GENERATED_USTRUCT_BODY();

	FNoesisRepeatBehavior() {}

	FNoesisRepeatBehavior(const Noesis::RepeatBehavior& RepeatBehavior);

	Noesis::RepeatBehavior ToNoesis();

private:

	FString TextForm;
};

USTRUCT(BlueprintType)
struct FNoesisGridLength
{
	GENERATED_USTRUCT_BODY();

	FNoesisGridLength() {}

	FNoesisGridLength(const Noesis::GridLength& GridLength);

	Noesis::GridLength ToNoesis();

private:

	FString TextForm;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisKeyTime
{
	GENERATED_USTRUCT_BODY();

	FNoesisKeyTime() {}

	FNoesisKeyTime(const Noesis::KeyTime& KeyTime);

	Noesis::KeyTime ToNoesis() const;

private:

	FString TextForm;
};

USTRUCT(BlueprintType, Category = "NoesisGUI")
struct FNoesisTimeSpan
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Days;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Hours;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Minutes;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Seconds;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Milliseconds;

	FNoesisTimeSpan() {}

	FNoesisTimeSpan(const Noesis::TimeSpan& TimeSpan);

	Noesis::TimeSpan ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisManipulationDelta
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	FNoesisPoint Expansion;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Rotation;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float Scale;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	FNoesisPoint Translation;

	FNoesisManipulationDelta() {}

	FNoesisManipulationDelta(const Noesis::ManipulationDelta& ManipulationDelta);

	Noesis::ManipulationDelta ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisManipulationVelocities
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float AngularVelocity;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	FNoesisPoint ExpansionVelocity;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	FNoesisPoint LinearVelocity;

	FNoesisManipulationVelocities() {}

	FNoesisManipulationVelocities(const Noesis::ManipulationVelocities& ManipulationVelocities);

	Noesis::ManipulationVelocities ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisInertiaExpansionBehavior
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float DesiredDeceleration;

	FNoesisInertiaExpansionBehavior() {}

	FNoesisInertiaExpansionBehavior(const Noesis::InertiaExpansionBehavior& InertiaExpansionBehavior);

	Noesis::InertiaExpansionBehavior ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisInertiaRotationBehavior
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float DesiredDeceleration;

	FNoesisInertiaRotationBehavior() {}

	FNoesisInertiaRotationBehavior(const Noesis::InertiaRotationBehavior& InertiaRotationBehavior);

	Noesis::InertiaRotationBehavior ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisInertiaTranslationBehavior
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	float DesiredDeceleration;

	FNoesisInertiaTranslationBehavior() {}

	FNoesisInertiaTranslationBehavior(const Noesis::InertiaTranslationBehavior& InertiaTranslationBehavior);

	Noesis::InertiaTranslationBehavior ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGeneratorPosition
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Index;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGUI")
	int32 Offset;

	FNoesisGeneratorPosition() {}

	FNoesisGeneratorPosition(const Noesis::GeneratorPosition& GeneratorPosition);

	Noesis::GeneratorPosition ToNoesis() const;
};

