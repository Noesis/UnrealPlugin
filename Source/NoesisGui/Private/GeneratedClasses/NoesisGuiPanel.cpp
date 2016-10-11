////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPanel::UNoesisGuiPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(InNoesisComponent);
	check(NoesisPanel);

}

class UNoesisGuiUIElementCollection* UNoesisGuiPanel::GetChildren()
{
	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel);
	return CastChecked<UNoesisGuiUIElementCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisPanel->GetChildren()));
}

void UNoesisGuiPanel::InvalidateZOrder()
{
	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel);
	return NoesisPanel->InvalidateZOrder();
}

	void UNoesisGuiPanel::BeginDestroy()
{
	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	if (!NoesisPanel)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

