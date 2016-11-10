////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisAdornerDecorator.h"

using namespace Noesis;
using namespace Gui;

UNoesisAdornerDecorator::UNoesisAdornerDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisAdornerDecorator::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AdornerDecorator* NoesisAdornerDecorator = NsDynamicCast<Noesis::Gui::AdornerDecorator*>(InNoesisComponent);
	check(NoesisAdornerDecorator);
}

void UNoesisAdornerDecorator::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AdornerDecorator* NoesisAdornerDecorator = NsDynamicCast<Noesis::Gui::AdornerDecorator*>(NoesisComponent.GetPtr());
	check(NoesisAdornerDecorator)


}

void UNoesisAdornerDecorator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AdornerDecorator* NoesisAdornerDecorator = NsDynamicCast<Noesis::Gui::AdornerDecorator*>(NoesisComponent.GetPtr());
	check(NoesisAdornerDecorator)


}

