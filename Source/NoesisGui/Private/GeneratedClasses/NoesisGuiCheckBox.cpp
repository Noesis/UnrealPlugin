////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCheckBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCheckBox::UNoesisGuiCheckBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCheckBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CheckBox* NoesisCheckBox = NsDynamicCast<Noesis::Gui::CheckBox*>(InNoesisComponent);
	check(NoesisCheckBox);

}

	void UNoesisGuiCheckBox::BeginDestroy()
{
	Noesis::Gui::CheckBox* NoesisCheckBox = NsDynamicCast<Noesis::Gui::CheckBox*>(NoesisComponent.GetPtr());
	if (!NoesisCheckBox)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

