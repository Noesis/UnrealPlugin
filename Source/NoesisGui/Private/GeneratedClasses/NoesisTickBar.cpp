////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTickBar.h"

using namespace Noesis;
using namespace Gui;

UNoesisTickBar::UNoesisTickBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTickBar::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(InNoesisComponent);
	check(NoesisTickBar);
}

class UNoesisBrush* UNoesisTickBar::GetFill()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisTickBar->GetFill()));
}

void UNoesisTickBar::SetFill(class UNoesisBrush* InFill)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetFill(NsDynamicCast<Brush*>(InFill->NoesisComponent.GetPtr()));
}

bool UNoesisTickBar::GetIsDirectionReversed()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return NoesisTickBar->GetIsDirectionReversed();
}

void UNoesisTickBar::SetIsDirectionReversed(bool InIsDirectionReversed)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetIsDirectionReversed(InIsDirectionReversed);
}

bool UNoesisTickBar::GetIsSelectionRangeEnabled()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return NoesisTickBar->GetIsSelectionRangeEnabled();
}

void UNoesisTickBar::SetIsSelectionRangeEnabled(bool InIsSelectionRangeEnabled)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetIsSelectionRangeEnabled(InIsSelectionRangeEnabled);
}

float UNoesisTickBar::GetMaximum()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return (float)NoesisTickBar->GetMaximum();
}

void UNoesisTickBar::SetMaximum(float InMaximum)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetMaximum(InMaximum);
}

float UNoesisTickBar::GetMinimum()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return (float)NoesisTickBar->GetMinimum();
}

void UNoesisTickBar::SetMinimum(float InMinimum)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetMinimum(InMinimum);
}

ENoesisTickBarPlacement UNoesisTickBar::GetPlacement()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return (ENoesisTickBarPlacement)NoesisTickBar->GetPlacement();
}

void UNoesisTickBar::SetPlacement(ENoesisTickBarPlacement InPlacement)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetPlacement((Noesis::Gui::TickBarPlacement)InPlacement);
}

float UNoesisTickBar::GetReservedSpace()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return (float)NoesisTickBar->GetReservedSpace();
}

void UNoesisTickBar::SetReservedSpace(float InReservedSpace)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetReservedSpace(InReservedSpace);
}

float UNoesisTickBar::GetSelectionEnd()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return (float)NoesisTickBar->GetSelectionEnd();
}

void UNoesisTickBar::SetSelectionEnd(float InSelectionEnd)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetSelectionEnd(InSelectionEnd);
}

float UNoesisTickBar::GetSelectionStart()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return (float)NoesisTickBar->GetSelectionStart();
}

void UNoesisTickBar::SetSelectionStart(float InSelectionStart)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetSelectionStart(InSelectionStart);
}

float UNoesisTickBar::GetTickFrequency()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return (float)NoesisTickBar->GetTickFrequency();
}

void UNoesisTickBar::SetTickFrequency(float InTickFrequency)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetTickFrequency(InTickFrequency);
}

FString UNoesisTickBar::GetTicks()
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	return NsStringToFString(NoesisTickBar->GetTicks());
}

void UNoesisTickBar::SetTicks(FString InTicks)
{
	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar);
	NoesisTickBar->SetTicks(StringCast<NsChar>(*InTicks).Get());
}

void UNoesisTickBar::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar)


}

void UNoesisTickBar::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TickBar* NoesisTickBar = NsDynamicCast<Noesis::Gui::TickBar*>(NoesisComponent.GetPtr());
	check(NoesisTickBar)


}

