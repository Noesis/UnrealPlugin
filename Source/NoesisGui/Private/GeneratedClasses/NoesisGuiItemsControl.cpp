////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiItemsControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiItemsControl::UNoesisGuiItemsControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiItemsControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(InNoesisComponent);
	check(NoesisItemsControl);

}

class UNoesisGuiItemCollection* UNoesisGuiItemsControl::GetItems()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisGuiItemCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemsControl->GetItems()));
}

	void UNoesisGuiItemsControl::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	if (!NoesisItemsControl)
		return;

}

