////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDataTemplate.h"

using namespace Noesis;
using namespace Gui;

UNoesisDataTemplate::UNoesisDataTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDataTemplate::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(InNoesisComponent);
	check(NoesisDataTemplate);
}

class UNoesisResourceKeyType* UNoesisDataTemplate::GetDataType()
{
	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplate);
	return CastChecked<UNoesisResourceKeyType>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTemplate->GetDataType()));
}

void UNoesisDataTemplate::SetDataType(class UNoesisResourceKeyType* InDataType)
{
	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplate);
	NoesisDataTemplate->SetDataType(NsDynamicCast<ResourceKeyType*>(InDataType->NoesisComponent.GetPtr()));
}

class UNoesisTriggerCollection* UNoesisDataTemplate::GetTriggers()
{
	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplate);
	return CastChecked<UNoesisTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTemplate->GetTriggers()));
}

void UNoesisDataTemplate::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplate)


}

void UNoesisDataTemplate::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DataTemplate* NoesisDataTemplate = NsDynamicCast<Noesis::Gui::DataTemplate*>(NoesisComponent.GetPtr());
	check(NoesisDataTemplate)


}

