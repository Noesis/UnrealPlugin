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

	void UNoesisGuiDataTemplateSelector::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::DataTemplateSelector* NoesisDataTemplateSelector = NsDynamicCast<Noesis::Gui::DataTemplateSelector*>(NoesisComponent.GetPtr());
	if (!NoesisDataTemplateSelector)
		return;

}

