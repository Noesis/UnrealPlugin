////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBaseGridViewRowPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseGridViewRowPresenter::UNoesisBaseGridViewRowPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBaseGridViewRowPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseGridViewRowPresenter* NoesisBaseGridViewRowPresenter = NsDynamicCast<Noesis::Gui::BaseGridViewRowPresenter*>(InNoesisComponent);
	check(NoesisBaseGridViewRowPresenter);
}

class UNoesisGridViewColumnCollection* UNoesisBaseGridViewRowPresenter::GetColumns()
{
	Noesis::Gui::BaseGridViewRowPresenter* NoesisBaseGridViewRowPresenter = NsDynamicCast<Noesis::Gui::BaseGridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisBaseGridViewRowPresenter);
	return CastChecked<UNoesisGridViewColumnCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseGridViewRowPresenter->GetColumns()));
}

void UNoesisBaseGridViewRowPresenter::SetColumns(class UNoesisGridViewColumnCollection* InColumns)
{
	Noesis::Gui::BaseGridViewRowPresenter* NoesisBaseGridViewRowPresenter = NsDynamicCast<Noesis::Gui::BaseGridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisBaseGridViewRowPresenter);
	NoesisBaseGridViewRowPresenter->SetColumns(NsDynamicCast<GridViewColumnCollection*>(InColumns->NoesisComponent.GetPtr()));
}

void UNoesisBaseGridViewRowPresenter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseGridViewRowPresenter* NoesisBaseGridViewRowPresenter = NsDynamicCast<Noesis::Gui::BaseGridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisBaseGridViewRowPresenter)


}

void UNoesisBaseGridViewRowPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseGridViewRowPresenter* NoesisBaseGridViewRowPresenter = NsDynamicCast<Noesis::Gui::BaseGridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisBaseGridViewRowPresenter)


}

