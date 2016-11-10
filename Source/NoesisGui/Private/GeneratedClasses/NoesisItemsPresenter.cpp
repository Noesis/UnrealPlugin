////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisItemsPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisItemsPresenter::UNoesisItemsPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisItemsPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemsPresenter* NoesisItemsPresenter = NsDynamicCast<Noesis::Gui::ItemsPresenter*>(InNoesisComponent);
	check(NoesisItemsPresenter);
}

void UNoesisItemsPresenter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ItemsPresenter* NoesisItemsPresenter = NsDynamicCast<Noesis::Gui::ItemsPresenter*>(NoesisComponent.GetPtr());
	check(NoesisItemsPresenter)


}

void UNoesisItemsPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ItemsPresenter* NoesisItemsPresenter = NsDynamicCast<Noesis::Gui::ItemsPresenter*>(NoesisComponent.GetPtr());
	check(NoesisItemsPresenter)


}

