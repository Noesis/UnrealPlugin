////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisGradientStopCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisGradientStopCollection::UNoesisGradientStopCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::GradientStopCollection::StaticGetClassType();
}

void UNoesisGradientStopCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GradientStopCollection* NoesisGradientStopCollection = NsDynamicCast<Noesis::Gui::GradientStopCollection*>(InNoesisComponent);
	check(NoesisGradientStopCollection);
}

void UNoesisGradientStopCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GradientStopCollection* NoesisGradientStopCollection = NsDynamicCast<Noesis::Gui::GradientStopCollection*>(NoesisComponent.GetPtr());
	check(NoesisGradientStopCollection);


}

void UNoesisGradientStopCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GradientStopCollection* NoesisGradientStopCollection = NsDynamicCast<Noesis::Gui::GradientStopCollection*>(NoesisComponent.GetPtr());
	check(NoesisGradientStopCollection);


}

