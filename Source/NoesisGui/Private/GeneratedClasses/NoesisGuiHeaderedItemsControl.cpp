////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiHeaderedItemsControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiHeaderedItemsControl::UNoesisGuiHeaderedItemsControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiHeaderedItemsControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(InNoesisComponent);
	check(NoesisHeaderedItemsControl);
}

void UNoesisGuiHeaderedItemsControl::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl)


}

void UNoesisGuiHeaderedItemsControl::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl)


}

