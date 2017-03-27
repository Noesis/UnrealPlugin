////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisVisualCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisVisualCollection::UNoesisVisualCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::VisualCollection::StaticGetClassType();
}

void UNoesisVisualCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(InNoesisComponent);
	check(NoesisVisualCollection);
}

class UNoesisVisual* UNoesisVisualCollection::GetVisualParent()
{
	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(NoesisComponent.GetPtr());
	check(NoesisVisualCollection);
	return CastChecked<UNoesisVisual>(CreateClassFor(NoesisVisualCollection->GetVisualParent(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisVisualCollection::SetVisualParent(class UNoesisVisual* InVisualParent)
{
	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(NoesisComponent.GetPtr());
	check(NoesisVisualCollection);
	NoesisVisualCollection->SetVisualParent(NsDynamicCast<Visual*>(InVisualParent->NoesisComponent.GetPtr()));
}

void UNoesisVisualCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(NoesisComponent.GetPtr());
	check(NoesisVisualCollection);


}

void UNoesisVisualCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VisualCollection* NoesisVisualCollection = NsDynamicCast<Noesis::Gui::VisualCollection*>(NoesisComponent.GetPtr());
	check(NoesisVisualCollection);


}

