////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisCollectionView.h"

using namespace Noesis;
using namespace Gui;

UNoesisCollectionView::UNoesisCollectionView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::CollectionView::StaticGetClassType();
}

void UNoesisCollectionView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(InNoesisComponent);
	check(NoesisCollectionView);
}

int32 UNoesisCollectionView::Count()
{
	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);
	return (int32)NoesisCollectionView->Count();
}

class UNoesisBaseComponent* UNoesisCollectionView::GetItemAt(int32 InIndex)
{
	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);
	NsSize NoesisInIndex = (NsSize)InIndex;
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisCollectionView->GetItemAt(NoesisInIndex), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisIList* UNoesisCollectionView::GetSourceCollection()
{
	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);
	return CastChecked<UNoesisIList>(CreateInterfaceFor(NoesisCollectionView->GetSourceCollection(), nullptr), ECastCheckedType::NullAllowed);
}

int32 UNoesisCollectionView::IndexOf(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisCollectionView->IndexOf(NoesisInItem);
}

void UNoesisCollectionView::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);


}

void UNoesisCollectionView::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);


}

