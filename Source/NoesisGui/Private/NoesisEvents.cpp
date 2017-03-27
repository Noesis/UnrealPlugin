////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisEvents.h"
#include "NoesisInstance.h"
#include "NoesisGeneratedClasses.h"

FNoesisRoutedEventArgs::FNoesisRoutedEventArgs(const Noesis::RoutedEventArgs& InArgs)
{
	Source = CreateClassFor(InArgs.source, nullptr);
	RoutedEvent = CastChecked<UNoesisRoutedEvent>(CreateClassFor(InArgs.routedEvent, nullptr), ECastCheckedType::NullAllowed);
}

FNoesisMouseEventArgs::FNoesisMouseEventArgs(const Noesis::MouseEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	Position = FNoesisDrawingPoint(InArgs.position);
	LeftButton = (ENoesisMouseButtonState)InArgs.leftButton;
	MiddleButton = (ENoesisMouseButtonState)InArgs.middleButton;
	RightButton = (ENoesisMouseButtonState)InArgs.rightButton;
	XButton1Button = (ENoesisMouseButtonState)InArgs.xButton1Button;
	XButton2Button = (ENoesisMouseButtonState)InArgs.xButton2Button;
}

FNoesisMouseButtonEventArgs::FNoesisMouseButtonEventArgs(const Noesis::MouseButtonEventArgs& InArgs)
	: FNoesisMouseEventArgs(InArgs)
{
	ChangedButton = (ENoesisMouseButton)InArgs.changedButton;
	ButtonState = (ENoesisMouseButtonState)InArgs.buttonState;
	ButtonClicks = (int32)InArgs.buttonClicks;
}

FNoesisMouseWheelEventArgs::FNoesisMouseWheelEventArgs(const Noesis::MouseWheelEventArgs& InArgs)
	: FNoesisMouseEventArgs(InArgs)
{
	WheelRotation = (int32)InArgs.wheelRotation;
}

FNoesisTouchEventArgs::FNoesisTouchEventArgs(const Noesis::TouchEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	TouchPoint = FNoesisDrawingPoint(InArgs.touchPoint);
	TouchDevice = (int32)InArgs.touchDevice;
}

FNoesisDragCompletedEventArgs::FNoesisDragCompletedEventArgs(const Noesis::DragCompletedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	Canceled = InArgs.canceled;
	HorizontalChange = InArgs.horizontalChange;
	VerticalChange = InArgs.verticalChange;
}

FNoesisDragStartedEventArgs::FNoesisDragStartedEventArgs(const Noesis::DragStartedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	HorizontalOffset = InArgs.horizontalOffset;
	VerticalOffset = InArgs.verticalOffset;
}

FNoesisSelectionChangedEventArgs::FNoesisSelectionChangedEventArgs(const Noesis::SelectionChangedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	for (auto Item : InArgs.addedItems)
	{
		AddedItems.Add(CreateClassFor(Item.GetPtr(), nullptr));
	}

	for (auto Item : InArgs.removedItems)
	{
		RemovedItems.Add(CreateClassFor(Item.GetPtr(), nullptr));
	}
}

FNoesisSizeChangedEventArgs::FNoesisSizeChangedEventArgs(const Noesis::SizeChangedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	NewSize = FNoesisDrawingSize(InArgs.sizeChangedInfo.newSize);
	PreviousSize = FNoesisDrawingSize(InArgs.sizeChangedInfo.previousSize);
	WidthChanged = InArgs.sizeChangedInfo.widthChanged;
	HeightChanged = InArgs.sizeChangedInfo.heightChanged;
}

FNoesisKeyboardFocusChangedEventArgs::FNoesisKeyboardFocusChangedEventArgs(const Noesis::KeyboardFocusChangedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	OldFocus = CastChecked<UNoesisUIElement>(CreateClassFor(InArgs.oldFocus, nullptr), ECastCheckedType::NullAllowed);
	NewFocus = CastChecked<UNoesisUIElement>(CreateClassFor(InArgs.newFocus, nullptr), ECastCheckedType::NullAllowed);
}

FNoesisScrollEventArgs::FNoesisScrollEventArgs(const Noesis::ScrollEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	NewValue = InArgs.newValue;
	ScrollEventType = (ENoesisScrollEventType)InArgs.scrollEventType;
}

FNoesisTextCompositionEventArgs::FNoesisTextCompositionEventArgs(const Noesis::TextCompositionEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	Character = (int32)InArgs.ch;
}

FNoesisContextMenuEventArgs::FNoesisContextMenuEventArgs(const Noesis::ContextMenuEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	Owner = CastChecked<UNoesisUIElement>(CreateClassFor(InArgs.owner.GetPtr(), nullptr), ECastCheckedType::NullAllowed);
	CursorLeft = InArgs.cursorLeft;
	CursorTop = InArgs.cursorTop;
}

