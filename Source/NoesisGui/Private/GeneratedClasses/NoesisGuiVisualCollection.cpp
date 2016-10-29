////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisualCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisualCollection::UNoesisGuiVisualCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisualCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(InNoesisComponent);
	check(NoesisVisualCollection);
}

class UNoesisGuiVisual* UNoesisGuiVisualCollection::GetVisualParent()
{
	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(NoesisComponent.GetPtr());
	check(NoesisVisualCollection);
	return CastChecked<UNoesisGuiVisual>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualCollection->GetVisualParent()));
}

void UNoesisGuiVisualCollection::SetVisualParent(class UNoesisGuiVisual* InVisualParent)
{
	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(NoesisComponent.GetPtr());
	check(NoesisVisualCollection);
	NoesisVisualCollection->SetVisualParent(NsDynamicCast<Visual*>(InVisualParent->NoesisComponent.GetPtr()));
}

void UNoesisGuiVisualCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(NoesisComponent.GetPtr());
	check(NoesisVisualCollection)


}

void UNoesisGuiVisualCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(NoesisComponent.GetPtr());
	check(NoesisVisualCollection)


}

