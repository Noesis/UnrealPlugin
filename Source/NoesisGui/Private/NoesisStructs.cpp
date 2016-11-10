////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisStructs.h"
#include "NoesisInstance.h"
#include "NoesisGeneratedClasses.h"

FNoesisObjectWithNameScope::FNoesisObjectWithNameScope(UNoesisInstance* Instance, const Noesis::Gui::ObjectWithNameScope& ObjectWithScope)
{
	Object = Instance->FindUnrealComponentForNoesisComponent(ObjectWithScope.object);
	Scope = ObjectWithScope.scope ? CastChecked<UNoesisINameScope>(Instance->FindUnrealInterfaceForNoesisInterface(ObjectWithScope.scope)) : nullptr;
}

FNoesisDrawingSize::FNoesisDrawingSize(const Noesis::Drawing::Size& Size)
{
	Width = Size.width;
	Height = Size.height;
}

Noesis::Drawing::Size FNoesisDrawingSize::ToNoesis() const
{
	return Noesis::Drawing::Size(Width, Height);
}

FNoesisDrawingRect::FNoesisDrawingRect(const Noesis::Drawing::Rect& Rect)
{
	X = Rect.x;
	Y = Rect.y;
	Width = Rect.width;
	Height = Rect.height;
}

Noesis::Drawing::Rect FNoesisDrawingRect::ToNoesis() const
{
	return Noesis::Drawing::Rect(X, Y, Width, Height);
}

FNoesisDrawingPoint::FNoesisDrawingPoint(const Noesis::Drawing::Point& Point)
{
	X = Point.x;
	Y = Point.y;
}

Noesis::Drawing::Point FNoesisDrawingPoint::ToNoesis() const
{
	return Noesis::Drawing::Point(X, Y);
}

FNoesisDrawingCornerRadius::FNoesisDrawingCornerRadius(const Noesis::Drawing::CornerRadius& CornerRadius)
{
	TopLeft = CornerRadius.topLeft;
	TopRight = CornerRadius.topRight;
	BottomRight = CornerRadius.bottomRight;
	BottomLeft = CornerRadius.bottomLeft;
}

Noesis::Drawing::CornerRadius FNoesisDrawingCornerRadius::ToNoesis() const
{
	return Noesis::Drawing::CornerRadius(TopLeft, TopRight, BottomRight, BottomLeft);
}

FNoesisDrawingThickness::FNoesisDrawingThickness(const Noesis::Drawing::Thickness& Thickness)
{
	Left = Thickness.left;
	Top = Thickness.top;
	Right = Thickness.right;
	Bottom = Thickness.bottom;
}

Noesis::Drawing::Thickness FNoesisDrawingThickness::ToNoesis() const
{
	return Noesis::Drawing::Thickness(Left, Top, Right, Bottom);
}

FNoesisDrawingColor::FNoesisDrawingColor(const Noesis::Drawing::Color& Color)
{
	Color.ToLinearRGB(Red, Green, Blue, Alpha);
}

Noesis::Drawing::Color FNoesisDrawingColor::ToNoesis() const
{
	return Noesis::Drawing::Color(Red, Green, Blue, Alpha);
}

FNoesisDrawingSizei::FNoesisDrawingSizei(const Noesis::Drawing::Sizei& Size)
{
	Width = Size.width;
	Height = Size.height;
}

Noesis::Drawing::Sizei FNoesisDrawingSizei::ToNoesis() const
{
	return Noesis::Drawing::Sizei(Width, Height);
}

FNoesisDrawingRecti::FNoesisDrawingRecti(const Noesis::Drawing::Recti& Rect)
{
	X = Rect.x;
	Y = Rect.y;
	Width = Rect.width;
	Height = Rect.height;
}

Noesis::Drawing::Recti FNoesisDrawingRecti::ToNoesis() const
{
	return Noesis::Drawing::Recti(X, Y, Width, Height);
}

FNoesisDrawingPointi::FNoesisDrawingPointi(const Noesis::Drawing::Pointi& Point)
{
	X = Point.x;
	Y = Point.y;
}

Noesis::Drawing::Pointi FNoesisDrawingPointi::ToNoesis() const
{
	return Noesis::Drawing::Pointi(X, Y);
}

FNoesisDuration::FNoesisDuration(const Noesis::Gui::Duration& Duration)
{
	DurationType = (ENoesisDurationType)Duration.GetDurationType();
	Milliseconds = (int32)Duration.GetTimeSpan().GetMilliseconds();
}

Noesis::Gui::Duration FNoesisDuration::ToNoesis() const
{
	if (DurationType == ENoesisDurationType::Automatic)
	{
		return Noesis::Gui::Duration::Automatic();
	}
	else if (DurationType == ENoesisDurationType::Forever)
	{
		return Noesis::Gui::Duration::Forever();
	}
	return Noesis::Gui::Duration(Noesis::Gui::TimeSpan(0, 0, 0, 0, Milliseconds));
}

