////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiItemsPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiItemsPresenter::UNoesisGuiItemsPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiItemsPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemsPresenter* NoesisItemsPresenter = NsDynamicCast<Noesis::Gui::ItemsPresenter*>(InNoesisComponent);
	check(NoesisItemsPresenter);

}

	void UNoesisGuiItemsPresenter::BeginDestroy()
{
	Noesis::Gui::ItemsPresenter* NoesisItemsPresenter = NsDynamicCast<Noesis::Gui::ItemsPresenter*>(NoesisComponent.GetPtr());
	if (!NoesisItemsPresenter)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

