////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiStatusBarItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiStatusBarItem::UNoesisGuiStatusBarItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiStatusBarItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StatusBarItem* NoesisStatusBarItem = NsDynamicCast<Noesis::Gui::StatusBarItem*>(InNoesisComponent);
	check(NoesisStatusBarItem);
}

void UNoesisGuiStatusBarItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::StatusBarItem* NoesisStatusBarItem = NsDynamicCast<Noesis::Gui::StatusBarItem*>(NoesisComponent.GetPtr());
	check(NoesisStatusBarItem)


}

void UNoesisGuiStatusBarItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::StatusBarItem* NoesisStatusBarItem = NsDynamicCast<Noesis::Gui::StatusBarItem*>(NoesisComponent.GetPtr());
	check(NoesisStatusBarItem)


}

