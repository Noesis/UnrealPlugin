////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGridViewRowPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGridViewRowPresenter::UNoesisGridViewRowPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGridViewRowPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GridViewRowPresenter* NoesisGridViewRowPresenter = NsDynamicCast<Noesis::Gui::GridViewRowPresenter*>(InNoesisComponent);
	check(NoesisGridViewRowPresenter);
}

class UNoesisBaseComponent* UNoesisGridViewRowPresenter::GetContent()
{
	Noesis::Gui::GridViewRowPresenter* NoesisGridViewRowPresenter = NsDynamicCast<Noesis::Gui::GridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewRowPresenter);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewRowPresenter->GetContent()));
}

void UNoesisGridViewRowPresenter::SetContent(class UNoesisBaseComponent* InContent)
{
	Noesis::Gui::GridViewRowPresenter* NoesisGridViewRowPresenter = NsDynamicCast<Noesis::Gui::GridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewRowPresenter);
	NoesisGridViewRowPresenter->SetContent(NsDynamicCast<Core::BaseComponent*>(InContent->NoesisComponent.GetPtr()));
}

void UNoesisGridViewRowPresenter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GridViewRowPresenter* NoesisGridViewRowPresenter = NsDynamicCast<Noesis::Gui::GridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewRowPresenter)


}

void UNoesisGridViewRowPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GridViewRowPresenter* NoesisGridViewRowPresenter = NsDynamicCast<Noesis::Gui::GridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewRowPresenter)


}

