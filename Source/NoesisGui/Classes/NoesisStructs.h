////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.generated.h"

USTRUCT(BlueprintType)
struct FNoesisObjectWithNameScope
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisBaseComponent* Object;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisINameScope* Scope;

	FNoesisObjectWithNameScope() {}

	FNoesisObjectWithNameScope(class UNoesisInstance* Instance, const Noesis::Gui::ObjectWithNameScope& ObjectWithScope);
};

USTRUCT(BlueprintType)
struct FNoesisDrawingSize
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Height;

	FNoesisDrawingSize() {}

	FNoesisDrawingSize(const Noesis::Drawing::Size& Size);

	Noesis::Drawing::Size ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisDrawingRect
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Y;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Height;

	FNoesisDrawingRect() {}

	FNoesisDrawingRect(const Noesis::Drawing::Rect& Rect);

	Noesis::Drawing::Rect ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisDrawingPoint
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Y;

	FNoesisDrawingPoint() {}

	FNoesisDrawingPoint(const Noesis::Drawing::Point& Point);
	
	Noesis::Drawing::Point ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisDrawingCornerRadius
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float TopLeft;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float TopRight;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float BottomRight;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float BottomLeft;

	FNoesisDrawingCornerRadius() {}

	FNoesisDrawingCornerRadius(const Noesis::Drawing::CornerRadius& CornerRadius);
	
	Noesis::Drawing::CornerRadius ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisDrawingThickness
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Left;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Top;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Right;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Bottom;

	FNoesisDrawingThickness() {}

	FNoesisDrawingThickness(const Noesis::Drawing::Thickness& Thickness);
	
	Noesis::Drawing::Thickness ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisDrawingColor
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Red;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Green;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Blue;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Alpha;

	FNoesisDrawingColor() {}

	FNoesisDrawingColor(const Noesis::Drawing::Color& Color);
	
	Noesis::Drawing::Color ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisDrawingSizei
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Height;

	FNoesisDrawingSizei() {}

	FNoesisDrawingSizei(const Noesis::Drawing::Sizei& Size);

	Noesis::Drawing::Sizei ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisDrawingRecti
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Y;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Height;

	FNoesisDrawingRecti() {}

	FNoesisDrawingRecti(const Noesis::Drawing::Recti& Rect);

	Noesis::Drawing::Recti ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisDrawingPointi
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Y;

	FNoesisDrawingPointi() {}

	FNoesisDrawingPointi(const Noesis::Drawing::Pointi& Point);
	
	Noesis::Drawing::Pointi ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisDuration
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisDurationType DurationType;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Milliseconds;

	FNoesisDuration() {}

	FNoesisDuration(const Noesis::Gui::Duration& Duration);

	Noesis::Gui::Duration ToNoesis() const;
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

USTRUCT(BlueprintType)
struct FNoesisKeyTime
{
	GENERATED_USTRUCT_BODY();

	FNoesisKeyTime() {}

	FNoesisKeyTime(const Noesis::KeyTime& KeyTime);

	Noesis::KeyTime ToNoesis();

private:

	FString TextForm;
};

USTRUCT(BlueprintType)
struct FNoesisManipulationDelta
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint Expansion;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Rotation;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Scale;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint Translation;

	FNoesisManipulationDelta() {}

	FNoesisManipulationDelta(const Noesis::Gui::ManipulationDelta& ManipulationDelta);

	Noesis::Gui::ManipulationDelta ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisManipulationVelocities
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float AngularVelocity;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint ExpansionVelocity;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint LinearVelocity;

	FNoesisManipulationVelocities() {}

	FNoesisManipulationVelocities(const Noesis::Gui::ManipulationVelocities& ManipulationVelocities);

	Noesis::Gui::ManipulationVelocities ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisInertiaExpansionBehavior
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float DesiredDeceleration;

	FNoesisInertiaExpansionBehavior() {}

	FNoesisInertiaExpansionBehavior(const Noesis::Gui::InertiaExpansionBehavior& InertiaExpansionBehavior);

	Noesis::Gui::InertiaExpansionBehavior ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisInertiaRotationBehavior
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float DesiredDeceleration;

	FNoesisInertiaRotationBehavior() {}

	FNoesisInertiaRotationBehavior(const Noesis::Gui::InertiaRotationBehavior& InertiaRotationBehavior);

	Noesis::Gui::InertiaRotationBehavior ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisInertiaTranslationBehavior
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float DesiredDeceleration;

	FNoesisInertiaTranslationBehavior() {}

	FNoesisInertiaTranslationBehavior(const Noesis::Gui::InertiaTranslationBehavior& InertiaTranslationBehavior);

	Noesis::Gui::InertiaTranslationBehavior ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGeneratorPosition
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Index;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Offset;

	FNoesisGeneratorPosition() {}

	FNoesisGeneratorPosition(const Noesis::Gui::GeneratorPosition& GeneratorPosition);

	Noesis::Gui::GeneratorPosition ToNoesis() const;
};