FNoesisKeyEventArgs::FNoesisKeyEventArgs(const Noesis::KeyEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	Key = (ENoesisKey)InArgs.key;
	KeyStates = (int32)InArgs.keyStates;
}

FNoesisManipulationStartingEventArgs::FNoesisManipulationStartingEventArgs(const Noesis::ManipulationStartingEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	ManipulationContainer = CastChecked<UNoesisVisual>(CreateClassFor(InArgs.manipulationContainer, nullptr), ECastCheckedType::NullAllowed);
	Mode = (ENoesisManipulationModes)InArgs.mode;
	Cancel = InArgs.cancel;
}

void FNoesisManipulationStartingEventArgs::ToNoesis(const Noesis::ManipulationStartingEventArgs& InArgs)
{
	InArgs.manipulationContainer = NsDynamicCast<Noesis::Ptr<Noesis::Gui::Visual> >(ManipulationContainer->NoesisComponent).GetPtr();
	InArgs.mode = (Noesis::ManipulationModes)Mode;
	InArgs.cancel = Cancel;
}

FNoesisManipulationStartedEventArgs::FNoesisManipulationStartedEventArgs(const Noesis::ManipulationStartedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	ManipulationContainer = CastChecked<UNoesisVisual>(CreateClassFor(InArgs.manipulationContainer, nullptr), ECastCheckedType::NullAllowed);
	ManipulationOrigin = FNoesisDrawingPoint(InArgs.manipulationOrigin);
	Cancel = InArgs.cancel;
	Complete = InArgs.complete;
}

void FNoesisManipulationStartedEventArgs::ToNoesis(const Noesis::ManipulationStartedEventArgs& InArgs)
{
	InArgs.cancel = Cancel;
	InArgs.complete = Complete;
}

FNoesisManipulationDeltaEventArgs::FNoesisManipulationDeltaEventArgs(const Noesis::ManipulationDeltaEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	ManipulationContainer = CastChecked<UNoesisVisual>(CreateClassFor(InArgs.manipulationContainer, nullptr), ECastCheckedType::NullAllowed);
	ManipulationOrigin = FNoesisDrawingPoint(InArgs.manipulationOrigin);
	DeltaManipulation = FNoesisManipulationDelta(InArgs.deltaManipulation);
	CumulativeManipulation = FNoesisManipulationDelta(InArgs.cumulativeManipulation);
	Velocities = FNoesisManipulationVelocities(InArgs.velocities);
	IsInertial = InArgs.isInertial;
	Cancel = InArgs.cancel;
	Complete = InArgs.complete;
}

void FNoesisManipulationDeltaEventArgs::ToNoesis(const Noesis::ManipulationDeltaEventArgs& InArgs)
{
	InArgs.cancel = Cancel;
	InArgs.complete = Complete;
}

FNoesisManipulationInertiaStartingEventArgs::FNoesisManipulationInertiaStartingEventArgs(const Noesis::ManipulationInertiaStartingEventArgs& InArgs)
: FNoesisRoutedEventArgs(InArgs)
{
	ManipulationContainer = CastChecked<UNoesisVisual>(CreateClassFor(InArgs.manipulationContainer, nullptr), ECastCheckedType::NullAllowed);
	ManipulationOrigin = FNoesisDrawingPoint(InArgs.manipulationOrigin);
	InitialVelocities = FNoesisManipulationVelocities(InArgs.initialVelocities);
	RotationBehavior = FNoesisInertiaRotationBehavior(InArgs.rotationBehavior);
	ExpansionBehavior = FNoesisInertiaExpansionBehavior(InArgs.expansionBehavior);
	TranslationBehavior = FNoesisInertiaTranslationBehavior(InArgs.translationBehavior);
	Cancel = InArgs.cancel;
}

void FNoesisManipulationInertiaStartingEventArgs::ToNoesis(const Noesis::ManipulationInertiaStartingEventArgs& InArgs)
{
	InArgs.initialVelocities = InitialVelocities.ToNoesis();
	InArgs.rotationBehavior = RotationBehavior.ToNoesis();
	InArgs.expansionBehavior = ExpansionBehavior.ToNoesis();
	InArgs.translationBehavior = TranslationBehavior.ToNoesis();
	InArgs.cancel = Cancel;
}

FNoesisManipulationCompletedEventArgs::FNoesisManipulationCompletedEventArgs(const Noesis::ManipulationCompletedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	ManipulationContainer = CastChecked<UNoesisVisual>(CreateClassFor(InArgs.manipulationContainer, nullptr), ECastCheckedType::NullAllowed);
	ManipulationOrigin = FNoesisDrawingPoint(InArgs.manipulationOrigin);
	FinalVelocities = FNoesisManipulationVelocities(InArgs.finalVelocities);
	TotalManipulation = FNoesisManipulationDelta(InArgs.totalManipulation);
	IsInertial = InArgs.isInertial;
	Cancel = InArgs.cancel;
}

