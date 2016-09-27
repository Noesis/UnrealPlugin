////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseView.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseView::UNoesisGuiBaseView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(InNoesisComponent);
	check(NoesisBaseView);

}

	void UNoesisGuiBaseView::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::BaseView* NoesisBaseView = NsDynamicCast<Noesis::Gui::BaseView*>(NoesisComponent.GetPtr());
	if (!NoesisBaseView)
		return;

}

