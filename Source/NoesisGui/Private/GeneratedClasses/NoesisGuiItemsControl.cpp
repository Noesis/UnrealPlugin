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

class UNoesisGuiDependencyObject* UNoesisGuiItemsControl::ContainerFromElement(class UNoesisGuiDependencyObject* InElement)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	DependencyObject* NoesisInElement = NsDynamicCast<DependencyObject*>(InElement->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemsControl->ContainerFromElement(NoesisInElement)));
}

class UNoesisGuiPanel* UNoesisGuiItemsControl::GetDefaultItemsPanel()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisGuiPanel>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemsControl->GetDefaultItemsPanel()));
}

class UNoesisGuiItemContainerGenerator* UNoesisGuiItemsControl::GetItemContainerGenerator()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisGuiItemContainerGenerator>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemsControl->GetItemContainerGenerator()));
}

bool UNoesisGuiItemsControl::IsItemItsOwnContainer(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisItemsControl->IsItemItsOwnContainer(NoesisInItem);
}

	void UNoesisGuiItemsControl::BeginDestroy()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	if (!NoesisItemsControl)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

