////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiListViewItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiListViewItem::UNoesisGuiListViewItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiListViewItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ListViewItem* NoesisListViewItem = NsDynamicCast<Noesis::Gui::ListViewItem*>(InNoesisComponent);
	check(NoesisListViewItem);

}

	void UNoesisGuiListViewItem::BeginDestroy()
{
	Noesis::Gui::ListViewItem* NoesisListViewItem = NsDynamicCast<Noesis::Gui::ListViewItem*>(NoesisComponent.GetPtr());
	if (!NoesisListViewItem)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

