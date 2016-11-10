////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisEvents.h"
#include "NoesisInstance.h"
#include "NoesisGeneratedClasses.h"

FNoesisRoutedEventArgs::FNoesisRoutedEventArgs(UNoesisInstance* Instance, const Noesis::RoutedEventArgs& InArgs)
{
	Source = Instance->FindUnrealComponentForNoesisComponent(InArgs.source);
	RoutedEvent = InArgs.routedEvent ? CastChecked<UNoesisRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent)) : nullptr;
}

FNoesisMouseEventArgs::FNoesisMouseEventArgs(UNoesisInstance* Instance, const Noesis::MouseEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	Position = FNoesisDrawingPoint(InArgs.position);
	LeftButton = (ENoesisMouseButtonState)InArgs.leftButton;
	MiddleButton = (ENoesisMouseButtonState)InArgs.middleButton;
	RightButton = (ENoesisMouseButtonState)InArgs.rightButton;
	XButton1Button = (ENoesisMouseButtonState)InArgs.xButton1Button;
	XButton2Button = (ENoesisMouseButtonState)InArgs.xButton2Button;
}

FNoesisMouseButtonEventArgs::FNoesisMouseButtonEventArgs(UNoesisInstance* Instance, const Noesis::MouseButtonEventArgs& InArgs)
	: FNoesisMouseEventArgs(Instance, InArgs)
{
	ChangedButton = (ENoesisMouseButton)InArgs.changedButton;
	ButtonState = (ENoesisMouseButtonState)InArgs.buttonState;
	ButtonClicks = (int32)InArgs.buttonClicks;
}

FNoesisMouseWheelEventArgs::FNoesisMouseWheelEventArgs(UNoesisInstance* Instance, const Noesis::MouseWheelEventArgs& InArgs)
	: FNoesisMouseEventArgs(Instance, InArgs)
{
	WheelRotation = (int32)InArgs.wheelRotation;
}

FNoesisTouchEventArgs::FNoesisTouchEventArgs(UNoesisInstance* Instance, const Noesis::TouchEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	TouchPoint = FNoesisDrawingPoint(InArgs.touchPoint);
	TouchDevice = (int32)InArgs.touchDevice;
}

FNoesisDragCompletedEventArgs::FNoesisDragCompletedEventArgs(UNoesisInstance* Instance, const Noesis::DragCompletedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	Canceled = InArgs.canceled;
	HorizontalChange = InArgs.horizontalChange;
	VerticalChange = InArgs.verticalChange;
}

FNoesisDragStartedEventArgs::FNoesisDragStartedEventArgs(UNoesisInstance* Instance, const Noesis::DragStartedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	HorizontalOffset = InArgs.horizontalOffset;
	VerticalOffset = InArgs.verticalOffset;
}

FNoesisSelectionChangedEventArgs::FNoesisSelectionChangedEventArgs(UNoesisInstance* Instance, const Noesis::SelectionChangedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	for (auto Item : InArgs.addedItems)
	{
		AddedItems.Add(Instance->FindUnrealComponentForNoesisComponent(Item.GetPtr()));
	}

	for (auto Item : InArgs.removedItems)
	{
		RemovedItems.Add(Instance->FindUnrealComponentForNoesisComponent(Item.GetPtr()));
	}
}

FNoesisSizeChangedEventArgs::FNoesisSizeChangedEventArgs(UNoesisInstance* Instance, const Noesis::SizeChangedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	NewSize = FNoesisDrawingSize(InArgs.sizeChangedInfo.newSize);
	PreviousSize = FNoesisDrawingSize(InArgs.sizeChangedInfo.previousSize);
	WidthChanged = InArgs.sizeChangedInfo.widthChanged;
	HeightChanged = InArgs.sizeChangedInfo.heightChanged;
}

FNoesisKeyboardFocusChangedEventArgs::FNoesisKeyboardFocusChangedEventArgs(UNoesisInstance* Instance, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	OldFocus = InArgs.oldFocus ? CastChecked<UNoesisUIElement>(Instance->FindUnrealComponentForNoesisComponent(InArgs.oldFocus)) : nullptr;
	NewFocus = InArgs.newFocus ? CastChecked<UNoesisUIElement>(Instance->FindUnrealComponentForNoesisComponent(InArgs.newFocus)) : nullptr;
}

FNoesisScrollEventArgs::FNoesisScrollEventArgs(UNoesisInstance* Instance, const Noesis::ScrollEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	NewValue = InArgs.newValue;
	ScrollEventType = (ENoesisScrollEventType)InArgs.scrollEventType;
}

FNoesisTextCompositionEventArgs::FNoesisTextCompositionEventArgs(UNoesisInstance* Instance, const Noesis::TextCompositionEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	Character = (int32)InArgs.ch;
}

FNoesisContextMenuEventArgs::FNoesisContextMenuEventArgs(UNoesisInstance* Instance, const Noesis::ContextMenuEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	Owner = InArgs.owner.GetPtr() ? CastChecked<UNoesisUIElement>(Instance->FindUnrealComponentForNoesisComponent(InArgs.owner.GetPtr())) : nullptr;
	CursorLeft = InArgs.cursorLeft;
	CursorTop = InArgs.cursorTop;
}

FNoesisKeyEventArgs::FNoesisKeyEventArgs(UNoesisInstance* Instance, const Noesis::KeyEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	Key = (ENoesisKey)InArgs.key;
	KeyStates = (int32)InArgs.keyStates;
}

FNoesisManipulationStartingEventArgs::FNoesisManipulationStartingEventArgs(UNoesisInstance* Instance, const Noesis::ManipulationStartingEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
	Mode = (ENoesisManipulationModes)InArgs.mode;
	Cancel = InArgs.cancel;
}

