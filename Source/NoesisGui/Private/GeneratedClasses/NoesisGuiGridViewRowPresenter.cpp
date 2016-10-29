////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGridViewRowPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGridViewRowPresenter::UNoesisGuiGridViewRowPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGridViewRowPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GridViewRowPresenter* NoesisGridViewRowPresenter = NsDynamicCast<Noesis::Gui::GridViewRowPresenter*>(InNoesisComponent);
	check(NoesisGridViewRowPresenter);
}

void UNoesisGuiGridViewRowPresenter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GridViewRowPresenter* NoesisGridViewRowPresenter = NsDynamicCast<Noesis::Gui::GridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewRowPresenter)


}

void UNoesisGuiGridViewRowPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GridViewRowPresenter* NoesisGridViewRowPresenter = NsDynamicCast<Noesis::Gui::GridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewRowPresenter)


}

