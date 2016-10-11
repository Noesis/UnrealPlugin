////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiAdornerDecorator.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiAdornerDecorator::UNoesisGuiAdornerDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiAdornerDecorator::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AdornerDecorator* NoesisAdornerDecorator = NsDynamicCast<Noesis::Gui::AdornerDecorator*>(InNoesisComponent);
	check(NoesisAdornerDecorator);

}

	void UNoesisGuiAdornerDecorator::BeginDestroy()
{
	Noesis::Gui::AdornerDecorator* NoesisAdornerDecorator = NsDynamicCast<Noesis::Gui::AdornerDecorator*>(NoesisComponent.GetPtr());
	if (!NoesisAdornerDecorator)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

