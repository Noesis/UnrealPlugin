////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiICollectionView.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiICollectionView::UNoesisGuiICollectionView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiICollectionView::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(InNoesisInterface);
	check(NoesisICollectionView);

}

bool UNoesisGuiICollectionView::CanFilter()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->CanFilter();
}

bool UNoesisGuiICollectionView::CanGroup()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->CanGroup();
}

bool UNoesisGuiICollectionView::CanSort()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->CanSort();
}

bool UNoesisGuiICollectionView::Contains(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisICollectionView->Contains(NoesisInItem);
}

class UNoesisGuiBaseComponent* UNoesisGuiICollectionView::CurrentItem()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisICollectionView->CurrentItem()));
}

int32 UNoesisGuiICollectionView::CurrentPosition()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->CurrentPosition();
}

bool UNoesisGuiICollectionView::IsCurrentAfterLast()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->IsCurrentAfterLast();
}

bool UNoesisGuiICollectionView::IsCurrentBeforeFirst()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->IsCurrentBeforeFirst();
}

bool UNoesisGuiICollectionView::IsEmpty()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->IsEmpty();
}

bool UNoesisGuiICollectionView::MoveCurrentTo(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisICollectionView->MoveCurrentTo(NoesisInItem);
}

	void UNoesisGuiICollectionView::BeginDestroy()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	if (!NoesisICollectionView)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

