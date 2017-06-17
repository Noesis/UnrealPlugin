////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisICollectionView.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisICollectionView::UNoesisICollectionView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::ICollectionView::StaticGetClassType();
}

void UNoesisICollectionView::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(InNoesisInterface);
	check(NoesisICollectionView);
}

bool UNoesisICollectionView::CanFilter()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->CanFilter();
}

bool UNoesisICollectionView::CanGroup()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->CanGroup();
}

bool UNoesisICollectionView::CanSort()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->CanSort();
}

bool UNoesisICollectionView::Contains(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisICollectionView->Contains(NoesisInItem);
}

class UNoesisBaseComponent* UNoesisICollectionView::CurrentItem()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisICollectionView->CurrentItem(), nullptr), ECastCheckedType::NullAllowed);
}

int32 UNoesisICollectionView::CurrentPosition()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->CurrentPosition();
}

bool UNoesisICollectionView::IsCurrentAfterLast()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->IsCurrentAfterLast();
}

bool UNoesisICollectionView::IsCurrentBeforeFirst()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->IsCurrentBeforeFirst();
}

bool UNoesisICollectionView::IsEmpty()
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	return NoesisICollectionView->IsEmpty();
}

bool UNoesisICollectionView::MoveCurrentTo(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisICollectionView->MoveCurrentTo(NoesisInItem);
}

void UNoesisICollectionView::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);


}

void UNoesisICollectionView::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ICollectionView* NoesisICollectionView = NsDynamicCast<Noesis::Gui::ICollectionView*>(NoesisInterface.GetPtr());
	check(NoesisICollectionView);


}

