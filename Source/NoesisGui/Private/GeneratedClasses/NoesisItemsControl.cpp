////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisItemsControl.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisItemsControl::UNoesisItemsControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ItemsControl::StaticGetClassType();
}

void UNoesisItemsControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(InNoesisComponent);
	check(NoesisItemsControl);
}

FString UNoesisItemsControl::GetDisplayMemberPath()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return NsStringToFString(NoesisItemsControl->GetDisplayMemberPath());
}

void UNoesisItemsControl::SetDisplayMemberPath(FString InDisplayMemberPath)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	NoesisItemsControl->SetDisplayMemberPath(StringCast<NsChar>(*InDisplayMemberPath).Get());
}

bool UNoesisItemsControl::GetHasItems()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return NoesisItemsControl->GetHasItems();
}

class UNoesisStyle* UNoesisItemsControl::GetItemContainerStyle()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisStyle>(CreateClassFor(NoesisItemsControl->GetItemContainerStyle(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisItemsControl::SetItemContainerStyle(class UNoesisStyle* InItemContainerStyle)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	NoesisItemsControl->SetItemContainerStyle(NsDynamicCast<Style*>(InItemContainerStyle->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplate* UNoesisItemsControl::GetItemTemplate()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisDataTemplate>(CreateClassFor(NoesisItemsControl->GetItemTemplate(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisItemsControl::SetItemTemplate(class UNoesisDataTemplate* InItemTemplate)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	NoesisItemsControl->SetItemTemplate(NsDynamicCast<DataTemplate*>(InItemTemplate->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplateSelector* UNoesisItemsControl::GetItemTemplateSelector()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisDataTemplateSelector>(CreateClassFor(NoesisItemsControl->GetItemTemplateSelector(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisItemsControl::SetItemTemplateSelector(class UNoesisDataTemplateSelector* InItemTemplateSelector)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	NoesisItemsControl->SetItemTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InItemTemplateSelector->NoesisComponent.GetPtr()));
}

class UNoesisItemCollection* UNoesisItemsControl::GetItems()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisItemCollection>(CreateClassFor(NoesisItemsControl->GetItems(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisItemsPanelTemplate* UNoesisItemsControl::GetItemsPanel()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisItemsPanelTemplate>(CreateClassFor(NoesisItemsControl->GetItemsPanel(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisItemsControl::SetItemsPanel(class UNoesisItemsPanelTemplate* InItemsPanel)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	NoesisItemsControl->SetItemsPanel(NsDynamicCast<ItemsPanelTemplate*>(InItemsPanel->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisItemsControl::GetItemsSource()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisItemsControl->GetItemsSource(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisItemsControl::SetItemsSource(class UNoesisBaseComponent* InItemsSource)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	NoesisItemsControl->SetItemsSource(NsDynamicCast<Core::BaseComponent*>(InItemsSource->NoesisComponent.GetPtr()));
}

class UNoesisDependencyObject* UNoesisItemsControl::ContainerFromElement(class UNoesisDependencyObject* InElement)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	DependencyObject* NoesisInElement = NsDynamicCast<DependencyObject*>(InElement->NoesisComponent.GetPtr());
	return CastChecked<UNoesisDependencyObject>(CreateClassFor(NoesisItemsControl->ContainerFromElement(NoesisInElement), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisPanel* UNoesisItemsControl::GetDefaultItemsPanel()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisPanel>(CreateClassFor(NoesisItemsControl->GetDefaultItemsPanel(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisItemContainerGenerator* UNoesisItemsControl::GetItemContainerGenerator()
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	return CastChecked<UNoesisItemContainerGenerator>(CreateClassFor(NoesisItemsControl->GetItemContainerGenerator(), nullptr), ECastCheckedType::NullAllowed);
}

bool UNoesisItemsControl::IsItemItsOwnContainer(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisItemsControl->IsItemItsOwnContainer(NoesisInItem);
}

void UNoesisItemsControl::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);


}

void UNoesisItemsControl::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ItemsControl* NoesisItemsControl = NsDynamicCast<Noesis::Gui::ItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisItemsControl);


}

