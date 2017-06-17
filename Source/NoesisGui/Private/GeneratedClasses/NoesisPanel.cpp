////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisPanel.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisPanel::UNoesisPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Panel::StaticGetClassType();
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
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisPanel->GetBackground(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisUIElementCollection>(CreateClassFor(NoesisPanel->GetChildren(), nullptr), ECastCheckedType::NullAllowed);
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
	check(NoesisPanel);


}

void UNoesisPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Panel* NoesisPanel = NsDynamicCast<Noesis::Gui::Panel*>(NoesisComponent.GetPtr());
	check(NoesisPanel);


}

