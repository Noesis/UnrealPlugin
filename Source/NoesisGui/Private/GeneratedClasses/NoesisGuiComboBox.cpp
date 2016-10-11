////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiComboBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiComboBox::UNoesisGuiComboBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiComboBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(InNoesisComponent);
	check(NoesisComboBox);

}

	void UNoesisGuiComboBox::BeginDestroy()
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	if (!NoesisComboBox)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

