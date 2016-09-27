////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiProgressBar.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiProgressBar::UNoesisGuiProgressBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiProgressBar::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ProgressBar* NoesisProgressBar = NsDynamicCast<Noesis::Gui::ProgressBar*>(InNoesisComponent);
	check(NoesisProgressBar);

}

	void UNoesisGuiProgressBar::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ProgressBar* NoesisProgressBar = NsDynamicCast<Noesis::Gui::ProgressBar*>(NoesisComponent.GetPtr());
	if (!NoesisProgressBar)
		return;

}

