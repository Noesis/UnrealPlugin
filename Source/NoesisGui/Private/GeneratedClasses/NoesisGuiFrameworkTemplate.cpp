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

	void UNoesisGuiFrameworkTemplate::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::FrameworkTemplate* NoesisFrameworkTemplate = NsDynamicCast<Noesis::Gui::FrameworkTemplate*>(NoesisComponent.GetPtr());
	if (!NoesisFrameworkTemplate)
		return;

}

