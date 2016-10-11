////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiTypes.h"
#include "NoesisGuiInstance.h"
#include "NoesisGuiGeneratedClasses.h"

FNoesisGuiObjectWithNameScope::FNoesisGuiObjectWithNameScope(UNoesisGuiInstance* Instance, const Noesis::Gui::ObjectWithNameScope& ObjectWithScope)
{
	Object = Instance->FindUnrealComponentForNoesisComponent(ObjectWithScope.object);
	Scope = ObjectWithScope.scope ? CastChecked<UNoesisGuiINameScope>(Instance->FindUnrealInterfaceForNoesisInterface(ObjectWithScope.scope)) : nullptr;
}

FNoesisGuiDrawingSize::FNoesisGuiDrawingSize(const Noesis::Drawing::Size& Size)
{
	Width = Size.width;
	Height = Size.height;
}

Noesis::Drawing::Size FNoesisGuiDrawingSize::ToNoesis() const
{
	return Noesis::Drawing::Size(Width, Height);
}

FNoesisGuiDrawingRect::FNoesisGuiDrawingRect(const Noesis::Drawing::Rect& Rect)
{
	X = Rect.x;
	Y = Rect.y;
	Width = Rect.width;
	Height = Rect.height;
}

Noesis::Drawing::Rect FNoesisGuiDrawingRect::ToNoesis() const
{
	return Noesis::Drawing::Rect(X, Y, Width, Height);
}

FNoesisGuiDrawingPoint::FNoesisGuiDrawingPoint(const Noesis::Drawing::Point& Point)
{
	X = Point.x;
	Y = Point.y;
}

Noesis::Drawing::Point FNoesisGuiDrawingPoint::ToNoesis() const
{
	return Noesis::Drawing::Point(X, Y);
}

FNoesisGuiDrawingSizei::FNoesisGuiDrawingSizei(const Noesis::Drawing::Sizei& Size)
{
	Width = Size.width;
	Height = Size.height;
}

Noesis::Drawing::Sizei FNoesisGuiDrawingSizei::ToNoesis() const
{
	return Noesis::Drawing::Sizei(Width, Height);
}

FNoesisGuiDrawingRecti::FNoesisGuiDrawingRecti(const Noesis::Drawing::Recti& Rect)
{
	X = Rect.x;
	Y = Rect.y;
	Width = Rect.width;
	Height = Rect.height;
}

Noesis::Drawing::Recti FNoesisGuiDrawingRecti::ToNoesis() const
{
	return Noesis::Drawing::Recti(X, Y, Width, Height);
}

FNoesisGuiDrawingPointi::FNoesisGuiDrawingPointi(const Noesis::Drawing::Pointi& Point)
{
	X = Point.x;
	Y = Point.y;
}

Noesis::Drawing::Pointi FNoesisGuiDrawingPointi::ToNoesis() const
{
	return Noesis::Drawing::Pointi(X, Y);
}

FNoesisGuiDuration::FNoesisGuiDuration(const Noesis::Gui::Duration& Duration)
{
	DurationType = (ENoesisGuiDurationType)Duration.GetDurationType();
	Milliseconds = (int32)Duration.GetTimeSpan().GetMilliseconds();
}

Noesis::Gui::Duration FNoesisGuiDuration::ToNoesis() const
{
	if (DurationType == ENoesisGuiDurationType::Automatic)
	{
		return Noesis::Gui::Duration::Automatic();
	}
	else if (DurationType == ENoesisGuiDurationType::Forever)
	{
		return Noesis::Gui::Duration::Forever();
	}
	return Noesis::Gui::Duration(Noesis::Gui::TimeSpan(0, 0, 0, 0, Milliseconds));
}

FNoesisGuiRoutedEventArgs::FNoesisGuiRoutedEventArgs(UNoesisGuiInstance* Instance, const Noesis::RoutedEventArgs& InArgs)
{
	Source = Instance->FindUnrealComponentForNoesisComponent(InArgs.source);
	RoutedEvent = InArgs.routedEvent ? CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent)) : nullptr;
}

