////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisProgressBar.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisProgressBar::UNoesisProgressBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ProgressBar::StaticGetClassType();
}

void UNoesisProgressBar::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ProgressBar* NoesisProgressBar = NsDynamicCast<Noesis::Gui::ProgressBar*>(InNoesisComponent);
	check(NoesisProgressBar);
}

bool UNoesisProgressBar::GetIsIndeterminate()
{
	Noesis::Gui::ProgressBar* NoesisProgressBar = NsDynamicCast<Noesis::Gui::ProgressBar*>(NoesisComponent.GetPtr());
	check(NoesisProgressBar);
	return NoesisProgressBar->GetIsIndeterminate();
}

void UNoesisProgressBar::SetIsIndeterminate(bool InIsIndeterminate)
{
	Noesis::Gui::ProgressBar* NoesisProgressBar = NsDynamicCast<Noesis::Gui::ProgressBar*>(NoesisComponent.GetPtr());
	check(NoesisProgressBar);
	NoesisProgressBar->SetIsIndeterminate(InIsIndeterminate);
}

ENoesisOrientation UNoesisProgressBar::GetOrientation()
{
	Noesis::Gui::ProgressBar* NoesisProgressBar = NsDynamicCast<Noesis::Gui::ProgressBar*>(NoesisComponent.GetPtr());
	check(NoesisProgressBar);
	return (ENoesisOrientation)NoesisProgressBar->GetOrientation();
}

void UNoesisProgressBar::SetOrientation(ENoesisOrientation InOrientation)
{
	Noesis::Gui::ProgressBar* NoesisProgressBar = NsDynamicCast<Noesis::Gui::ProgressBar*>(NoesisComponent.GetPtr());
	check(NoesisProgressBar);
	NoesisProgressBar->SetOrientation((Noesis::Gui::Orientation)InOrientation);
}

void UNoesisProgressBar::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ProgressBar* NoesisProgressBar = NsDynamicCast<Noesis::Gui::ProgressBar*>(NoesisComponent.GetPtr());
	check(NoesisProgressBar);


}

void UNoesisProgressBar::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ProgressBar* NoesisProgressBar = NsDynamicCast<Noesis::Gui::ProgressBar*>(NoesisComponent.GetPtr());
	check(NoesisProgressBar);


}

