////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiContentPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiContentPresenter::UNoesisGuiContentPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiContentPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(InNoesisComponent);
	check(NoesisContentPresenter);

}

	void UNoesisGuiContentPresenter::BeginDestroy()
{
	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	if (!NoesisContentPresenter)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