FNoesisGuiMouseEventArgs::FNoesisGuiMouseEventArgs(UNoesisGuiInstance* Instance, const Noesis::MouseEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	Position = FNoesisGuiDrawingPoint(InArgs.position);
	LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
}

FNoesisGuiMouseButtonEventArgs::FNoesisGuiMouseButtonEventArgs(UNoesisGuiInstance* Instance, const Noesis::MouseButtonEventArgs& InArgs)
	: FNoesisGuiMouseEventArgs(Instance, InArgs)
{
	ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	ButtonClicks = (int32)InArgs.buttonClicks;
}

FNoesisGuiMouseWheelEventArgs::FNoesisGuiMouseWheelEventArgs(UNoesisGuiInstance* Instance, const Noesis::MouseWheelEventArgs& InArgs)
	: FNoesisGuiMouseEventArgs(Instance, InArgs)
{
	WheelRotation = (int32)InArgs.wheelRotation;
}

FNoesisGuiTouchEventArgs::FNoesisGuiTouchEventArgs(UNoesisGuiInstance* Instance, const Noesis::TouchEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	TouchPoint = FNoesisGuiDrawingPoint(InArgs.touchPoint);
	TouchDevice = (int32)InArgs.touchDevice;
}

FNoesisGuiDragCompletedEventArgs::FNoesisGuiDragCompletedEventArgs(UNoesisGuiInstance* Instance, const Noesis::DragCompletedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	Canceled = InArgs.canceled;
	HorizontalChange = InArgs.horizontalChange;
	VerticalChange = InArgs.verticalChange;
}

FNoesisGuiDragStartedEventArgs::FNoesisGuiDragStartedEventArgs(UNoesisGuiInstance* Instance, const Noesis::DragStartedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	HorizontalOffset = InArgs.horizontalOffset;
	VerticalOffset = InArgs.verticalOffset;
}

FNoesisGuiSelectionChangedEventArgs::FNoesisGuiSelectionChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::SelectionChangedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
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

FNoesisGuiSizeChangedEventArgs::FNoesisGuiSizeChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::SizeChangedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	NewSize = FNoesisGuiDrawingSize(InArgs.sizeChangedInfo.newSize);
	PreviousSize = FNoesisGuiDrawingSize(InArgs.sizeChangedInfo.previousSize);
	WidthChanged = InArgs.sizeChangedInfo.widthChanged;
	HeightChanged = InArgs.sizeChangedInfo.heightChanged;
}

FNoesisGuiKeyboardFocusChangedEventArgs::FNoesisGuiKeyboardFocusChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	OldFocus = InArgs.oldFocus ? CastChecked<UNoesisGuiUIElement>(Instance->FindUnrealComponentForNoesisComponent(InArgs.oldFocus)) : nullptr;
	NewFocus = InArgs.newFocus ? CastChecked<UNoesisGuiUIElement>(Instance->FindUnrealComponentForNoesisComponent(InArgs.newFocus)) : nullptr;
}

FNoesisGuiScrollEventArgs::FNoesisGuiScrollEventArgs(UNoesisGuiInstance* Instance, const Noesis::ScrollEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	NewValue = InArgs.newValue;
	ScrollEventType = (ENoesisGuiScrollEventType)InArgs.scrollEventType;
}

FNoesisGuiTextCompositionEventArgs::FNoesisGuiTextCompositionEventArgs(UNoesisGuiInstance* Instance, const Noesis::TextCompositionEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	Character = (int32)InArgs.ch;
}

FNoesisGuiContextMenuEventArgs::FNoesisGuiContextMenuEventArgs(UNoesisGuiInstance* Instance, const Noesis::ContextMenuEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	Owner = InArgs.owner.GetPtr() ? CastChecked<UNoesisGuiUIElement>(Instance->FindUnrealComponentForNoesisComponent(InArgs.owner.GetPtr())) : nullptr;
	CursorLeft = InArgs.cursorLeft;
	CursorTop = InArgs.cursorTop;
}

