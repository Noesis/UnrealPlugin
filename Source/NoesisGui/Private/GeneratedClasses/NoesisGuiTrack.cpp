////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTrack.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTrack::UNoesisGuiTrack(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTrack::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(InNoesisComponent);
	check(NoesisTrack);
}

class UNoesisGuiRepeatButton* UNoesisGuiTrack::GetDecreaseRepeatButton()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return CastChecked<UNoesisGuiRepeatButton>(Instance->FindUnrealComponentForNoesisComponent(NoesisTrack->GetDecreaseRepeatButton()));
}

void UNoesisGuiTrack::SetDecreaseRepeatButton(class UNoesisGuiRepeatButton* InDecreaseRepeatButton)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetDecreaseRepeatButton(NsDynamicCast<RepeatButton*>(InDecreaseRepeatButton->NoesisComponent.GetPtr()));
}

class UNoesisGuiRepeatButton* UNoesisGuiTrack::GetIncreaseRepeatButton()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return CastChecked<UNoesisGuiRepeatButton>(Instance->FindUnrealComponentForNoesisComponent(NoesisTrack->GetIncreaseRepeatButton()));
}

void UNoesisGuiTrack::SetIncreaseRepeatButton(class UNoesisGuiRepeatButton* InIncreaseRepeatButton)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetIncreaseRepeatButton(NsDynamicCast<RepeatButton*>(InIncreaseRepeatButton->NoesisComponent.GetPtr()));
}

class UNoesisGuiThumb* UNoesisGuiTrack::GetThumb()
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	return CastChecked<UNoesisGuiThumb>(Instance->FindUnrealComponentForNoesisComponent(NoesisTrack->GetThumb()));
}

void UNoesisGuiTrack::SetThumb(class UNoesisGuiThumb* InThumb)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NoesisTrack->SetThumb(NsDynamicCast<Thumb*>(InThumb->NoesisComponent.GetPtr()));
}

float UNoesisGuiTrack::ValueFromDistance(float InHorizontal, float InVertical)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	NsFloat32 NoesisInHorizontal = InHorizontal;
	NsFloat32 NoesisInVertical = InVertical;
	return (float)NoesisTrack->ValueFromDistance(NoesisInHorizontal, NoesisInVertical);
}

float UNoesisGuiTrack::ValueFromPoint(FNoesisGuiDrawingPoint InPoint)
{
	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack);
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return (float)NoesisTrack->ValueFromPoint(NoesisInPoint);
}

void UNoesisGuiTrack::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack)


}

void UNoesisGuiTrack::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Track* NoesisTrack = NsDynamicCast<Noesis::Gui::Track*>(NoesisComponent.GetPtr());
	check(NoesisTrack)


}

