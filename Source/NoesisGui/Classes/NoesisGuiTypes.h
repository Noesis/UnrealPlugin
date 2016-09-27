////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ObjectBase.h"
#include "NoesisGuiTypes.generated.h"

UENUM()
enum ENoesisGuiHandoffBehavior
{
	HB_SnapshotAndReplace,
	HB_Compose,
	HB_MAX
};

UENUM()
enum ENoesisGuiBindingMode
{
	BM_Default,
	BM_TwoWay,
	BM_OneWay,
	BM_OneTime,
	BM_OneWayToSource,
	BM_MAX
};

UENUM()
enum ENoesisGuiUpdateSourceTrigger
{
	UST_Default,
	UST_PropertyChanged,
	UST_LostFocus,
	UST_Explicit,
	UST_MAX
};

UENUM()
enum ENoesisGuiGeneratorStatus
{
	GS_NotStarted,
	GS_GeneratingContainers,
	GS_ContainersGenerated,
	GS_Error,
	GS_MAX
};

UENUM()
enum ENoesisGuiRelativeSourceMode
{
	RSM_PreviousData,
	RSM_TemplatedParent,
	RSM_Self,
	RSM_FindAncestor,
	RSM_MAX
};

UENUM()
enum ENoesisGuiRoutingStrategy
{
	RS_Bubbling,
	RS_Tunneling,
	RS_Direct,
	RS_MAX
};

UENUM()
enum ENoesisGuiDurationType
{
	DT_Automatic,
	DT_TimeSpan,
	DT_Forever,
	DT_MAX
};

UENUM()
enum ENoesisGuiMouseButton
{
	MB_Left,
	MB_Right,
	MB_Middle,
	MB_XButton1,
	MB_XButton2,
	MB_MAX
};

UENUM()
enum ENoesisGuiMouseButtonState
{
	MBS_Pressed,
	MBS_Released,
	MBS_MAX
};

USTRUCT(BlueprintType)
struct FNoesisGuiDrawingSize
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	float Width;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	float Height;

	FNoesisGuiDrawingSize() {}

	FNoesisGuiDrawingSize(float InWidth, float InHeight)
		: Width(InWidth), Height(InHeight)
	{
	}
};

USTRUCT(BlueprintType)
struct FNoesisGuiDrawingRect
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	float X;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	float Y;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	float Width;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	float Height;

	FNoesisGuiDrawingRect() {}

	FNoesisGuiDrawingRect(float InX, float InY, float InWidth, float InHeight)
		: X(InX), Y(InY), Width(InWidth), Height(InHeight)
	{
	}
};

USTRUCT(BlueprintType)
struct FNoesisGuiDrawingPoint
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	float X;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	float Y;

	FNoesisGuiDrawingPoint() {}

	FNoesisGuiDrawingPoint(float InX, float InY)
		: X(InX), Y(InY)
	{
	}
};

USTRUCT(BlueprintType)
struct FNoesisGuiDuration
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	TEnumAsByte<ENoesisGuiDurationType> DurationType;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	int32 Milliseconds;

	FNoesisGuiDuration() {}

	FNoesisGuiDuration(ENoesisGuiDurationType InDurationType, int32 InMilliseconds)
		: DurationType(InDurationType), Milliseconds(InMilliseconds)
	{
	}
};

USTRUCT(BlueprintType)
struct FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* Source;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	class UNoesisGuiRoutedEvent* RoutedEvent;
};

USTRUCT(BlueprintType)
struct FNoesisGuiMouseEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	FNoesisGuiDrawingPoint Position;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	TEnumAsByte<ENoesisGuiMouseButtonState> LeftButton;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	TEnumAsByte<ENoesisGuiMouseButtonState> MiddleButton;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	TEnumAsByte<ENoesisGuiMouseButtonState> RightButton;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	TEnumAsByte<ENoesisGuiMouseButtonState> XButton1Button;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	TEnumAsByte<ENoesisGuiMouseButtonState> XButton2Button;
};

USTRUCT(BlueprintType)
struct FNoesisGuiMouseButtonEventArgs : public FNoesisGuiMouseEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	TEnumAsByte<ENoesisGuiMouseButton> ChangedButton;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	TEnumAsByte<ENoesisGuiMouseButtonState> ButtonState;

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	int32 ButtonClicks;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiRoutedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiRoutedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiMouseButtonEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiMouseButtonEventArgs, Args);
