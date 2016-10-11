////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCollectionView.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCollectionView::UNoesisGuiCollectionView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCollectionView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(InNoesisComponent);
	check(NoesisCollectionView);

}

int32 UNoesisGuiCollectionView::Count()
{
	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);
	return (int32)NoesisCollectionView->Count();
}

class UNoesisGuiBaseComponent* UNoesisGuiCollectionView::GetItemAt(int32 InIndex)
{
	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);
	NsSize NoesisInIndex = InIndex;
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisCollectionView->GetItemAt(NoesisInIndex)));
}

class UNoesisGuiIList* UNoesisGuiCollectionView::GetSourceCollection()
{
	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);
	return CastChecked<UNoesisGuiIList>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisCollectionView->GetSourceCollection()));
}

int32 UNoesisGuiCollectionView::IndexOf(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	check(NoesisCollectionView);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisCollectionView->IndexOf(NoesisInItem);
}

	void UNoesisGuiCollectionView::BeginDestroy()
{
	Noesis::Gui::CollectionView* NoesisCollectionView = NsDynamicCast<Noesis::Gui::CollectionView*>(NoesisComponent.GetPtr());
	if (!NoesisCollectionView)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