FNoesisGuiKeyEventArgs::FNoesisGuiKeyEventArgs(UNoesisGuiInstance* Instance, const Noesis::KeyEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	Key = (ENoesisGuiKey)InArgs.key;
	KeyStates = (int32)InArgs.keyStates;
}

FNoesisGuiManipulationStartingEventArgs::FNoesisGuiManipulationStartingEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationStartingEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisGuiVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
	Mode = (ENoesisGuiManipulationModes)InArgs.mode;
	Cancel = InArgs.cancel;
}

void FNoesisGuiManipulationStartingEventArgs::ToNoesis(const Noesis::ManipulationStartingEventArgs& InArgs)
{
	InArgs.manipulationContainer = NsDynamicCast<Noesis::Ptr<Noesis::Gui::Visual> >(ManipulationContainer->NoesisComponent).GetPtr();
	InArgs.mode = (Noesis::ManipulationModes)Mode;
	InArgs.cancel = Cancel;
}

FNoesisGuiManipulationStartedEventArgs::FNoesisGuiManipulationStartedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationStartedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisGuiVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
	ManipulationOrigin = FNoesisGuiDrawingPoint(InArgs.manipulationOrigin);
	Cancel = InArgs.cancel;
	Complete = InArgs.complete;
}

void FNoesisGuiManipulationStartedEventArgs::ToNoesis(const Noesis::ManipulationStartedEventArgs& InArgs)
{
	InArgs.cancel = Cancel;
	InArgs.complete = Complete;
}

FNoesisGuiManipulationDelta::FNoesisGuiManipulationDelta(const Noesis::Gui::ManipulationDelta& ManipulationDelta)
{
	Expansion = FNoesisGuiDrawingPoint(ManipulationDelta.expansion);
	Rotation = ManipulationDelta.rotation;
	Scale = ManipulationDelta.scale;
	Translation = FNoesisGuiDrawingPoint(ManipulationDelta.translation);
}

Noesis::Gui::ManipulationDelta FNoesisGuiManipulationDelta::ToNoesis() const
{
	Noesis::Gui::ManipulationDelta ManipulationDelta;
	ManipulationDelta.expansion = Expansion.ToNoesis();
	ManipulationDelta.rotation = Rotation;
	ManipulationDelta.scale = Scale;
	ManipulationDelta.translation = Translation.ToNoesis();
	return ManipulationDelta;
}

FNoesisGuiManipulationVelocities::FNoesisGuiManipulationVelocities(const Noesis::Gui::ManipulationVelocities& ManipulationVelocities)
{
	AngularVelocity = ManipulationVelocities.angularVelocity;
	ExpansionVelocity = FNoesisGuiDrawingPoint(ManipulationVelocities.expansionVelocity);
	LinearVelocity = FNoesisGuiDrawingPoint(ManipulationVelocities.linearVelocity);
}

Noesis::Gui::ManipulationVelocities FNoesisGuiManipulationVelocities::ToNoesis() const
{
	Noesis::Gui::ManipulationVelocities ManipulationVelocities;
	ManipulationVelocities.angularVelocity = AngularVelocity;
	ManipulationVelocities.expansionVelocity = ExpansionVelocity.ToNoesis();
	ManipulationVelocities.linearVelocity = LinearVelocity.ToNoesis();
	return ManipulationVelocities;
}

FNoesisGuiManipulationDeltaEventArgs::FNoesisGuiManipulationDeltaEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationDeltaEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisGuiVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
	ManipulationOrigin = FNoesisGuiDrawingPoint(InArgs.manipulationOrigin);
	DeltaManipulation = FNoesisGuiManipulationDelta(InArgs.deltaManipulation);
	CumulativeManipulation = FNoesisGuiManipulationDelta(InArgs.cumulativeManipulation);
	Velocities = FNoesisGuiManipulationVelocities(InArgs.velocities);
	IsInertial = InArgs.isInertial;
	Cancel = InArgs.cancel;
	Complete = InArgs.complete;
}

