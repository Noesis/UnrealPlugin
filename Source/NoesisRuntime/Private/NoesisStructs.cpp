////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisStructs.h"

// NoesisRuntime includes
#include "NoesisSupport.h"

FNoesisSize::FNoesisSize(const Noesis::Size& Size)
{
	Width = Size.width;
	Height = Size.height;
}

Noesis::Size FNoesisSize::ToNoesis() const
{
	return Noesis::Size(Width, Height);
}

FNoesisRect::FNoesisRect(const Noesis::Rect& Rect)
{
	X = Rect.x;
	Y = Rect.y;
	Width = Rect.width;
	Height = Rect.height;
}

Noesis::Rect FNoesisRect::ToNoesis() const
{
	return Noesis::Rect(X, Y, Width, Height);
}

FNoesisPoint::FNoesisPoint(const Noesis::Point& Point)
{
	X = Point.x;
	Y = Point.y;
}

Noesis::Point FNoesisPoint::ToNoesis() const
{
	return Noesis::Point(X, Y);
}

FNoesisCornerRadius::FNoesisCornerRadius(const Noesis::CornerRadius& CornerRadius)
{
	TopLeft = CornerRadius.topLeft;
	TopRight = CornerRadius.topRight;
	BottomRight = CornerRadius.bottomRight;
	BottomLeft = CornerRadius.bottomLeft;
}

Noesis::CornerRadius FNoesisCornerRadius::ToNoesis() const
{
	return Noesis::CornerRadius(TopLeft, TopRight, BottomRight, BottomLeft);
}

FNoesisThickness::FNoesisThickness(const Noesis::Thickness& Thickness)
{
	Left = Thickness.left;
	Top = Thickness.top;
	Right = Thickness.right;
	Bottom = Thickness.bottom;
}

Noesis::Thickness FNoesisThickness::ToNoesis() const
{
	return Noesis::Thickness(Left, Top, Right, Bottom);
}

FNoesisColor::FNoesisColor(const Noesis::Color& Color)
{
	Color.ToLinearRGB(Red, Green, Blue, Alpha);
}

Noesis::Color FNoesisColor::ToNoesis() const
{
	return Noesis::Color(Red, Green, Blue, Alpha);
}

FNoesisSizei::FNoesisSizei(const Noesis::Sizei& Size)
{
	Width = Size.width;
	Height = Size.height;
}

Noesis::Sizei FNoesisSizei::ToNoesis() const
{
	return Noesis::Sizei(Width, Height);
}

FNoesisRecti::FNoesisRecti(const Noesis::Recti& Rect)
{
	X = Rect.x;
	Y = Rect.y;
	Width = Rect.width;
	Height = Rect.height;
}

Noesis::Recti FNoesisRecti::ToNoesis() const
{
	return Noesis::Recti(X, Y, Width, Height);
}

FNoesisPointi::FNoesisPointi(const Noesis::Pointi& Point)
{
	X = Point.x;
	Y = Point.y;
}

Noesis::Pointi FNoesisPointi::ToNoesis() const
{
	return Noesis::Pointi(X, Y);
}

FNoesisDuration::FNoesisDuration(const Noesis::Duration& Duration)
{
	DurationType = (ENoesisDurationType)Duration.GetDurationType();
	Milliseconds = (int32)Duration.GetTimeSpan().GetMilliseconds();
}

Noesis::Duration FNoesisDuration::ToNoesis() const
{
	if (DurationType == ENoesisDurationType::Automatic)
	{
		return Noesis::Duration::Automatic();
	}
	else if (DurationType == ENoesisDurationType::Forever)
	{
		return Noesis::Duration::Forever();
	}
	return Noesis::Duration(Noesis::TimeSpan(0, 0, 0, 0, Milliseconds));
}

FNoesisRepeatBehavior::FNoesisRepeatBehavior(const Noesis::RepeatBehavior& RepeatBehavior)
{
	TextForm = NsStringToFString(RepeatBehavior.ToString().c_str());
}

Noesis::RepeatBehavior FNoesisRepeatBehavior::ToNoesis()
{
	Noesis::RepeatBehavior RepeatBehavior;
	Noesis::RepeatBehavior::TryParse(TCHARToNsString(*TextForm).c_str(), RepeatBehavior);
	return RepeatBehavior;
}

FNoesisGridLength::FNoesisGridLength(const Noesis::GridLength& GridLength)
{
	TextForm = NsStringToFString(GridLength.ToString().c_str());
}

