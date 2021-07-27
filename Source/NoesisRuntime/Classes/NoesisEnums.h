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
#include "NoesisEnums.generated.h"

UENUM()
enum class ENoesisHandoffBehavior : uint8
{
	SnapshotAndReplace,
	Compose
};

UENUM()
enum class ENoesisBindingMode : uint8
{
	Default,
	TwoWay,
	OneWay,
	OneTime,
	OneWayToSource
};

UENUM()
enum class ENoesisUpdateSourceTrigger : uint8
{
	Default,
	PropertyChanged,
	LostFocus,
	Explicit
};

UENUM()
enum class ENoesisGeneratorStatus : uint8
{
	NotStarted,
	GeneratingContainers,
	ContainersGenerated,
	Error
};

UENUM()
enum class ENoesisRelativeSourceMode : uint8
{
	PreviousData,
	TemplatedParent,
	Self,
	FindAncestor
};

UENUM()
enum class ENoesisRoutingStrategy : uint8
{
	Bubbling,
	Tunneling,
	Direct
};

UENUM(BlueprintType)
enum class ENoesisDurationType : uint8
{
	Automatic,
	TimeSpan,
	Forever
};

UENUM()
enum class ENoesisMouseButton : uint8
{
	Left,
	Right,
	Middle,
	XButton1,
	XButton2
};

UENUM()
enum class ENoesisMouseButtonState : uint8
{
	Pressed,
	Released
};

UENUM()
enum class ENoesisScrollEventType : uint8
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
enum class ENoesisKey : uint8
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
enum class ENoesisEvaluateBehavior : uint8
{
	Default,
	Once
};

UENUM()
enum class ENoesisBeforeSetAction : uint8
{
	Delete = 0,
	Maintain = 1
};

UENUM()
enum class ENoesisMessageDialogResult : uint8
{
	Ok,
	Cancel,
	Yes,
	No
};

UENUM()
enum class ENoesisMessageDialogButton : uint8
{
	Ok,
	OkCancel,
	YesNo,
	YesNoCancel
};

UENUM()
enum class ENoesisMessageDialogImage : uint8
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
enum class ENoesisClockState : uint8
{
	Active,
	Paused,
	Filling,
	Stopped,
	Finished
};

UENUM()
enum class ENoesisStretch : uint8
{
	None,
	Fill,
	Uniform,
	UniformToFill
};

UENUM()
enum class ENoesisDock : uint8
{
	Left,
	Top,
	Right,
	Bottom
};

UENUM()
enum class ENoesisManipulationModes : uint8
{
	None = 0,
	Rotate = 1,
	Scale = 2,
	TranslateX = 4,
	TranslateY = 8,
	Translate = 12,
	All = 15
};

UENUM()
enum class ENoesisClickMode : uint8
{
	Hover,
	Press,
	Release
};

UENUM()
enum class ENoesisScrollBarVisibility : uint8
{
	Disabled,
	Auto,
	Hidden,
	Visible
};

UENUM()
enum class ENoesisTickBarPlacement : uint8
{
	Left,
	Top,
	Right,
	Bottom
};

UENUM()
enum class ENoesisTextWrapping : uint8
{
	NoWrap,
	Wrap,
	WrapWithOverflow
};

UENUM()
enum class ENoesisGridViewColumnHeaderRole : uint8
{
	Normal,
	Floating,
	Padding
};

UENUM()
enum class ENoesisRepeatMode : uint8
{
	Count,
	Duration,
	Forever
};

UENUM()
enum class ENoesisVerticalAlignment : uint8
{
	Top,
	Center,
	Bottom,
	Stretch
};

UENUM()
enum class ENoesisStretchDirection : uint8
{
	UpOnly,
	DownOnly,
	Both
};

UENUM()
enum class ENoesisTickPlacement : uint8
{
	None,
	TopLeft,
	BottomRight,
	Both
};

UENUM()
enum class ENoesisSelectionMode : uint8
{
	Single,
	Multiple,
	Extended
};

UENUM()
enum class ENoesisEasingMode : uint8
{
	EaseOut,
	EaseIn,
	EaseInOut
};

