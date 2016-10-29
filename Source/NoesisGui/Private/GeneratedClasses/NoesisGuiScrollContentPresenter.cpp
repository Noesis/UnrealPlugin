////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiScrollContentPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiScrollContentPresenter::UNoesisGuiScrollContentPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiScrollContentPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(InNoesisComponent);
	check(NoesisScrollContentPresenter);
}

void UNoesisGuiScrollContentPresenter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter)


}

void UNoesisGuiScrollContentPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter)


}

