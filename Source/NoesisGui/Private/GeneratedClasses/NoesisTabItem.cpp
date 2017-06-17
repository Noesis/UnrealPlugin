////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisTabItem.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisTabItem::UNoesisTabItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TabItem::StaticGetClassType();
}

void UNoesisTabItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TabItem* NoesisTabItem = NsDynamicCast<Noesis::Gui::TabItem*>(InNoesisComponent);
	check(NoesisTabItem);
}

bool UNoesisTabItem::GetIsSelected()
{
	Noesis::Gui::TabItem* NoesisTabItem = NsDynamicCast<Noesis::Gui::TabItem*>(NoesisComponent.GetPtr());
	check(NoesisTabItem);
	return NoesisTabItem->GetIsSelected();
}

void UNoesisTabItem::SetIsSelected(bool InIsSelected)
{
	Noesis::Gui::TabItem* NoesisTabItem = NsDynamicCast<Noesis::Gui::TabItem*>(NoesisComponent.GetPtr());
	check(NoesisTabItem);
	NoesisTabItem->SetIsSelected(InIsSelected);
}

ENoesisDock UNoesisTabItem::GetTabStripPlacement()
{
	Noesis::Gui::TabItem* NoesisTabItem = NsDynamicCast<Noesis::Gui::TabItem*>(NoesisComponent.GetPtr());
	check(NoesisTabItem);
	return (ENoesisDock)NoesisTabItem->GetTabStripPlacement();
}

void UNoesisTabItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TabItem* NoesisTabItem = NsDynamicCast<Noesis::Gui::TabItem*>(NoesisComponent.GetPtr());
	check(NoesisTabItem);


}

void UNoesisTabItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TabItem* NoesisTabItem = NsDynamicCast<Noesis::Gui::TabItem*>(NoesisComponent.GetPtr());
	check(NoesisTabItem);


}