Noesis::GridLength FNoesisGridLength::ToNoesis()
{
	Noesis::GridLength GridLength;
	Noesis::GridLength::TryParse(TCHARToNsString(*TextForm).c_str(), GridLength);
	return GridLength;
}

FNoesisKeyTime::FNoesisKeyTime(const Noesis::KeyTime& KeyTime)
{
	TextForm = NsStringToFString(KeyTime.ToString().c_str());
}

Noesis::KeyTime FNoesisKeyTime::ToNoesis() const
{
	Noesis::KeyTime KeyTime;
	Noesis::KeyTime::TryParse(TCHARToNsString(*TextForm).c_str(), KeyTime);
	return KeyTime;
}

FNoesisTimeSpan::FNoesisTimeSpan(const Noesis::TimeSpan& TimeSpan)
{
	Days = TimeSpan.GetDays();
	Hours = TimeSpan.GetHours();
	Minutes = TimeSpan.GetMinutes();
	Seconds = TimeSpan.GetSeconds();
	Milliseconds = TimeSpan.GetMilliseconds();
}

Noesis::TimeSpan FNoesisTimeSpan::ToNoesis() const
{
	return Noesis::TimeSpan(Days, Hours, Minutes, Seconds, Milliseconds);
}

FNoesisManipulationDelta::FNoesisManipulationDelta(const Noesis::ManipulationDelta& ManipulationDelta)
{
	Expansion = FNoesisPoint(ManipulationDelta.expansion);
	Rotation = ManipulationDelta.rotation;
	Scale = ManipulationDelta.scale;
	Translation = FNoesisPoint(ManipulationDelta.translation);
}

Noesis::ManipulationDelta FNoesisManipulationDelta::ToNoesis() const
{
	Noesis::ManipulationDelta ManipulationDelta;
	ManipulationDelta.expansion = Expansion.ToNoesis();
	ManipulationDelta.rotation = Rotation;
	ManipulationDelta.scale = Scale;
	ManipulationDelta.translation = Translation.ToNoesis();
	return ManipulationDelta;
}

FNoesisManipulationVelocities::FNoesisManipulationVelocities(const Noesis::ManipulationVelocities& ManipulationVelocities)
{
	AngularVelocity = ManipulationVelocities.angularVelocity;
	ExpansionVelocity = FNoesisPoint(ManipulationVelocities.expansionVelocity);
	LinearVelocity = FNoesisPoint(ManipulationVelocities.linearVelocity);
}

Noesis::ManipulationVelocities FNoesisManipulationVelocities::ToNoesis() const
{
	Noesis::ManipulationVelocities ManipulationVelocities;
	ManipulationVelocities.angularVelocity = AngularVelocity;
	ManipulationVelocities.expansionVelocity = ExpansionVelocity.ToNoesis();
	ManipulationVelocities.linearVelocity = LinearVelocity.ToNoesis();
	return ManipulationVelocities;
}

FNoesisInertiaExpansionBehavior::FNoesisInertiaExpansionBehavior(const Noesis::InertiaExpansionBehavior& InertiaExpansionBehavior)
{
	DesiredDeceleration = InertiaExpansionBehavior.desiredDeceleration;
}

Noesis::InertiaExpansionBehavior FNoesisInertiaExpansionBehavior::ToNoesis() const
{
	return Noesis::InertiaExpansionBehavior{ DesiredDeceleration };
}

FNoesisInertiaRotationBehavior::FNoesisInertiaRotationBehavior(const Noesis::InertiaRotationBehavior& InertiaRotationBehavior)
{
	DesiredDeceleration = InertiaRotationBehavior.desiredDeceleration;
}

Noesis::InertiaRotationBehavior FNoesisInertiaRotationBehavior::ToNoesis() const
{
	return Noesis::InertiaRotationBehavior{ DesiredDeceleration };
}

FNoesisInertiaTranslationBehavior::FNoesisInertiaTranslationBehavior(const Noesis::InertiaTranslationBehavior& InertiaTranslationBehavior)
{
	DesiredDeceleration = InertiaTranslationBehavior.desiredDeceleration;
}

Noesis::InertiaTranslationBehavior FNoesisInertiaTranslationBehavior::ToNoesis() const
{
	return Noesis::InertiaTranslationBehavior{ DesiredDeceleration };
}

FNoesisGeneratorPosition::FNoesisGeneratorPosition(const Noesis::GeneratorPosition& GeneratorPosition)
{
	Index = GeneratorPosition.index;
	Offset = GeneratorPosition.offset;
}

Noesis::GeneratorPosition FNoesisGeneratorPosition::ToNoesis() const
{
	return Noesis::GeneratorPosition(Index, Offset);
}
