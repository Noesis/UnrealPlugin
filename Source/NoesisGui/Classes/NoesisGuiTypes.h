////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ObjectBase.h"
#include "NoesisGuiTypes.generated.h"

UENUM()
enum class ENoesisGuiHandoffBehavior : uint8
{
	SnapshotAndReplace,
	Compose
};

UENUM()
enum class ENoesisGuiBindingMode : uint8
{
	Default,
	TwoWay,
	OneWay,
	OneTime,
	OneWayToSource
};

UENUM()
enum class ENoesisGuiUpdateSourceTrigger : uint8
{
	Default,
	PropertyChanged,
	LostFocus,
	Explicit
};

UENUM()
enum class ENoesisGuiGeneratorStatus : uint8
{
	NotStarted,
	GeneratingContainers,
	ContainersGenerated,
	Error
};

UENUM()
enum class ENoesisGuiRelativeSourceMode : uint8
{
	PreviousData,
	TemplatedParent,
	Self,
	FindAncestor
};

UENUM()
enum class ENoesisGuiRoutingStrategy : uint8
{
	Bubbling,
	Tunneling,
	Direct
};

UENUM()
enum class ENoesisGuiDurationType : uint8
{
	Automatic,
	TimeSpan,
	Forever
};

UENUM()
enum class ENoesisGuiMouseButton : uint8
{
	Left,
	Right,
	Middle,
	XButton1,
	XButton2
};

UENUM()
enum class ENoesisGuiMouseButtonState : uint8
{
	Pressed,
	Released
};

UENUM()
enum class ENoesisGuiScrollEventType : uint8
{
	EndScroll,
	First,
	LargeDecrement,
	LargeIncrement,
	Last,
	SmallDecrement,
	SmallIncrement,
	ThumbPosition,
	ThumbTrack
};

UENUM()
enum class ENoesisGuiKey : uint8
{
	None,
	Back,
	Tab,
	Clear,
	Return,
	Pause,
	Shift,
	Control,
	Alt,
	Escape,
	Space,
	Prior,
	Next,
	End,
	Home,
	Left,
	Up,
	Right,
	Down,
	Select,
	Print,
	Execute,
	SnapShot,
	Insert,
	Delete,
	Help,
	Num0,
	Num1,
	Num2,
	Num3,
	Num4,
	Num5,
	Num6,
	Num7,
	Num8,
	Num9,
	Pad0,
	Pad1,
	Pad2,
	Pad3,
	Pad4,
	Pad5,
	Pad6,
	Pad7,
	Pad8,
	Pad9,
	Multiply,
	Add,
	Separator,
	Subtract,
	Decimal,
	Divide,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,
	F13,
	F14,
	F15,
	F16,
	F17,
	F18,
	F19,
	F20,
	F21,
	F22,
	F23,
	F24,
	NumLock,
	Scroll,
	Oem1,
	OemPlus,
	OemComma,
	OemMinus,
	OemPeriod,
	Oem2,
	Oem3,
	Oem4,
	Oem5,
	Oem6,
	Oem7,
	Oem8,
	Oem102
};

UENUM()
enum class ENoesisGuiEvaluateBehavior : uint8
{
	Default,
	Once
};

UENUM()
enum class ENoesisGuiBeforeSetAction : uint8
{
	Delete = 0,
	Maintain = 1
};

UENUM()
enum class ENoesisGuiMessageDialogResult : uint8
{
	Ok,
	Cancel,
	Yes,
	No
};

UENUM()
enum class ENoesisGuiMessageDialogButton : uint8
{
	Ok,
	OkCancel,
	YesNo,
	YesNoCancel
};

UENUM()
enum class ENoesisGuiMessageDialogImage : uint8
{
	None,
	Hand,
	Question,
	Exclamation,
	Asterisk,
	Stop,
	Error,
	Warning,
	Information
};

UENUM()
enum class ENoesisGuiClockState : uint8
{
	Active,
	Paused,
	Filling,
	Stopped,
	Finished
};

UENUM()
enum class ENoesisGuiStretch : uint8
{
	None,
	Fill,
	Uniform,
	UniformToFill
};

UENUM()
enum class ENoesisGuiDock : uint8
{
	Left,
	Top,
	Right,
	Bottom
};

USTRUCT(BlueprintType)
struct FNoesisGuiObjectWithNameScope
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* Object;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiINameScope* Scope;

	FNoesisGuiObjectWithNameScope() {}

	FNoesisGuiObjectWithNameScope(UNoesisGuiInstance* Instance, const Noesis::Gui::ObjectWithNameScope& ObjectWithScope);
};

