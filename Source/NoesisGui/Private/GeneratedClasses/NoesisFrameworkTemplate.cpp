////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisFrameworkTemplate.h"

using namespace Noesis;
using namespace Gui;

UNoesisFrameworkTemplate::UNoesisFrameworkTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisFrameworkTemplate::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(InNoesisComponent);
	check(NoesisFrameworkTemplate);
}

class UNoesisResourceDictionary* UNoesisFrameworkTemplate::GetResources()
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	return CastChecked<UNoesisResourceDictionary>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->GetResources()));
}

void UNoesisFrameworkTemplate::SetResources(class UNoesisResourceDictionary* InResources)
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	NoesisFrameworkTemplate->SetResources(NsDynamicCast<ResourceDictionary*>(InResources->NoesisComponent.GetPtr()));
}

class UNoesisVisual* UNoesisFrameworkTemplate::GetVisualTree()
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	return CastChecked<UNoesisVisual>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->GetVisualTree()));
}

void UNoesisFrameworkTemplate::SetVisualTree(class UNoesisVisual* InVisualTree)
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	NoesisFrameworkTemplate->SetVisualTree(NsDynamicCast<Visual*>(InVisualTree->NoesisComponent.GetPtr()));
}

class UNoesisFrameworkElement* UNoesisFrameworkTemplate::Apply(class UNoesisFrameworkElement* InTemplatedParent, class UNoesisBaseComponent* InDataContext)
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	FrameworkElement* NoesisInTemplatedParent = NsDynamicCast<FrameworkElement*>(InTemplatedParent->NoesisComponent.GetPtr());
	BaseComponent* NoesisInDataContext = NsDynamicCast<BaseComponent*>(InDataContext->NoesisComponent.GetPtr());
	return CastChecked<UNoesisFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->Apply(NoesisInTemplatedParent, NoesisInDataContext)));
}

class UNoesisBaseComponent* UNoesisFrameworkTemplate::FindName(FString InName, class UNoesisFrameworkElement* InTemplatedParent)
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	FrameworkElement* NoesisInTemplatedParent = NsDynamicCast<FrameworkElement*>(InTemplatedParent->NoesisComponent.GetPtr());
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->FindName(NoesisInName, NoesisInTemplatedParent)));
}

class UNoesisTriggerCollection* UNoesisFrameworkTemplate::GetAvailableTriggers()
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	return CastChecked<UNoesisTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->GetAvailableTriggers()));
}

void UNoesisFrameworkTemplate::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate)


}

void UNoesisFrameworkTemplate::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate)


}

