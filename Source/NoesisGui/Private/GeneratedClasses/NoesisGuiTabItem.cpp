////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTabItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTabItem::UNoesisGuiTabItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTabItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TabItem* NoesisTabItem = NsDynamicCast<Noesis::Gui::TabItem*>(InNoesisComponent);
	check(NoesisTabItem);
}

void UNoesisGuiTabItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TabItem* NoesisTabItem = NsDynamicCast<Noesis::Gui::TabItem*>(NoesisComponent.GetPtr());
	check(NoesisTabItem)


}

void UNoesisGuiTabItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TabItem* NoesisTabItem = NsDynamicCast<Noesis::Gui::TabItem*>(NoesisComponent.GetPtr());
	check(NoesisTabItem)


}

