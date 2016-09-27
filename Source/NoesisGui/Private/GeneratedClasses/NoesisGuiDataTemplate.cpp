////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDataTemplate.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDataTemplate::UNoesisGuiDataTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDataTemplate::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(InNoesisComponent);
	check(NoesisDataTemplate);

}

class UNoesisGuiResourceKeyType* UNoesisGuiDataTemplate::GetDataType()
{
	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplate);
	return CastChecked<UNoesisGuiResourceKeyType>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTemplate->GetDataType()));
}

void UNoesisGuiDataTemplate::SetDataType(class UNoesisGuiResourceKeyType* InDataType)
{
	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplate);
	NoesisDataTemplate->SetDataType(NsDynamicCast<ResourceKeyType*>(InDataType->NoesisComponent.GetPtr()));
}

class UNoesisGuiTriggerCollection* UNoesisGuiDataTemplate::GetTriggers()
{
	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplate);
	return CastChecked<UNoesisGuiTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTemplate->GetTriggers()));
}

	void UNoesisGuiDataTemplate::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(NoesisComponent.GetPtr());
	if (!NoesisDataTemplate)
		return;

}

