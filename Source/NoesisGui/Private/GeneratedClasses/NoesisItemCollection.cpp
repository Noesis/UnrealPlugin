////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisItemCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisItemCollection::UNoesisItemCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ItemCollection::StaticGetClassType();
}

void UNoesisItemCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(InNoesisComponent);
	check(NoesisItemCollection);
}

bool UNoesisItemCollection::IsReadOnly()
{
	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection);
	return NoesisItemCollection->IsReadOnly();
}

void UNoesisItemCollection::SetItemsControlOwner(class UNoesisItemsControl* InItemsControl)
{
	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection);
	ItemsControl* NoesisInItemsControl = NsDynamicCast<ItemsControl*>(InItemsControl->NoesisComponent.GetPtr());
	return NoesisItemCollection->SetItemsControlOwner(NoesisInItemsControl);
}

void UNoesisItemCollection::SetView(class UNoesisCollectionView* InView)
{
	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection);
	CollectionView* NoesisInView = NsDynamicCast<CollectionView*>(InView->NoesisComponent.GetPtr());
	return NoesisItemCollection->SetView(NoesisInView);
}

void UNoesisItemCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection);


}

void UNoesisItemCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	check(NoesisItemCollection);


}

