////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisIList.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisIList::UNoesisIList(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::IList::StaticGetClassType();
}

void UNoesisIList::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(InNoesisInterface);
	check(NoesisIList);
}

int32 UNoesisIList::Add(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return (int32)NoesisIList->Add(NoesisInItem);
}

void UNoesisIList::Clear()
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	return NoesisIList->Clear();
}

bool UNoesisIList::Contains(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisIList->Contains(NoesisInItem);
}

int32 UNoesisIList::Count()
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	return (int32)NoesisIList->Count();
}

class UNoesisBaseComponent* UNoesisIList::Get(int32 InIndex)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	NsSize NoesisInIndex = (NsSize)InIndex;
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisIList->Get(NoesisInIndex), nullptr), ECastCheckedType::NullAllowed);
}

int32 UNoesisIList::IndexOf(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisIList->IndexOf(NoesisInItem);
}

void UNoesisIList::Insert(int32 InIndex, class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	NsSize NoesisInIndex = (NsSize)InIndex;
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisIList->Insert(NoesisInIndex, NoesisInItem);
}

void UNoesisIList::Remove(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisIList->Remove(NoesisInItem);
}

void UNoesisIList::RemoveAt(int32 InIndex)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	NsSize NoesisInIndex = (NsSize)InIndex;
	return NoesisIList->RemoveAt(NoesisInIndex);
}

void UNoesisIList::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);


}

void UNoesisIList::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);


}