FNoesisRepeatBehavior::FNoesisRepeatBehavior(const Noesis::RepeatBehavior& RepeatBehavior)
{
	TextForm = NsStringToFString(RepeatBehavior.ToString().c_str());
}

Noesis::RepeatBehavior FNoesisRepeatBehavior::ToNoesis()
{
	Noesis::RepeatBehavior RepeatBehavior;
	Noesis::RepeatBehavior::TryParse(StringCast<NsChar>(*TextForm).Get(), RepeatBehavior);
	return RepeatBehavior;
}

FNoesisGridLength::FNoesisGridLength(const Noesis::GridLength& GridLength)
{
	TextForm = NsStringToFString(GridLength.ToString().c_str());
}

Noesis::GridLength FNoesisGridLength::ToNoesis()
{
	Noesis::GridLength GridLength;
	Noesis::GridLength::TryParse(StringCast<NsChar>(*TextForm).Get(), GridLength);
	return GridLength;
}

FNoesisKeyTime::FNoesisKeyTime(const Noesis::KeyTime& KeyTime)
{
	TextForm = NsStringToFString(KeyTime.ToString().c_str());
}

Noesis::KeyTime FNoesisKeyTime::ToNoesis()
{
	Noesis::KeyTime KeyTime;
	Noesis::KeyTime::TryParse(StringCast<NsChar>(*TextForm).Get(), KeyTime);
	return KeyTime;
}

FNoesisManipulationDelta::FNoesisManipulationDelta(const Noesis::Gui::ManipulationDelta& ManipulationDelta)
{
	Expansion = FNoesisDrawingPoint(ManipulationDelta.expansion);
	Rotation = ManipulationDelta.rotation;
	Scale = ManipulationDelta.scale;
	Translation = FNoesisDrawingPoint(ManipulationDelta.translation);
}

Noesis::Gui::ManipulationDelta FNoesisManipulationDelta::ToNoesis() const
{
	Noesis::Gui::ManipulationDelta ManipulationDelta;
	ManipulationDelta.expansion = Expansion.ToNoesis();
	ManipulationDelta.rotation = Rotation;
	ManipulationDelta.scale = Scale;
	ManipulationDelta.translation = Translation.ToNoesis();
	return ManipulationDelta;
}

FNoesisManipulationVelocities::FNoesisManipulationVelocities(const Noesis::Gui::ManipulationVelocities& ManipulationVelocities)
{
	AngularVelocity = ManipulationVelocities.angularVelocity;
	ExpansionVelocity = FNoesisDrawingPoint(ManipulationVelocities.expansionVelocity);
	LinearVelocity = FNoesisDrawingPoint(ManipulationVelocities.linearVelocity);
}

Noesis::Gui::ManipulationVelocities FNoesisManipulationVelocities::ToNoesis() const
{
	Noesis::Gui::ManipulationVelocities ManipulationVelocities;
	ManipulationVelocities.angularVelocity = AngularVelocity;
	ManipulationVelocities.expansionVelocity = ExpansionVelocity.ToNoesis();
	ManipulationVelocities.linearVelocity = LinearVelocity.ToNoesis();
	return ManipulationVelocities;
}

FNoesisInertiaExpansionBehavior::FNoesisInertiaExpansionBehavior(const Noesis::Gui::InertiaExpansionBehavior& InertiaExpansionBehavior)
{
	DesiredDeceleration = InertiaExpansionBehavior.desiredDeceleration;
}

Noesis::Gui::InertiaExpansionBehavior FNoesisInertiaExpansionBehavior::ToNoesis() const
{
	return Noesis::Gui::InertiaExpansionBehavior{ DesiredDeceleration };
}

FNoesisInertiaRotationBehavior::FNoesisInertiaRotationBehavior(const Noesis::Gui::InertiaRotationBehavior& InertiaRotationBehavior)
{
	DesiredDeceleration = InertiaRotationBehavior.desiredDeceleration;
}

Noesis::Gui::InertiaRotationBehavior FNoesisInertiaRotationBehavior::ToNoesis() const
{
	return Noesis::Gui::InertiaRotationBehavior{ DesiredDeceleration };
}

FNoesisInertiaTranslationBehavior::FNoesisInertiaTranslationBehavior(const Noesis::Gui::InertiaTranslationBehavior& InertiaTranslationBehavior)
{
	DesiredDeceleration = InertiaTranslationBehavior.desiredDeceleration;
}

Noesis::Gui::InertiaTranslationBehavior FNoesisInertiaTranslationBehavior::ToNoesis() const
{
	return Noesis::Gui::InertiaTranslationBehavior{ DesiredDeceleration };
}

FNoesisGeneratorPosition::FNoesisGeneratorPosition(const Noesis::Gui::GeneratorPosition& GeneratorPosition)
{
	Index = GeneratorPosition.index;
	Offset = GeneratorPosition.offset;
}

Noesis::Gui::GeneratorPosition FNoesisGeneratorPosition::ToNoesis() const
{
	return Noesis::Gui::GeneratorPosition(Index, Offset);
}
