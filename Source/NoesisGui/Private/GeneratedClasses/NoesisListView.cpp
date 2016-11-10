////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisListView.h"

using namespace Noesis;
using namespace Gui;

UNoesisListView::UNoesisListView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisListView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ListView* NoesisListView = NsDynamicCast<Noesis::Gui::ListView*>(InNoesisComponent);
	check(NoesisListView);
}

class UNoesisBaseView* UNoesisListView::GetView()
{
	Noesis::Gui::ListView* NoesisListView = NsDynamicCast<Noesis::Gui::ListView*>(NoesisComponent.GetPtr());
	check(NoesisListView);
	return CastChecked<UNoesisBaseView>(Instance->FindUnrealComponentForNoesisComponent(NoesisListView->GetView()));
}

void UNoesisListView::SetView(class UNoesisBaseView* InView)
{
	Noesis::Gui::ListView* NoesisListView = NsDynamicCast<Noesis::Gui::ListView*>(NoesisComponent.GetPtr());
	check(NoesisListView);
	NoesisListView->SetView(NsDynamicCast<BaseView*>(InView->NoesisComponent.GetPtr()));
}

void UNoesisListView::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ListView* NoesisListView = NsDynamicCast<Noesis::Gui::ListView*>(NoesisComponent.GetPtr());
	check(NoesisListView)


}

void UNoesisListView::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ListView* NoesisListView = NsDynamicCast<Noesis::Gui::ListView*>(NoesisComponent.GetPtr());
	check(NoesisListView)


}

