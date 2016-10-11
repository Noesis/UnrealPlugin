////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGridView.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGridView::UNoesisGuiGridView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGridView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(InNoesisComponent);
	check(NoesisGridView);

}

class UNoesisGuiGridViewColumnCollection* UNoesisGuiGridView::GetColumns()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	return CastChecked<UNoesisGuiGridViewColumnCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridView->GetColumns()));
}

	void UNoesisGuiGridView::BeginDestroy()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	if (!NoesisGridView)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

