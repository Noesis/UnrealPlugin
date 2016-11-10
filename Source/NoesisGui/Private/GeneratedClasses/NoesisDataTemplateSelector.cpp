////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDataTemplateSelector.h"

using namespace Noesis;
using namespace Gui;

UNoesisDataTemplateSelector::UNoesisDataTemplateSelector(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDataTemplateSelector::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(InNoesisComponent);
	check(NoesisDataTemplateSelector);
}

class UNoesisDataTemplate* UNoesisDataTemplateSelector::SelectTemplate(class UNoesisBaseComponent* InItem, class UNoesisDependencyObject* InContainer)
{
	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplateSelector);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTemplateSelector->SelectTemplate(NoesisInItem, NoesisInContainer)));
}

void UNoesisDataTemplateSelector::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplateSelector)


}

void UNoesisDataTemplateSelector::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplateSelector)


}

