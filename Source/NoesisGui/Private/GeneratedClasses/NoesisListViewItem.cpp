////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisListViewItem.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisListViewItem::UNoesisListViewItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ListViewItem::StaticGetClassType();
}

void UNoesisListViewItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ListViewItem* NoesisListViewItem = NsDynamicCast<Noesis::Gui::ListViewItem*>(InNoesisComponent);
	check(NoesisListViewItem);
}

void UNoesisListViewItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ListViewItem* NoesisListViewItem = NsDynamicCast<Noesis::Gui::ListViewItem*>(NoesisComponent.GetPtr());
	check(NoesisListViewItem);


}

void UNoesisListViewItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ListViewItem* NoesisListViewItem = NsDynamicCast<Noesis::Gui::ListViewItem*>(NoesisComponent.GetPtr());
	check(NoesisListViewItem);


}

