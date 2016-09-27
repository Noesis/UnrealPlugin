////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTreeView.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTreeView::UNoesisGuiTreeView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTreeView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TreeView* NoesisTreeView = NsDynamicCast<Noesis::Gui::TreeView*>(InNoesisComponent);
	check(NoesisTreeView);

}

	void UNoesisGuiTreeView::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TreeView* NoesisTreeView = NsDynamicCast<Noesis::Gui::TreeView*>(NoesisComponent.GetPtr());
	if (!NoesisTreeView)
		return;

}

