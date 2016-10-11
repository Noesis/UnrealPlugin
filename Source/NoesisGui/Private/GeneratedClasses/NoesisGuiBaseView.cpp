////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseView.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseView::UNoesisGuiBaseView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(InNoesisComponent);
	check(NoesisBaseView);

}

void UNoesisGuiBaseView::ClearItem(class UNoesisGuiListViewItem* InItem)
{
	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(NoesisComponent.GetPtr());
	check(NoesisBaseView);
	ListViewItem* NoesisInItem = NsDynamicCast<ListViewItem*>(InItem->NoesisComponent.GetPtr());
	return NoesisBaseView->ClearItem(NoesisInItem);
}

void UNoesisGuiBaseView::PrepareItem(class UNoesisGuiListViewItem* InItem)
{
	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(NoesisComponent.GetPtr());
	check(NoesisBaseView);
	ListViewItem* NoesisInItem = NsDynamicCast<ListViewItem*>(InItem->NoesisComponent.GetPtr());
	return NoesisBaseView->PrepareItem(NoesisInItem);
}

	void UNoesisGuiBaseView::BeginDestroy()
{
	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(NoesisComponent.GetPtr());
	if (!NoesisBaseView)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