void FNoesisGuiManipulationDeltaEventArgs::ToNoesis(const Noesis::ManipulationDeltaEventArgs& InArgs)
{
	InArgs.cancel = Cancel;
	InArgs.complete = Complete;
}

FNoesisGuiInertiaExpansionBehavior::FNoesisGuiInertiaExpansionBehavior(const Noesis::Gui::InertiaExpansionBehavior& InertiaExpansionBehavior)
{
	DesiredDeceleration = InertiaExpansionBehavior.desiredDeceleration;
}

Noesis::Gui::InertiaExpansionBehavior FNoesisGuiInertiaExpansionBehavior::ToNoesis() const
{
	return Noesis::Gui::InertiaExpansionBehavior{ DesiredDeceleration };
}

FNoesisGuiInertiaRotationBehavior::FNoesisGuiInertiaRotationBehavior(const Noesis::Gui::InertiaRotationBehavior& InertiaRotationBehavior)
{
	DesiredDeceleration = InertiaRotationBehavior.desiredDeceleration;
}

Noesis::Gui::InertiaRotationBehavior FNoesisGuiInertiaRotationBehavior::ToNoesis() const
{
	return Noesis::Gui::InertiaRotationBehavior{ DesiredDeceleration };
}

FNoesisGuiInertiaTranslationBehavior::FNoesisGuiInertiaTranslationBehavior(const Noesis::Gui::InertiaTranslationBehavior& InertiaTranslationBehavior)
{
	DesiredDeceleration = InertiaTranslationBehavior.desiredDeceleration;
}

Noesis::Gui::InertiaTranslationBehavior FNoesisGuiInertiaTranslationBehavior::ToNoesis() const
{
	return Noesis::Gui::InertiaTranslationBehavior{ DesiredDeceleration };
}

FNoesisGuiManipulationInertiaStartingEventArgs::FNoesisGuiManipulationInertiaStartingEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationInertiaStartingEventArgs& InArgs)
: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisGuiVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
	ManipulationOrigin = FNoesisGuiDrawingPoint(InArgs.manipulationOrigin);
	InitialVelocities = FNoesisGuiManipulationVelocities(InArgs.initialVelocities);
	RotationBehavior = FNoesisGuiInertiaRotationBehavior(InArgs.rotationBehavior);
	ExpansionBehavior = FNoesisGuiInertiaExpansionBehavior(InArgs.expansionBehavior);
	TranslationBehavior = FNoesisGuiInertiaTranslationBehavior(InArgs.translationBehavior);
	Cancel = InArgs.cancel;
}

void FNoesisGuiManipulationInertiaStartingEventArgs::ToNoesis(const Noesis::ManipulationInertiaStartingEventArgs& InArgs)
{
	InArgs.initialVelocities = InitialVelocities.ToNoesis();
	InArgs.rotationBehavior = RotationBehavior.ToNoesis();
	InArgs.expansionBehavior = ExpansionBehavior.ToNoesis();
	InArgs.translationBehavior = TranslationBehavior.ToNoesis();
	InArgs.cancel = Cancel;
}

FNoesisGuiManipulationCompletedEventArgs::FNoesisGuiManipulationCompletedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ManipulationCompletedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	ManipulationContainer = InArgs.manipulationContainer ? CastChecked<UNoesisGuiVisual>(Instance->FindUnrealComponentForNoesisComponent(InArgs.manipulationContainer)) : nullptr;
	ManipulationOrigin = FNoesisGuiDrawingPoint(InArgs.manipulationOrigin);
	FinalVelocities = FNoesisGuiManipulationVelocities(InArgs.finalVelocities);
	TotalManipulation = FNoesisGuiManipulationDelta(InArgs.totalManipulation);
	IsInertial = InArgs.isInertial;
	Cancel = InArgs.cancel;
}

void FNoesisGuiManipulationCompletedEventArgs::ToNoesis(const Noesis::ManipulationCompletedEventArgs& InArgs)
{
	InArgs.cancel = Cancel;
}