USTRUCT(BlueprintType)
struct FNoesisGuiDrawingSize
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Height;

	FNoesisGuiDrawingSize() {}

	FNoesisGuiDrawingSize(const Noesis::Drawing::Size& Size);

	Noesis::Drawing::Size ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiDrawingRect
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

	FNoesisGuiDrawingRect() {}

	FNoesisGuiDrawingRect(const Noesis::Drawing::Rect& Rect);

	Noesis::Drawing::Rect ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiDrawingPoint
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Y;

	FNoesisGuiDrawingPoint() {}

	FNoesisGuiDrawingPoint(const Noesis::Drawing::Point& Point);
	
	Noesis::Drawing::Point ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiDrawingSizei
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Width;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Height;

	FNoesisGuiDrawingSizei() {}

	FNoesisGuiDrawingSizei(const Noesis::Drawing::Sizei& Size);

	Noesis::Drawing::Sizei ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiDrawingRecti
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

	FNoesisGuiDrawingRecti() {}

	FNoesisGuiDrawingRecti(const Noesis::Drawing::Recti& Rect);

	Noesis::Drawing::Recti ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiDrawingPointi
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 X;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Y;

	FNoesisGuiDrawingPointi() {}

	FNoesisGuiDrawingPointi(const Noesis::Drawing::Pointi& Point);
	
	Noesis::Drawing::Pointi ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiDuration
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiDurationType DurationType;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Milliseconds;

	FNoesisGuiDuration() {}

	FNoesisGuiDuration(const Noesis::Gui::Duration& Duration);

	Noesis::Gui::Duration ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* Source;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiRoutedEvent* RoutedEvent;

	FNoesisGuiRoutedEventArgs() {}

	FNoesisGuiRoutedEventArgs(UNoesisGuiInstance* Instance, const Noesis::RoutedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiMouseEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint Position;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiMouseButtonState LeftButton;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiMouseButtonState MiddleButton;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiMouseButtonState RightButton;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiMouseButtonState XButton1Button;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiMouseButtonState XButton2Button;

	FNoesisGuiMouseEventArgs() {}

	FNoesisGuiMouseEventArgs(UNoesisGuiInstance* Instance, const Noesis::MouseEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiMouseButtonEventArgs : public FNoesisGuiMouseEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiMouseButton ChangedButton;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiMouseButtonState ButtonState;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 ButtonClicks;

	FNoesisGuiMouseButtonEventArgs() {}

	FNoesisGuiMouseButtonEventArgs(UNoesisGuiInstance* Instance, const Noesis::MouseButtonEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiMouseWheelEventArgs : public FNoesisGuiMouseEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 WheelRotation;

	FNoesisGuiMouseWheelEventArgs() {}

	FNoesisGuiMouseWheelEventArgs(UNoesisGuiInstance* Instance, const Noesis::MouseWheelEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiTouchEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint TouchPoint;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 TouchDevice;

	FNoesisGuiTouchEventArgs() {}

	FNoesisGuiTouchEventArgs(UNoesisGuiInstance* Instance, const Noesis::TouchEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiDragCompletedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool Canceled;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float HorizontalChange;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float VerticalChange;

	FNoesisGuiDragCompletedEventArgs() {}

	FNoesisGuiDragCompletedEventArgs(UNoesisGuiInstance* Instance, const Noesis::DragCompletedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiDragStartedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float HorizontalOffset;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float VerticalOffset;

	FNoesisGuiDragStartedEventArgs() {}

	FNoesisGuiDragStartedEventArgs(UNoesisGuiInstance* Instance, const Noesis::DragStartedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiSelectionChangedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	TArray<class UNoesisGuiBaseComponent*> AddedItems;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	TArray<class UNoesisGuiBaseComponent*> RemovedItems;

	FNoesisGuiSelectionChangedEventArgs(){}

	FNoesisGuiSelectionChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::SelectionChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiSizeChangedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingSize NewSize;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingSize PreviousSize;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool WidthChanged;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool HeightChanged;

	FNoesisGuiSizeChangedEventArgs(){}

	FNoesisGuiSizeChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::SizeChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiKeyboardFocusChangedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiUIElement* OldFocus;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiUIElement* NewFocus;

	FNoesisGuiKeyboardFocusChangedEventArgs() {}

	FNoesisGuiKeyboardFocusChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::KeyboardFocusChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiScrollEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float NewValue;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiScrollEventType ScrollEventType;

	FNoesisGuiScrollEventArgs() {}

	FNoesisGuiScrollEventArgs(UNoesisGuiInstance* Instance, const Noesis::ScrollEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiTextCompositionEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Character;

	FNoesisGuiTextCompositionEventArgs() {}

	FNoesisGuiTextCompositionEventArgs(UNoesisGuiInstance* Instance, const Noesis::TextCompositionEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiContextMenuEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiUIElement* Owner;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float CursorLeft;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float CursorTop;

	FNoesisGuiContextMenuEventArgs() {}

	FNoesisGuiContextMenuEventArgs(UNoesisGuiInstance* Instance, const Noesis::ContextMenuEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiKeyEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiKey Key;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 KeyStates;

	FNoesisGuiKeyEventArgs() {}

	FNoesisGuiKeyEventArgs(UNoesisGuiInstance* Instance, const Noesis::KeyEventArgs& InArgs);
};

UENUM()
enum class ENoesisGuiManipulationModes : uint8
{
	None = 0,
	Rotate = 1,
	Scale = 2,
	TranslateX = 4,
	TranslateY = 8,
	Translate = 12,
	All = 15
};

USTRUCT(BlueprintType)
struct FNoesisGuiManipulationStartingEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	class UNoesisGuiVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	ENoesisGuiManipulationModes Mode;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	FNoesisGuiManipulationStartingEventArgs() {}

	FNoesisGuiManipulationStartingEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationStartingEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationStartingEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiManipulationStartedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint ManipulationOrigin;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Complete;

	FNoesisGuiManipulationStartedEventArgs() {}

	FNoesisGuiManipulationStartedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationStartedEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationStartedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiManipulationDelta
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint Expansion;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Rotation;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float Scale;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint Translation;

	FNoesisGuiManipulationDelta() {}

	FNoesisGuiManipulationDelta(const Noesis::Gui::ManipulationDelta& ManipulationDelta);

	Noesis::Gui::ManipulationDelta ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiManipulationVelocities
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float AngularVelocity;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint ExpansionVelocity;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint LinearVelocity;

	FNoesisGuiManipulationVelocities() {}

	FNoesisGuiManipulationVelocities(const Noesis::Gui::ManipulationVelocities& ManipulationVelocities);

	Noesis::Gui::ManipulationVelocities ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiManipulationDeltaEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint ManipulationOrigin;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiManipulationDelta DeltaManipulation;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiManipulationDelta CumulativeManipulation;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiManipulationVelocities Velocities;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool IsInertial;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Complete;

	FNoesisGuiManipulationDeltaEventArgs() {}

	FNoesisGuiManipulationDeltaEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationDeltaEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationDeltaEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiInertiaExpansionBehavior
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float DesiredDeceleration;

	FNoesisGuiInertiaExpansionBehavior() {}

	FNoesisGuiInertiaExpansionBehavior(const Noesis::Gui::InertiaExpansionBehavior& InertiaExpansionBehavior);

	Noesis::Gui::InertiaExpansionBehavior ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiInertiaRotationBehavior
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float DesiredDeceleration;

	FNoesisGuiInertiaRotationBehavior() {}

	FNoesisGuiInertiaRotationBehavior(const Noesis::Gui::InertiaRotationBehavior& InertiaRotationBehavior);

	Noesis::Gui::InertiaRotationBehavior ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiInertiaTranslationBehavior
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float DesiredDeceleration;

	FNoesisGuiInertiaTranslationBehavior() {}

	FNoesisGuiInertiaTranslationBehavior(const Noesis::Gui::InertiaTranslationBehavior& InertiaTranslationBehavior);

	Noesis::Gui::InertiaTranslationBehavior ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiManipulationInertiaStartingEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint ManipulationOrigin;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	FNoesisGuiManipulationVelocities InitialVelocities;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	FNoesisGuiInertiaRotationBehavior RotationBehavior;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	FNoesisGuiInertiaExpansionBehavior ExpansionBehavior;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	FNoesisGuiInertiaTranslationBehavior TranslationBehavior;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	FNoesisGuiManipulationInertiaStartingEventArgs() {}

	FNoesisGuiManipulationInertiaStartingEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationInertiaStartingEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationInertiaStartingEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiManipulationCompletedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiVisual* ManipulationContainer;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiDrawingPoint ManipulationOrigin;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiManipulationVelocities FinalVelocities;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiManipulationDelta TotalManipulation;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	bool IsInertial;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool Cancel;

	FNoesisGuiManipulationCompletedEventArgs() {}

	FNoesisGuiManipulationCompletedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationCompletedEventArgs& InArgs);

	void ToNoesis(const Noesis::ManipulationCompletedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiScrollChangedEventArgs : public FNoesisGuiRoutedEventArgs
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

	FNoesisGuiScrollChangedEventArgs() {}

	FNoesisGuiScrollChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ScrollChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiToolTipEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	FNoesisGuiToolTipEventArgs() {}

	FNoesisGuiToolTipEventArgs(UNoesisGuiInstance* Instance, const Noesis::ToolTipEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiDragDeltaEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float HorizontalChange;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float VerticalChange;

	FNoesisGuiDragDeltaEventArgs() {}

	FNoesisGuiDragDeltaEventArgs(UNoesisGuiInstance* Instance, const Noesis::DragDeltaEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiFloatPropertyChangedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float OldValue;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	float NewValue;

	FNoesisGuiFloatPropertyChangedEventArgs() {}

	FNoesisGuiFloatPropertyChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::RoutedPropertyChangedEventArgs<NsFloat32>& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiBaseComponentPropertyChangedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* OldValue;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* NewValue;

	FNoesisGuiBaseComponentPropertyChangedEventArgs() {}

	FNoesisGuiBaseComponentPropertyChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::RoutedPropertyChangedEventArgs<Noesis::Ptr<Noesis::BaseComponent> >& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiCanExecuteRoutedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	const class UNoesisGuiICommand* Command;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* Parameter;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool CanExecute;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGui")
	bool ContinueRouting;

	FNoesisGuiCanExecuteRoutedEventArgs() {}

	FNoesisGuiCanExecuteRoutedEventArgs(UNoesisGuiInstance* Instance, const Noesis::CanExecuteRoutedEventArgs& InArgs);

	void ToNoesis(const Noesis::CanExecuteRoutedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiExecutedRoutedEventArgs : public FNoesisGuiRoutedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	const class UNoesisGuiICommand* Command;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* Parameter;

	FNoesisGuiExecutedRoutedEventArgs() {}

	FNoesisGuiExecutedRoutedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ExecutedRoutedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiEventArgs
{
	GENERATED_USTRUCT_BODY()

	FNoesisGuiEventArgs() {}

	FNoesisGuiEventArgs(UNoesisGuiInstance* Instance, const Noesis::EventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiTimelineEventArgs : public FNoesisGuiEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	const class UNoesisGuiDependencyObject* Target;

	FNoesisGuiTimelineEventArgs() {}

	FNoesisGuiTimelineEventArgs(UNoesisGuiInstance* Instance, const Noesis::TimelineEventArgs& InArgs);
};

UENUM()
enum class ENoesisGuiNotifyCollectionChangedAction : uint8
{
	Add,
	Remove,
	Replace,
	Move,
	Reset,
	PreReset
};

USTRUCT(BlueprintType)
struct FNoesisGuiGeneratorPosition
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Index;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 Offset;

	FNoesisGuiGeneratorPosition() {}

	FNoesisGuiGeneratorPosition(const Noesis::Gui::GeneratorPosition& GeneratorPosition);

	Noesis::Gui::GeneratorPosition ToNoesis() const;
};

USTRUCT(BlueprintType)
struct FNoesisGuiItemsChangedEventArgs : public FNoesisGuiEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	ENoesisGuiNotifyCollectionChangedAction Action;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiGeneratorPosition Position;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FNoesisGuiGeneratorPosition OldPosition;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 ItemCount;

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	int32 ItemUICount;

	FNoesisGuiItemsChangedEventArgs() {}

	FNoesisGuiItemsChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ItemsChangedEventArgs& InArgs);
};

USTRUCT(BlueprintType)
struct FNoesisGuiDependencyPropertyChangedEventArgs
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	const class UNoesisGuiDependencyProperty* Prop;

	FNoesisGuiDependencyPropertyChangedEventArgs() {}

	FNoesisGuiDependencyPropertyChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::DependencyPropertyChangedEventArgs& InArgs);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiRoutedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiRoutedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiMouseEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiMouseEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiMouseButtonEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiMouseButtonEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiMouseWheelEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiMouseWheelEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiTouchEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiTouchEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiDragCompletedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiDragCompletedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiDragStartedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiDragStartedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiSizeChangedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiSizeChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiSelectionChangedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiSelectionChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiKeyboardFocusChangedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiKeyboardFocusChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiScrollEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiScrollEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiTextCompositionEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiTextCompositionEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiContextMenuEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiContextMenuEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiKeyEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiKeyEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiManipulationStartingEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiManipulationStartingEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiManipulationStartedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiManipulationStartedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiManipulationDeltaEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiManipulationDeltaEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiManipulationInertiaStartingEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiManipulationInertiaStartingEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiManipulationCompletedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiManipulationCompletedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiScrollChangedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiScrollChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiToolTipEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiToolTipEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiDragDeltaEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiDragDeltaEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiFloatPropertyChangedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiFloatPropertyChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiBaseComponentPropertyChangedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiBaseComponentPropertyChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiCanExecuteRoutedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiCanExecuteRoutedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiExecutedRoutedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiExecutedRoutedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiTimelineEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiTimelineEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiItemsChangedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiItemsChangedEventArgs, Args);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoesisGuiDependencyPropertyChangedEventHandler, class UNoesisGuiBaseComponent*, Sender, FNoesisGuiDependencyPropertyChangedEventArgs, Args);
