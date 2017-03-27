////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisStatusBarItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisStatusBarItem::UNoesisStatusBarItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::StatusBarItem::StaticGetClassType();
}

void UNoesisStatusBarItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StatusBarItem* NoesisStatusBarItem = NsDynamicCast<Noesis::Gui::StatusBarItem*>(InNoesisComponent);
	check(NoesisStatusBarItem);
}

void UNoesisStatusBarItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::StatusBarItem* NoesisStatusBarItem = NsDynamicCast<Noesis::Gui::StatusBarItem*>(NoesisComponent.GetPtr());
	check(NoesisStatusBarItem);


}

void UNoesisStatusBarItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::StatusBarItem* NoesisStatusBarItem = NsDynamicCast<Noesis::Gui::StatusBarItem*>(NoesisComponent.GetPtr());
	check(NoesisStatusBarItem);


}

