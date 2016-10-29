////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDataTemplateSelector.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDataTemplateSelector::UNoesisGuiDataTemplateSelector(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDataTemplateSelector::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(InNoesisComponent);
	check(NoesisDataTemplateSelector);
}

class UNoesisGuiDataTemplate* UNoesisGuiDataTemplateSelector::SelectTemplate(class UNoesisGuiBaseComponent* InItem, class UNoesisGuiDependencyObject* InContainer)
{
	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplateSelector);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTemplateSelector->SelectTemplate(NoesisInItem, NoesisInContainer)));
}

void UNoesisGuiDataTemplateSelector::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplateSelector)


}

void UNoesisGuiDataTemplateSelector::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplateSelector)


}

