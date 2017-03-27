////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisUIElementCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisUIElementCollection::UNoesisUIElementCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::UIElementCollection::StaticGetClassType();
}

void UNoesisUIElementCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::UIElementCollection* NoesisUIElementCollection = NsDynamicCast<Noesis::Gui::UIElementCollection*>(InNoesisComponent);
	check(NoesisUIElementCollection);
}

class UNoesisFrameworkElement* UNoesisUIElementCollection::GetLogicalParent()
{
	Noesis::Gui::UIElementCollection* NoesisUIElementCollection = NsDynamicCast<Noesis::Gui::UIElementCollection*>(NoesisComponent.GetPtr());
	check(NoesisUIElementCollection);
	return CastChecked<UNoesisFrameworkElement>(CreateClassFor(NoesisUIElementCollection->GetLogicalParent(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisUIElementCollection::SetLogicalParent(class UNoesisFrameworkElement* InLogicalParent)
{
	Noesis::Gui::UIElementCollection* NoesisUIElementCollection = NsDynamicCast<Noesis::Gui::UIElementCollection*>(NoesisComponent.GetPtr());
	check(NoesisUIElementCollection);
	NoesisUIElementCollection->SetLogicalParent(NsDynamicCast<FrameworkElement*>(InLogicalParent->NoesisComponent.GetPtr()));
}

void UNoesisUIElementCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::UIElementCollection* NoesisUIElementCollection = NsDynamicCast<Noesis::Gui::UIElementCollection*>(NoesisComponent.GetPtr());
	check(NoesisUIElementCollection);


}

void UNoesisUIElementCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::UIElementCollection* NoesisUIElementCollection = NsDynamicCast<Noesis::Gui::UIElementCollection*>(NoesisComponent.GetPtr());
	check(NoesisUIElementCollection);


}

