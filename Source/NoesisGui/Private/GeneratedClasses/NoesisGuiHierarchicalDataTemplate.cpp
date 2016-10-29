////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiHierarchicalDataTemplate.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiHierarchicalDataTemplate::UNoesisGuiHierarchicalDataTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiHierarchicalDataTemplate::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(InNoesisComponent);
	check(NoesisHierarchicalDataTemplate);
}

class UNoesisGuiStyle* UNoesisGuiHierarchicalDataTemplate::GetItemContainerStyle()
{
	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate);
	return CastChecked<UNoesisGuiStyle>(Instance->FindUnrealComponentForNoesisComponent(NoesisHierarchicalDataTemplate->GetItemContainerStyle()));
}

void UNoesisGuiHierarchicalDataTemplate::SetItemContainerStyle(class UNoesisGuiStyle* InItemContainerStyle)
{
	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate);
	NoesisHierarchicalDataTemplate->SetItemContainerStyle(NsDynamicCast<Style*>(InItemContainerStyle->NoesisComponent.GetPtr()));
}

class UNoesisGuiDataTemplate* UNoesisGuiHierarchicalDataTemplate::GetItemTemplate()
{
	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate);
	return CastChecked<UNoesisGuiDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisHierarchicalDataTemplate->GetItemTemplate()));
}

void UNoesisGuiHierarchicalDataTemplate::SetItemTemplate(class UNoesisGuiDataTemplate* InItemTemplate)
{
	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate);
	NoesisHierarchicalDataTemplate->SetItemTemplate(NsDynamicCast<DataTemplate*>(InItemTemplate->NoesisComponent.GetPtr()));
}

class UNoesisGuiDataTemplateSelector* UNoesisGuiHierarchicalDataTemplate::GetItemTemplateSelector()
{
	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate);
	return CastChecked<UNoesisGuiDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisHierarchicalDataTemplate->GetItemTemplateSelector()));
}

void UNoesisGuiHierarchicalDataTemplate::SetItemTemplateSelector(class UNoesisGuiDataTemplateSelector* InItemTemplateSelector)
{
	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate);
	NoesisHierarchicalDataTemplate->SetItemTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InItemTemplateSelector->NoesisComponent.GetPtr()));
}

class UNoesisGuiBaseBinding* UNoesisGuiHierarchicalDataTemplate::GetItemsSource()
{
	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate);
	return CastChecked<UNoesisGuiBaseBinding>(Instance->FindUnrealComponentForNoesisComponent(NoesisHierarchicalDataTemplate->GetItemsSource()));
}

void UNoesisGuiHierarchicalDataTemplate::SetItemsSource(class UNoesisGuiBaseBinding* InItemsSource)
{
	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate);
	NoesisHierarchicalDataTemplate->SetItemsSource(NsDynamicCast<BaseBinding*>(InItemsSource->NoesisComponent.GetPtr()));
}

void UNoesisGuiHierarchicalDataTemplate::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate)


}

void UNoesisGuiHierarchicalDataTemplate::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::HierarchicalDataTemplate* NoesisHierarchicalDataTemplate = NsDynamicCast<Noesis::Gui::HierarchicalDataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisHierarchicalDataTemplate)


}

