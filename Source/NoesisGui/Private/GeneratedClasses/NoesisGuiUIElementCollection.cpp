////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiUIElementCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiUIElementCollection::UNoesisGuiUIElementCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiUIElementCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::UIElementCollection* NoesisUIElementCollection = NsDynamicCast<Noesis::Gui::UIElementCollection*>(InNoesisComponent);
	check(NoesisUIElementCollection);

}

class UNoesisGuiFrameworkElement* UNoesisGuiUIElementCollection::GetLogicalParent()
{
	Noesis::Gui::UIElementCollection* NoesisUIElementCollection = NsDynamicCast<Noesis::Gui::UIElementCollection*>(NoesisComponent.GetPtr());
	check(NoesisUIElementCollection);
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElementCollection->GetLogicalParent()));
}

void UNoesisGuiUIElementCollection::SetLogicalParent(class UNoesisGuiFrameworkElement* InLogicalParent)
{
	Noesis::Gui::UIElementCollection* NoesisUIElementCollection = NsDynamicCast<Noesis::Gui::UIElementCollection*>(NoesisComponent.GetPtr());
	check(NoesisUIElementCollection);
	NoesisUIElementCollection->SetLogicalParent(NsDynamicCast<FrameworkElement*>(InLogicalParent->NoesisComponent.GetPtr()));
}

	void UNoesisGuiUIElementCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::UIElementCollection* NoesisUIElementCollection = NsDynamicCast<Noesis::Gui::UIElementCollection*>(NoesisComponent.GetPtr());
	if (!NoesisUIElementCollection)
		return;

}

