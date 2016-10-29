////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiListView.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiListView::UNoesisGuiListView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiListView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ListView* NoesisListView = NsDynamicCast<Noesis::Gui::ListView*>(InNoesisComponent);
	check(NoesisListView);
}

void UNoesisGuiListView::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ListView* NoesisListView = NsDynamicCast<Noesis::Gui::ListView*>(NoesisComponent.GetPtr());
	check(NoesisListView)


}

void UNoesisGuiListView::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ListView* NoesisListView = NsDynamicCast<Noesis::Gui::ListView*>(NoesisComponent.GetPtr());
	check(NoesisListView)


}

