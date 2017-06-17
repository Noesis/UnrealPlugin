////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisTrack.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisTrack::UNoesisTrack(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Track::StaticGetClassType();
}

void UNoesisTrack::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(InNoesisComponent);
	check(NoesisTrack);
}

class UNoesisRepeatButton* UNoesisTrack::GetDecreaseRepeatButton()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return CastChecked<UNoesisRepeatButton>(CreateClassFor(NoesisTrack->GetDecreaseRepeatButton(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTrack::SetDecreaseRepeatButton(class UNoesisRepeatButton* InDecreaseRepeatButton)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetDecreaseRepeatButton(NsDynamicCast<RepeatButton*>(InDecreaseRepeatButton->NoesisComponent.GetPtr()));
}

class UNoesisRepeatButton* UNoesisTrack::GetIncreaseRepeatButton()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return CastChecked<UNoesisRepeatButton>(CreateClassFor(NoesisTrack->GetIncreaseRepeatButton(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTrack::SetIncreaseRepeatButton(class UNoesisRepeatButton* InIncreaseRepeatButton)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetIncreaseRepeatButton(NsDynamicCast<RepeatButton*>(InIncreaseRepeatButton->NoesisComponent.GetPtr()));
}

bool UNoesisTrack::GetIsDirectionReversed()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return NoesisTrack->GetIsDirectionReversed();
}

void UNoesisTrack::SetIsDirectionReversed(bool InIsDirectionReversed)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetIsDirectionReversed(InIsDirectionReversed);
}

float UNoesisTrack::GetMaximum()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return (float)NoesisTrack->GetMaximum();
}

void UNoesisTrack::SetMaximum(float InMaximum)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetMaximum(InMaximum);
}

float UNoesisTrack::GetMinimum()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return (float)NoesisTrack->GetMinimum();
}

void UNoesisTrack::SetMinimum(float InMinimum)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetMinimum(InMinimum);
}

ENoesisOrientation UNoesisTrack::GetOrientation()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return (ENoesisOrientation)NoesisTrack->GetOrientation();
}

void UNoesisTrack::SetOrientation(ENoesisOrientation InOrientation)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetOrientation((Noesis::Gui::Orientation)InOrientation);
}

class UNoesisThumb* UNoesisTrack::GetThumb()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return CastChecked<UNoesisThumb>(CreateClassFor(NoesisTrack->GetThumb(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTrack::SetThumb(class UNoesisThumb* InThumb)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetThumb(NsDynamicCast<Thumb*>(InThumb->NoesisComponent.GetPtr()));
}

float UNoesisTrack::GetValue()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return (float)NoesisTrack->GetValue();
}

void UNoesisTrack::SetValue(float InValue)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetValue(InValue);
}

float UNoesisTrack::GetViewportSize()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return (float)NoesisTrack->GetViewportSize();
}

void UNoesisTrack::SetViewportSize(float InViewportSize)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetViewportSize(InViewportSize);
}

float UNoesisTrack::ValueFromDistance(float InHorizontal, float InVertical)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NsFloat32 NoesisInHorizontal = InHorizontal;
	NsFloat32 NoesisInVertical = InVertical;
	return (float)NoesisTrack->ValueFromDistance(NoesisInHorizontal, NoesisInVertical);
}

float UNoesisTrack::ValueFromPoint(FNoesisDrawingPoint InPoint)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return (float)NoesisTrack->ValueFromPoint(NoesisInPoint);
}

void UNoesisTrack::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);


}

void UNoesisTrack::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);


}

