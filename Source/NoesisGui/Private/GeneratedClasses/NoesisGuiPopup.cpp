////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPopup.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPopup::UNoesisGuiPopup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPopup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(InNoesisComponent);
	check(NoesisPopup);

}

	void UNoesisGuiPopup::BeginDestroy()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	if (!NoesisPopup)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

