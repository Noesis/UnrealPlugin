////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIList.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIList::UNoesisGuiIList(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIList::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(InNoesisInterface);
	check(NoesisIList);
}

int32 UNoesisGuiIList::Add(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return (int32)NoesisIList->Add(NoesisInItem);
}

void UNoesisGuiIList::Clear()
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	return NoesisIList->Clear();
}

bool UNoesisGuiIList::Contains(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisIList->Contains(NoesisInItem);
}

int32 UNoesisGuiIList::Count()
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	return (int32)NoesisIList->Count();
}

class UNoesisGuiBaseComponent* UNoesisGuiIList::Get(int32 InIndex)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	NsSize NoesisInIndex = InIndex;
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisIList->Get(NoesisInIndex)));
}

int32 UNoesisGuiIList::IndexOf(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisIList->IndexOf(NoesisInItem);
}

void UNoesisGuiIList::Insert(int32 InIndex, class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	NsSize NoesisInIndex = InIndex;
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisIList->Insert(NoesisInIndex, NoesisInItem);
}

void UNoesisGuiIList::Remove(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisIList->Remove(NoesisInItem);
}

void UNoesisGuiIList::RemoveAt(int32 InIndex)
{
	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList);
	NsSize NoesisInIndex = InIndex;
	return NoesisIList->RemoveAt(NoesisInIndex);
}

void UNoesisGuiIList::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList)


}

void UNoesisGuiIList::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IList* NoesisIList = NsDynamicCast<Noesis::Gui::IList*>(NoesisInterface.GetPtr());
	check(NoesisIList)


}

