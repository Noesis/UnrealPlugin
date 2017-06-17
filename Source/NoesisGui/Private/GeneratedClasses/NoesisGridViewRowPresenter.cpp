////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisGridViewRowPresenter.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisGridViewRowPresenter::UNoesisGridViewRowPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::GridViewRowPresenter::StaticGetClassType();
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
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisGridViewRowPresenter->GetContent(), nullptr), ECastCheckedType::NullAllowed);
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
	check(NoesisGridViewRowPresenter);


}

void UNoesisGridViewRowPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GridViewRowPresenter* NoesisGridViewRowPresenter = NsDynamicCast<Noesis::Gui::GridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewRowPresenter);


}