FNoesisGuiScrollChangedEventArgs::FNoesisGuiScrollChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ScrollChangedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
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

FNoesisGuiToolTipEventArgs::FNoesisGuiToolTipEventArgs(UNoesisGuiInstance* Instance, const Noesis::ToolTipEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
}

FNoesisGuiDragDeltaEventArgs::FNoesisGuiDragDeltaEventArgs(UNoesisGuiInstance* Instance, const Noesis::DragDeltaEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	HorizontalChange = InArgs.horizontalChange;
	VerticalChange = InArgs.verticalChange;
}

FNoesisGuiFloatPropertyChangedEventArgs::FNoesisGuiFloatPropertyChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::RoutedPropertyChangedEventArgs<NsFloat32>& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	OldValue = InArgs.oldValue;
	NewValue = InArgs.newValue;
}

FNoesisGuiBaseComponentPropertyChangedEventArgs::FNoesisGuiBaseComponentPropertyChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::RoutedPropertyChangedEventArgs<Noesis::Ptr<Noesis::BaseComponent> >& InArgs)
: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	OldValue = Instance->FindUnrealComponentForNoesisComponent(InArgs.oldValue.GetPtr());
	NewValue = Instance->FindUnrealComponentForNoesisComponent(InArgs.newValue.GetPtr());
}

FNoesisGuiCanExecuteRoutedEventArgs::FNoesisGuiCanExecuteRoutedEventArgs(UNoesisGuiInstance* Instance, const Noesis::CanExecuteRoutedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs) 
{
	// Command =
	Parameter = Instance->FindUnrealComponentForNoesisComponent(InArgs.parameter.GetPtr());
	CanExecute = InArgs.canExecute;
	ContinueRouting = InArgs.continueRouting;
}

void FNoesisGuiCanExecuteRoutedEventArgs::ToNoesis(const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	InArgs.canExecute = CanExecute;
	InArgs.continueRouting = ContinueRouting;
}

FNoesisGuiExecutedRoutedEventArgs::FNoesisGuiExecutedRoutedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ExecutedRoutedEventArgs& InArgs)
	: FNoesisGuiRoutedEventArgs(Instance, InArgs)
{
	// Command =
	Parameter = Instance->FindUnrealComponentForNoesisComponent(InArgs.parameter.GetPtr());
}

FNoesisGuiEventArgs::FNoesisGuiEventArgs(UNoesisGuiInstance* Instance, const Noesis::EventArgs& InArgs)
{
}

FNoesisGuiTimelineEventArgs::FNoesisGuiTimelineEventArgs(UNoesisGuiInstance* Instance, const Noesis::TimelineEventArgs& InArgs)
	: FNoesisGuiEventArgs(Instance, InArgs)
{
	Target = InArgs.target ? CastChecked<UNoesisGuiDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(InArgs.target)) : nullptr;
}

FNoesisGuiGeneratorPosition::FNoesisGuiGeneratorPosition(const Noesis::Gui::GeneratorPosition& GeneratorPosition)
{
	Index = GeneratorPosition.index;
	Offset = GeneratorPosition.offset;
}

Noesis::Gui::GeneratorPosition FNoesisGuiGeneratorPosition::ToNoesis() const
{
	return Noesis::Gui::GeneratorPosition(Index, Offset);
}

FNoesisGuiItemsChangedEventArgs::FNoesisGuiItemsChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::ItemsChangedEventArgs& InArgs)
{
	Action = (ENoesisGuiNotifyCollectionChangedAction)InArgs.action;
	Position = FNoesisGuiGeneratorPosition(InArgs.position);
	OldPosition = FNoesisGuiGeneratorPosition(InArgs.oldPosition);
	ItemCount = InArgs.itemCount;
	ItemUICount = InArgs.itemUICount;
}

FNoesisGuiDependencyPropertyChangedEventArgs::FNoesisGuiDependencyPropertyChangedEventArgs(UNoesisGuiInstance* Instance, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	Prop = InArgs.prop ? CastChecked<UNoesisGuiDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(InArgs.prop)) : nullptr;
}
