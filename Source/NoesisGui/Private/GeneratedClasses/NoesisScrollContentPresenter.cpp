////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisScrollContentPresenter.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisScrollContentPresenter::UNoesisScrollContentPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ScrollContentPresenter::StaticGetClassType();
}

void UNoesisScrollContentPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(InNoesisComponent);
	check(NoesisScrollContentPresenter);
}

bool UNoesisScrollContentPresenter::GetCanContentScroll()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return NoesisScrollContentPresenter->GetCanContentScroll();
}

void UNoesisScrollContentPresenter::SetCanContentScroll(bool InCanContentScroll)
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	NoesisScrollContentPresenter->SetCanContentScroll(InCanContentScroll);
}

void UNoesisScrollContentPresenter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);


}

void UNoesisScrollContentPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);


}