void FNoesisManipulationCompletedEventArgs::ToNoesis(const Noesis::ManipulationCompletedEventArgs& InArgs)
{
	InArgs.cancel = Cancel;
}

FNoesisScrollChangedEventArgs::FNoesisScrollChangedEventArgs(const Noesis::ScrollChangedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	ExtentHeight = InArgs.extentHeight;
	ExtentHeightChange = InArgs.extentHeightChange;
	ExtentWidth = InArgs.extentWidth;
	ExtentWidthChange = InArgs.extentWidthChange;
	HorizontalChange = InArgs.horizontalChange;
	HorizontalOffset = InArgs.horizontalOffset;
	VerticalChange = InArgs.verticalChange;
	VerticalOffset = InArgs.verticalOffset;
	ViewportHeight = InArgs.viewportHeight;
	ViewportHeightChange = InArgs.viewportHeightChange;
	ViewportWidth = InArgs.viewportWidth;
	ViewportWidthChange = InArgs.viewportWidthChange;
}

FNoesisToolTipEventArgs::FNoesisToolTipEventArgs(const Noesis::ToolTipEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
}

FNoesisDragDeltaEventArgs::FNoesisDragDeltaEventArgs(const Noesis::DragDeltaEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	HorizontalChange = InArgs.horizontalChange;
	VerticalChange = InArgs.verticalChange;
}

FNoesisFloatPropertyChangedEventArgs::FNoesisFloatPropertyChangedEventArgs(const Noesis::RoutedPropertyChangedEventArgs<NsFloat32>& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	OldValue = InArgs.oldValue;
	NewValue = InArgs.newValue;
}

FNoesisBaseComponentPropertyChangedEventArgs::FNoesisBaseComponentPropertyChangedEventArgs(const Noesis::RoutedPropertyChangedEventArgs<Noesis::Ptr<Noesis::BaseComponent> >& InArgs)
: FNoesisRoutedEventArgs(InArgs)
{
	OldValue = CreateClassFor(InArgs.oldValue.GetPtr(), nullptr);
	NewValue = CreateClassFor(InArgs.newValue.GetPtr(), nullptr);
}

FNoesisCanExecuteRoutedEventArgs::FNoesisCanExecuteRoutedEventArgs(const Noesis::CanExecuteRoutedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs) 
{
	Command = CastChecked<UNoesisICommand>(CreateInterfaceFor(InArgs.command, nullptr), ECastCheckedType::NullAllowed);
	Parameter = CreateClassFor(InArgs.parameter.GetPtr(), nullptr);
	CanExecute = InArgs.canExecute;
	ContinueRouting = InArgs.continueRouting;
}

void FNoesisCanExecuteRoutedEventArgs::ToNoesis(const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	InArgs.canExecute = CanExecute;
	InArgs.continueRouting = ContinueRouting;
}

FNoesisExecutedRoutedEventArgs::FNoesisExecutedRoutedEventArgs(const Noesis::ExecutedRoutedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	Command = CastChecked<UNoesisICommand>(CreateInterfaceFor(InArgs.command, nullptr), ECastCheckedType::NullAllowed);
	Parameter = CreateClassFor(InArgs.parameter.GetPtr(), nullptr);
}

FNoesisRequestBringIntoViewEventArgs::FNoesisRequestBringIntoViewEventArgs(const Noesis::RequestBringIntoViewEventArgs& InArgs)
	: FNoesisRoutedEventArgs(InArgs)
{
	TargetObject = CastChecked<UNoesisDependencyObject>(CreateClassFor(InArgs.targetObject, nullptr), ECastCheckedType::NullAllowed);
	TargetRect = FNoesisDrawingRect(InArgs.targetRect);
}

FNoesisEventArgs::FNoesisEventArgs(const Noesis::EventArgs& InArgs)
{
}

FNoesisTimelineEventArgs::FNoesisTimelineEventArgs(const Noesis::TimelineEventArgs& InArgs)
	: FNoesisEventArgs(InArgs)
{
	Target = CastChecked<UNoesisDependencyObject>(CreateClassFor(InArgs.target, nullptr), ECastCheckedType::NullAllowed);
}

FNoesisItemsChangedEventArgs::FNoesisItemsChangedEventArgs(const Noesis::ItemsChangedEventArgs& InArgs)
{
	Action = (ENoesisNotifyCollectionChangedAction)InArgs.action;
	Position = FNoesisGeneratorPosition(InArgs.position);
	OldPosition = FNoesisGeneratorPosition(InArgs.oldPosition);
	ItemCount = InArgs.itemCount;
	ItemUICount = InArgs.itemUICount;
}

FNoesisDependencyPropertyChangedEventArgs::FNoesisDependencyPropertyChangedEventArgs(const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	Prop = CastChecked<UNoesisDependencyProperty>(CreateClassFor(InArgs.prop, nullptr), ECastCheckedType::NullAllowed);
}