UENUM()
enum class ENoesisTextAlignment : uint8
{
	Center,
	Justify,
	Left,
	Right
};

UENUM()
enum class ENoesisPanningMode : uint8
{
	Both,
	HorizontalFirst,
	HorizontalOnly,
	None,
	VerticalFirst,
	VerticalOnly
};

UENUM()
enum class ENoesisVisibility : uint8
{
	Collapsed,
	Hidden,
	Visible
};

UENUM()
enum class ENoesisPenLineCap : uint8
{
	Flat,
	Square,
	Round,
	Triangle
};

UENUM()
enum class ENoesisExpandDirection : uint8
{
	Down,
	Up,
	Left,
	Right
};

UENUM()
enum class ENoesisBrushMappingMode : uint8
{
	Absolute,
	RelativeToBoundingBox
};

UENUM()
enum class ENoesisPenLineJoin : uint8
{
	Miter,
	Bevel,
	Round
};

UENUM()
enum class ENoesisSlipBehavior : uint8
{
	Grow,
	Slip
};

UENUM()
enum class ENoesisPopupAnimation : uint8
{
	None,
	Fade,
	Slide,
	Scroll
};

UENUM()
enum class ENoesisHorizontalAlignment : uint8
{
	Left,
	Center,
	Right,
	Stretch
};

UENUM()
enum class ENoesisAlignmentY : uint8
{
	Top,
	Center,
	Bottom
};

UENUM()
enum class ENoesisAlignmentX : uint8
{
	Left,
	Center,
	Right
};

UENUM()
enum class ENoesisFontStyle : uint8
{
	Normal,
	Italic,
	Oblique
};

UENUM()
enum class ENoesissGuiGridUnitType : uint8
{
	Auto,
	Pixel,
	Star
};

UENUM()
enum class ENoesisTileMode : uint8
{
	None,
	Tile,
	FlipX,
	FlipY,
	FlipXY
};

UENUM()
enum class ENoesisFillRule : uint8
{
	EvenOdd,
	Nonzero
};

UENUM()
enum class ENoesisTextTrimming : uint8
{
	None,
	CharacterEllipsis,
	WordEllipsis
};

UENUM()
enum class ENoesisGradientSpreadMethod : uint8
{
	Pad,
	Reflect,
	Repeat
};

UENUM()
enum class ENoesisOrientation : uint8
{
	Horizontal,
	Vertical
};

UENUM()
enum class ENoesisFontWeight : uint8
{
	Thin = 10,
	ExtraLight = 20,
	Light = 30,
	SemiLight = 35,
	Normal = 40,
	Medium = 50,
	SemiBold = 60,
	Bold = 70,
	ExtraBold = 80,
	Black = 90,
	ExtraBlack = 95
};

UENUM()
enum class ENoesisFontStretch : uint8
{
	UltraCondensed = 1,
	ExtraCondensed = 2,
	Condensed = 3,
	SemiCondensed = 4,
	Normal = 5,
	SemiExpanded = 6,
	Expanded = 7,
	ExtraExpanded = 8,
	UltraExpanded = 9
};

UENUM()
enum class ENoesisFillBehavior : uint8
{
	HoldEnd,
	Stop
};

UENUM()
enum class ENoesisGeometryCombineMode :uint8
{
	Union,
	Intersect,
	Xor,
	Exclude
};

UENUM()
enum class ENoesisMenuItemRole : uint8
{
	TopLevelItem,
	TopLevelHeader,
	SubmenuItem,
	SubmenuHeader
};

UENUM()
enum class ENoesisColorInterpolationMode : uint8
{
	ScRgbLinearInterpolation,
	SRgbLinearInterpolation
};

UENUM()
enum class ENoesisPlacementMode : uint8
{
	Absolute,
	Relative,
	Bottom,
	Center,
	Right,
	AbsolutePoint,
	RelativePoint,
	Mouse,
	MousePoint,
	Left,
	Top,
	Custom
};

UENUM()
enum class ENoesisNotifyCollectionChangedAction : uint8
{
	Add,
	Remove,
	Replace,
	Move,
	Reset,
	PreReset
};
