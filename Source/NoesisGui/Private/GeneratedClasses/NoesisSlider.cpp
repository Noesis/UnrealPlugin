////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisSlider.h"

using namespace Noesis;
using namespace Gui;

UNoesisSlider::UNoesisSlider(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Slider::StaticGetClassType();
}

void UNoesisSlider::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(InNoesisComponent);
	check(NoesisSlider);
}

int32 UNoesisSlider::GetDelay()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return NoesisSlider->GetDelay();
}

void UNoesisSlider::SetDelay(int32 InDelay)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetDelay(InDelay);
}

int32 UNoesisSlider::GetInterval()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return NoesisSlider->GetInterval();
}

void UNoesisSlider::SetInterval(int32 InInterval)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetInterval(InInterval);
}

bool UNoesisSlider::GetIsDirectionReversed()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return NoesisSlider->GetIsDirectionReversed();
}

void UNoesisSlider::SetIsDirectionReversed(bool InIsDirectionReversed)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetIsDirectionReversed(InIsDirectionReversed);
}

bool UNoesisSlider::GetIsMoveToPointEnabled()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return NoesisSlider->GetIsMoveToPointEnabled();
}

void UNoesisSlider::SetIsMoveToPointEnabled(bool InIsMoveToPointEnabled)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetIsMoveToPointEnabled(InIsMoveToPointEnabled);
}

bool UNoesisSlider::GetIsSelectionRangeEnabled()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return NoesisSlider->GetIsSelectionRangeEnabled();
}

void UNoesisSlider::SetIsSelectionRangeEnabled(bool InIsSelectionRangeEnabled)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetIsSelectionRangeEnabled(InIsSelectionRangeEnabled);
}

bool UNoesisSlider::GetIsSnapToTickEnabled()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return NoesisSlider->GetIsSnapToTickEnabled();
}

void UNoesisSlider::SetIsSnapToTickEnabled(bool InIsSnapToTickEnabled)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetIsSnapToTickEnabled(InIsSnapToTickEnabled);
}

ENoesisOrientation UNoesisSlider::GetOrientation()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return (ENoesisOrientation)NoesisSlider->GetOrientation();
}

void UNoesisSlider::SetOrientation(ENoesisOrientation InOrientation)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetOrientation((Noesis::Gui::Orientation)InOrientation);
}

float UNoesisSlider::GetSelectionEnd()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return (float)NoesisSlider->GetSelectionEnd();
}

void UNoesisSlider::SetSelectionEnd(float InSelectionEnd)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetSelectionEnd(InSelectionEnd);
}

float UNoesisSlider::GetSelectionStart()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return (float)NoesisSlider->GetSelectionStart();
}

void UNoesisSlider::SetSelectionStart(float InSelectionStart)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetSelectionStart(InSelectionStart);
}

float UNoesisSlider::GetTickFrequency()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return (float)NoesisSlider->GetTickFrequency();
}

void UNoesisSlider::SetTickFrequency(float InTickFrequency)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetTickFrequency(InTickFrequency);
}

ENoesisTickPlacement UNoesisSlider::GetTickPlacement()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return (ENoesisTickPlacement)NoesisSlider->GetTickPlacement();
}

void UNoesisSlider::SetTickPlacement(ENoesisTickPlacement InTickPlacement)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetTickPlacement((Noesis::Gui::TickPlacement)InTickPlacement);
}

FString UNoesisSlider::GetTicks()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	return NsStringToFString(NoesisSlider->GetTicks());
}

void UNoesisSlider::SetTicks(FString InTicks)
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);
	NoesisSlider->SetTicks(StringCast<NsChar>(*InTicks).Get());
}

void UNoesisSlider::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);


}

void UNoesisSlider::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	check(NoesisSlider);


}

