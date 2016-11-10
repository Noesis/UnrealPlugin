////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisPanel::UNoesisPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(InNoesisComponent);
	check(NoesisPanel);
}

class UNoesisBrush* UNoesisPanel::GetBackground()
{
	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisPanel->GetBackground()));
}

void UNoesisPanel::SetBackground(class UNoesisBrush* InBackground)
{
	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel);
	NoesisPanel->SetBackground(NsDynamicCast<Brush*>(InBackground->NoesisComponent.GetPtr()));
}

class UNoesisUIElementCollection* UNoesisPanel::GetChildren()
{
	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel);
	return CastChecked<UNoesisUIElementCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisPanel->GetChildren()));
}

bool UNoesisPanel::GetIsItemsHost()
{
	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel);
	return NoesisPanel->GetIsItemsHost();
}

void UNoesisPanel::SetIsItemsHost(bool InIsItemsHost)
{
	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel);
	NoesisPanel->SetIsItemsHost(InIsItemsHost);
}

void UNoesisPanel::InvalidateZOrder()
{
	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel);
	return NoesisPanel->InvalidateZOrder();
}

void UNoesisPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel)


}

void UNoesisPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel)


}

