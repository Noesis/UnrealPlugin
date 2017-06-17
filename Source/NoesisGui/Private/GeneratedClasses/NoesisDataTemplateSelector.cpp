////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDataTemplateSelector.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDataTemplateSelector::UNoesisDataTemplateSelector(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DataTemplateSelector::StaticGetClassType();
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
	return CastChecked<UNoesisDataTemplate>(CreateClassFor(NoesisDataTemplateSelector->SelectTemplate(NoesisInItem, NoesisInContainer), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisDataTemplateSelector::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplateSelector);


}

void UNoesisDataTemplateSelector::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplateSelector);


}

