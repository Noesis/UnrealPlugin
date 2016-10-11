////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiWrapPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiWrapPanel::UNoesisGuiWrapPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiWrapPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(InNoesisComponent);
	check(NoesisWrapPanel);

}

	void UNoesisGuiWrapPanel::BeginDestroy()
{
	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	if (!NoesisWrapPanel)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

