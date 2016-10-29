////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiFrameworkTemplate.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiFrameworkTemplate::UNoesisGuiFrameworkTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiFrameworkTemplate::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(InNoesisComponent);
	check(NoesisFrameworkTemplate);
}

class UNoesisGuiResourceDictionary* UNoesisGuiFrameworkTemplate::GetResources()
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	return CastChecked<UNoesisGuiResourceDictionary>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->GetResources()));
}

void UNoesisGuiFrameworkTemplate::SetResources(class UNoesisGuiResourceDictionary* InResources)
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	NoesisFrameworkTemplate->SetResources(NsDynamicCast<ResourceDictionary*>(InResources->NoesisComponent.GetPtr()));
}

class UNoesisGuiVisual* UNoesisGuiFrameworkTemplate::GetVisualTree()
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	return CastChecked<UNoesisGuiVisual>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->GetVisualTree()));
}

void UNoesisGuiFrameworkTemplate::SetVisualTree(class UNoesisGuiVisual* InVisualTree)
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	NoesisFrameworkTemplate->SetVisualTree(NsDynamicCast<Visual*>(InVisualTree->NoesisComponent.GetPtr()));
}

class UNoesisGuiFrameworkElement* UNoesisGuiFrameworkTemplate::Apply(class UNoesisGuiFrameworkElement* InTemplatedParent, class UNoesisGuiBaseComponent* InDataContext)
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	FrameworkElement* NoesisInTemplatedParent = NsDynamicCast<FrameworkElement*>(InTemplatedParent->NoesisComponent.GetPtr());
	BaseComponent* NoesisInDataContext = NsDynamicCast<BaseComponent*>(InDataContext->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->Apply(NoesisInTemplatedParent, NoesisInDataContext)));
}

class UNoesisGuiBaseComponent* UNoesisGuiFrameworkTemplate::FindName(FString InName, class UNoesisGuiFrameworkElement* InTemplatedParent)
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	FrameworkElement* NoesisInTemplatedParent = NsDynamicCast<FrameworkElement*>(InTemplatedParent->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->FindName(NoesisInName, NoesisInTemplatedParent)));
}

class UNoesisGuiTriggerCollection* UNoesisGuiFrameworkTemplate::GetAvailableTriggers()
{
	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate);
	return CastChecked<UNoesisGuiTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkTemplate->GetAvailableTriggers()));
}

void UNoesisGuiFrameworkTemplate::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate)


}

void UNoesisGuiFrameworkTemplate::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkTemplate)


}

