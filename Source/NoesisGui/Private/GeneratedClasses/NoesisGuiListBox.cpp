////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiListBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiListBox::UNoesisGuiListBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiListBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(InNoesisComponent);
	check(NoesisListBox);

}

	void UNoesisGuiListBox::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	if (!NoesisListBox)
		return;

}