void FNoesisManipulationStartingEventArgs::ToNoesis(const Noesis::ManipulationStartingEventArgs& InArgs)
{
	InArgs.manipulationContainer = NsDynamicCast<Noesis::Ptr<Noesis::Gui::Visual> >(ManipulationContainer->NoesisComponent).GetPtr();
	InArgs.mode = (Noesis::ManipulationModes)Mode;
	InArgs.cancel = Cancel;
}

FNoesisManipulationStartedEventArgs::FNoesisManipulationStartedEventArgs(UNoesisInstance* Instance, const Noesis::ManipulationStartedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
	ManipulationOrigin = FNoesisDrawingPoint(InArgs.manipulationOrigin);
	Cancel = InArgs.cancel;
	Complete = InArgs.complete;
}

void FNoesisManipulationStartedEventArgs::ToNoesis(const Noesis::ManipulationStartedEventArgs& InArgs)
{
	InArgs.cancel = Cancel;
	InArgs.complete = Complete;
}

FNoesisManipulationDeltaEventArgs::FNoesisManipulationDeltaEventArgs(UNoesisInstance* Instance, const Noesis::ManipulationDeltaEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
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

FNoesisManipulationInertiaStartingEventArgs::FNoesisManipulationInertiaStartingEventArgs(UNoesisInstance* Instance, const Noesis::ManipulationInertiaStartingEventArgs& InArgs)
: FNoesisRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
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

FNoesisManipulationCompletedEventArgs::FNoesisManipulationCompletedEventArgs(UNoesisInstance* Instance, const Noesis::ManipulationCompletedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
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

FNoesisScrollChangedEventArgs::FNoesisScrollChangedEventArgs(UNoesisInstance* Instance, const Noesis::ScrollChangedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
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

FNoesisToolTipEventArgs::FNoesisToolTipEventArgs(UNoesisInstance* Instance, const Noesis::ToolTipEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
}

FNoesisDragDeltaEventArgs::FNoesisDragDeltaEventArgs(UNoesisInstance* Instance, const Noesis::DragDeltaEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	HorizontalChange = InArgs.horizontalChange;
	VerticalChange = InArgs.verticalChange;
}

FNoesisFloatPropertyChangedEventArgs::FNoesisFloatPropertyChangedEventArgs(UNoesisInstance* Instance, const Noesis::RoutedPropertyChangedEventArgs<NsFloat32>& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	OldValue = InArgs.oldValue;
	NewValue = InArgs.newValue;
}

FNoesisBaseComponentPropertyChangedEventArgs::FNoesisBaseComponentPropertyChangedEventArgs(UNoesisInstance* Instance, const Noesis::RoutedPropertyChangedEventArgs<Noesis::Ptr<Noesis::BaseComponent> >& InArgs)
: FNoesisRoutedEventArgs(Instance, InArgs)
{
	OldValue = Instance->FindUnrealComponentForNoesisComponent(InArgs.oldValue.GetPtr());
	NewValue = Instance->FindUnrealComponentForNoesisComponent(InArgs.newValue.GetPtr());
}

FNoesisCanExecuteRoutedEventArgs::FNoesisCanExecuteRoutedEventArgs(UNoesisInstance* Instance, const Noesis::CanExecuteRoutedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs) 
{
	Command = CastChecked<UNoesisICommand>(Instance->FindUnrealInterfaceForNoesisInterface(InArgs.command));
	Parameter = Instance->FindUnrealComponentForNoesisComponent(InArgs.parameter.GetPtr());
	CanExecute = InArgs.canExecute;
	ContinueRouting = InArgs.continueRouting;
}

void FNoesisCanExecuteRoutedEventArgs::ToNoesis(const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	InArgs.canExecute = CanExecute;
	InArgs.continueRouting = ContinueRouting;
}

FNoesisExecutedRoutedEventArgs::FNoesisExecutedRoutedEventArgs(UNoesisInstance* Instance, const Noesis::ExecutedRoutedEventArgs& InArgs)
	: FNoesisRoutedEventArgs(Instance, InArgs)
{
	Command = CastChecked<UNoesisICommand>(Instance->FindUnrealInterfaceForNoesisInterface(InArgs.command));
	Parameter = Instance->FindUnrealComponentForNoesisComponent(InArgs.parameter.GetPtr());
}

FNoesisEventArgs::FNoesisEventArgs(UNoesisInstance* Instance, const Noesis::EventArgs& InArgs)
{
}

FNoesisTimelineEventArgs::FNoesisTimelineEventArgs(UNoesisInstance* Instance, const Noesis::TimelineEventArgs& InArgs)
	: FNoesisEventArgs(Instance, InArgs)
{
	Target = InArgs.target ? CastChecked<UNoesisDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(InArgs.target)) : nullptr;
}

FNoesisItemsChangedEventArgs::FNoesisItemsChangedEventArgs(UNoesisInstance* Instance, const Noesis::ItemsChangedEventArgs& InArgs)
{
	Action = (ENoesisNotifyCollectionChangedAction)InArgs.action;
	Position = FNoesisGeneratorPosition(InArgs.position);
	OldPosition = FNoesisGeneratorPosition(InArgs.oldPosition);
	ItemCount = InArgs.itemCount;
	ItemUICount = InArgs.itemUICount;
}

FNoesisDependencyPropertyChangedEventArgs::FNoesisDependencyPropertyChangedEventArgs(UNoesisInstance* Instance, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	Prop = InArgs.prop ? CastChecked<UNoesisDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(InArgs.prop)) : nullptr;
}
