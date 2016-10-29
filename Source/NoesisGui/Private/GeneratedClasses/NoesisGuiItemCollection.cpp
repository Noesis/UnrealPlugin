////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiItemCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiItemCollection::UNoesisGuiItemCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiItemCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(InNoesisComponent);
	check(NoesisItemCollection);
}

bool UNoesisGuiItemCollection::IsReadOnly()
{
	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection);
	return NoesisItemCollection->IsReadOnly();
}

void UNoesisGuiItemCollection::SetItemsControlOwner(class UNoesisGuiItemsControl* InItemsControl)
{
	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection);
	ItemsControl* NoesisInItemsControl = NsDynamicCast<ItemsControl*>(InItemsControl->NoesisComponent.GetPtr());
	return NoesisItemCollection->SetItemsControlOwner(NoesisInItemsControl);
}

void UNoesisGuiItemCollection::SetView(class UNoesisGuiCollectionView* InView)
{
	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection);
	CollectionView* NoesisInView = NsDynamicCast<CollectionView*>(InView->NoesisComponent.GetPtr());
	return NoesisItemCollection->SetView(NoesisInView);
}

void UNoesisGuiItemCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection)


}

void UNoesisGuiItemCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection)


}

