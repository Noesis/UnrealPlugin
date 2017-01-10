////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.generated.h"

USTRUCT(BlueprintType)
struct FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisBaseComponent* Source;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisRoutedEvent* RoutedEvent;

	FNoesisRoutedEventArgs() {}

	FNoesisRoutedEventArgs(class UNoesisInstance* Instance, const Noesis::RoutedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisMouseEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint Position;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisMouseButtonState LeftButton;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisMouseButtonState MiddleButton;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisMouseButtonState RightButton;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisMouseButtonState XButton1Button;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisMouseButtonState XButton2Button;

	FNoesisMouseEventArgs() {}

	FNoesisMouseEventArgs(class UNoesisInstance* Instance, const Noesis::MouseEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisMouseButtonEventArgs : public FNoesisMouseEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisMouseButton ChangedButton;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisMouseButtonState ButtonState;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 ButtonClicks;

	FNoesisMouseButtonEventArgs() {}

	FNoesisMouseButtonEventArgs(class UNoesisInstance* Instance, const Noesis::MouseButtonEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisMouseWheelEventArgs : public FNoesisMouseEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 WheelRotation;

	FNoesisMouseWheelEventArgs() {}

	FNoesisMouseWheelEventArgs(class UNoesisInstance* Instance, const Noesis::MouseWheelEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisTouchEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint TouchPoint;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 TouchDevice;

	FNoesisTouchEventArgs() {}

	FNoesisTouchEventArgs(class UNoesisInstance* Instance, const Noesis::TouchEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisDragCompletedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool Canceled;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float HorizontalChange;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float VerticalChange;

	FNoesisDragCompletedEventArgs() {}

	FNoesisDragCompletedEventArgs(class UNoesisInstance* Instance, const Noesis::DragCompletedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisDragStartedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float HorizontalOffset;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float VerticalOffset;

	FNoesisDragStartedEventArgs() {}

	FNoesisDragStartedEventArgs(class UNoesisInstance* Instance, const Noesis::DragStartedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisSelectionChangedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	TArray<class UNoesisBaseComponent*> AddedItems;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	TArray<class UNoesisBaseComponent*> RemovedItems;

	FNoesisSelectionChangedEventArgs(){}

	FNoesisSelectionChangedEventArgs(class UNoesisInstance* Instance, const Noesis::SelectionChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisSizeChangedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingSize NewSize;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingSize PreviousSize;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool WidthChanged;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool HeightChanged;

	FNoesisSizeChangedEventArgs(){}

	FNoesisSizeChangedEventArgs(class UNoesisInstance* Instance, const Noesis::SizeChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisKeyboardFocusChangedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisUIElement* OldFocus;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisUIElement* NewFocus;

	FNoesisKeyboardFocusChangedEventArgs() {}

	FNoesisKeyboardFocusChangedEventArgs(class UNoesisInstance* Instance, const Noesis::KeyboardFocusChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisScrollEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float NewValue;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisScrollEventType ScrollEventType;

	FNoesisScrollEventArgs() {}

	FNoesisScrollEventArgs(class UNoesisInstance* Instance, const Noesis::ScrollEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisTextCompositionEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Character;

	FNoesisTextCompositionEventArgs() {}

	FNoesisTextCompositionEventArgs(class UNoesisInstance* Instance, const Noesis::TextCompositionEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisContextMenuEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisUIElement* Owner;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float CursorLeft;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float CursorTop;

	FNoesisContextMenuEventArgs() {}

	FNoesisContextMenuEventArgs(class UNoesisInstance* Instance, const Noesis::ContextMenuEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisKeyEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisKey Key;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 KeyStates;

	FNoesisKeyEventArgs() {}

	FNoesisKeyEventArgs(class UNoesisInstance* Instance, const Noesis::KeyEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisManipulationStartingEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	class UNoesisVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	ENoesisManipulationModes Mode;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	FNoesisManipulationStartingEventArgs() {}

	FNoesisManipulationStartingEventArgs(class UNoesisInstance* Instance, const Noesis::ManipulationStartingEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationStartingEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisManipulationStartedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint ManipulationOrigin;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Complete;

	FNoesisManipulationStartedEventArgs() {}

	FNoesisManipulationStartedEventArgs(class UNoesisInstance* Instance, const Noesis::ManipulationStartedEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationStartedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisManipulationDeltaEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint ManipulationOrigin;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisManipulationDelta DeltaManipulation;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisManipulationDelta CumulativeManipulation;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisManipulationVelocities Velocities;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool IsInertial;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Complete;

	FNoesisManipulationDeltaEventArgs() {}

	FNoesisManipulationDeltaEventArgs(class UNoesisInstance* Instance, const Noesis::ManipulationDeltaEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationDeltaEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisManipulationInertiaStartingEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint ManipulationOrigin;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	FNoesisManipulationVelocities InitialVelocities;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	FNoesisInertiaRotationBehavior RotationBehavior;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	FNoesisInertiaExpansionBehavior ExpansionBehavior;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	FNoesisInertiaTranslationBehavior TranslationBehavior;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	FNoesisManipulationInertiaStartingEventArgs() {}

	FNoesisManipulationInertiaStartingEventArgs(class UNoesisInstance* Instance, const Noesis::ManipulationInertiaStartingEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationInertiaStartingEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisManipulationCompletedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingPoint ManipulationOrigin;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisManipulationVelocities FinalVelocities;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisManipulationDelta TotalManipulation;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool IsInertial;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	FNoesisManipulationCompletedEventArgs() {}

	FNoesisManipulationCompletedEventArgs(class UNoesisInstance* Instance, const Noesis::ManipulationCompletedEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationCompletedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisScrollChangedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float ExtentHeight;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float ExtentHeightChange;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float ExtentWidth;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float ExtentWidthChange;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float HorizontalChange;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float HorizontalOffset;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float VerticalChange;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float VerticalOffset;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float ViewportHeight;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float ViewportHeightChange;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float ViewportWidth;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float ViewportWidthChange;

	FNoesisScrollChangedEventArgs() {}

	FNoesisScrollChangedEventArgs(class UNoesisInstance* Instance, const Noesis::ScrollChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisToolTipEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	FNoesisToolTipEventArgs() {}

	FNoesisToolTipEventArgs(class UNoesisInstance* Instance, const Noesis::ToolTipEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisDragDeltaEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float HorizontalChange;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float VerticalChange;

	FNoesisDragDeltaEventArgs() {}

	FNoesisDragDeltaEventArgs(class UNoesisInstance* Instance, const Noesis::DragDeltaEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisFloatPropertyChangedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float OldValue;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float NewValue;

	FNoesisFloatPropertyChangedEventArgs() {}

	FNoesisFloatPropertyChangedEventArgs(class UNoesisInstance* Instance, const Noesis::RoutedPropertyChangedEventArgs<NsFloat32>& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisBaseComponentPropertyChangedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisBaseComponent* OldValue;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisBaseComponent* NewValue;

	FNoesisBaseComponentPropertyChangedEventArgs() {}

	FNoesisBaseComponentPropertyChangedEventArgs(class UNoesisInstance* Instance, const Noesis::RoutedPropertyChangedEventArgs<Noesis::Ptr<Noesis::BaseComponent> >& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisCanExecuteRoutedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	const class UNoesisICommand* Command;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisBaseComponent* Parameter;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool CanExecute;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool ContinueRouting;

	FNoesisCanExecuteRoutedEventArgs() {}

	FNoesisCanExecuteRoutedEventArgs(class UNoesisInstance* Instance, const Noesis::CanExecuteRoutedEventArgs& InArgs);

	void ToNoesis(const Noesis::CanExecuteRoutedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisExecutedRoutedEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	const class UNoesisICommand* Command;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisBaseComponent* Parameter;

	FNoesisExecutedRoutedEventArgs() {}

	FNoesisExecutedRoutedEventArgs(class UNoesisInstance* Instance, const Noesis::ExecutedRoutedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisRequestBringIntoViewEventArgs : public FNoesisRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	const class UNoesisDependencyObject* TargetObject;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisDrawingRect TargetRect;

	FNoesisRequestBringIntoViewEventArgs() {}

	FNoesisRequestBringIntoViewEventArgs(class UNoesisInstance* Instance, const Noesis::RequestBringIntoViewEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisEventArgs
{
	GENERATED_USTRUCT_BODY()

	FNoesisEventArgs() {}

	FNoesisEventArgs(class UNoesisInstance* Instance, const Noesis::EventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisTimelineEventArgs : public FNoesisEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	const class UNoesisDependencyObject* Target;

	FNoesisTimelineEventArgs() {}

	FNoesisTimelineEventArgs(class UNoesisInstance* Instance, const Noesis::TimelineEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisItemsChangedEventArgs : public FNoesisEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisNotifyCollectionChangedAction Action;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGeneratorPosition Position;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGeneratorPosition OldPosition;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 ItemCount;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 ItemUICount;

	FNoesisItemsChangedEventArgs() {}

	FNoesisItemsChangedEventArgs(class UNoesisInstance* Instance, const Noesis::ItemsChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisDependencyPropertyChangedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	const class UNoesisDependencyProperty* Prop;

	FNoesisDependencyPropertyChangedEventArgs() {}

	FNoesisDependencyPropertyChangedEventArgs(class UNoesisInstance* Instance, const Noesis::DependencyPropertyChangedEventArgs& InArgs);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisRoutedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisRoutedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisMouseEventHandler, class UNoesisBaseComponent*, Sender, FNoesisMouseEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisMouseButtonEventHandler, class UNoesisBaseComponent*, Sender, FNoesisMouseButtonEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisMouseWheelEventHandler, class UNoesisBaseComponent*, Sender, FNoesisMouseWheelEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisTouchEventHandler, class UNoesisBaseComponent*, Sender, FNoesisTouchEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisDragCompletedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisDragCompletedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisDragStartedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisDragStartedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisSizeChangedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisSizeChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisSelectionChangedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisSelectionChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisKeyboardFocusChangedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisKeyboardFocusChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisScrollEventHandler, class UNoesisBaseComponent*, Sender, FNoesisScrollEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisTextCompositionEventHandler, class UNoesisBaseComponent*, Sender, FNoesisTextCompositionEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisContextMenuEventHandler, class UNoesisBaseComponent*, Sender, FNoesisContextMenuEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisKeyEventHandler, class UNoesisBaseComponent*, Sender, FNoesisKeyEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisManipulationStartingEventHandler, class UNoesisBaseComponent*, Sender, FNoesisManipulationStartingEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisManipulationStartedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisManipulationStartedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisManipulationDeltaEventHandler, class UNoesisBaseComponent*, Sender, FNoesisManipulationDeltaEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisManipulationInertiaStartingEventHandler, class UNoesisBaseComponent*, Sender, FNoesisManipulationInertiaStartingEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisManipulationCompletedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisManipulationCompletedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisScrollChangedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisScrollChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisToolTipEventHandler, class UNoesisBaseComponent*, Sender, FNoesisToolTipEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisDragDeltaEventHandler, class UNoesisBaseComponent*, Sender, FNoesisDragDeltaEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisFloatPropertyChangedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisFloatPropertyChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisBaseComponentPropertyChangedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisBaseComponentPropertyChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisCanExecuteRoutedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisCanExecuteRoutedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisExecutedRoutedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisExecutedRoutedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisRequestBringIntoViewEventHandler, class UNoesisBaseComponent*, Sender, FNoesisRequestBringIntoViewEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisEventHandler, class UNoesisBaseComponent*, Sender, FNoesisEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisTimelineEventHandler, class UNoesisBaseComponent*, Sender, FNoesisTimelineEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisItemsChangedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisItemsChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisDependencyPropertyChangedEventHandler, class UNoesisBaseComponent*, Sender, FNoesisDependencyPropertyChangedEventArgs, Args);
