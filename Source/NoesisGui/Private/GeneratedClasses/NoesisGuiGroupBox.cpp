////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGroupBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGroupBox::UNoesisGuiGroupBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGroupBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GroupBox* NoesisGroupBox = NsDynamicCast<Noesis::Gui::GroupBox*>(InNoesisComponent);
	check(NoesisGroupBox);

}

	void UNoesisGuiGroupBox::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::GroupBox* NoesisGroupBox = NsDynamicCast<Noesis::Gui::GroupBox*>(NoesisComponent.GetPtr());
	if (!NoesisGroupBox)
		return;

}

