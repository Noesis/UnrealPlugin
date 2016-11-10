////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBaseView.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseView::UNoesisBaseView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBaseView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(InNoesisComponent);
	check(NoesisBaseView);
}

void UNoesisBaseView::ClearItem(class UNoesisListViewItem* InItem)
{
	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(NoesisComponent.GetPtr());
	check(NoesisBaseView);
	ListViewItem* NoesisInItem = NsDynamicCast<ListViewItem*>(InItem->NoesisComponent.GetPtr());
	return NoesisBaseView->ClearItem(NoesisInItem);
}

void UNoesisBaseView::PrepareItem(class UNoesisListViewItem* InItem)
{
	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(NoesisComponent.GetPtr());
	check(NoesisBaseView);
	ListViewItem* NoesisInItem = NsDynamicCast<ListViewItem*>(InItem->NoesisComponent.GetPtr());
	return NoesisBaseView->PrepareItem(NoesisInItem);
}

void UNoesisBaseView::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(NoesisComponent.GetPtr());
	check(NoesisBaseView)


}

void UNoesisBaseView::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(NoesisComponent.GetPtr());
	check(NoesisBaseView)


}

