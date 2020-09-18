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

FNoesisKeyTime::FNoesisKeyTime(const Noesis::KeyTime& KeyTime)
{
	TextForm = NsStringToFString(KeyTime.ToString().Str());
}

Noesis::KeyTime FNoesisKeyTime::ToNoesis() const
{
	Noesis::KeyTime KeyTime;
	Noesis::KeyTime::TryParse(TCHARToNsString(*TextForm).Str(), KeyTime);
	return KeyTime;
}
