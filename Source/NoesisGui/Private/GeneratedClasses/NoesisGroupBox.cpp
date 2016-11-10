////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGroupBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGroupBox::UNoesisGroupBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGroupBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GroupBox* NoesisGroupBox = NsDynamicCast<Noesis::Gui::GroupBox*>(InNoesisComponent);
	check(NoesisGroupBox);
}

void UNoesisGroupBox::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GroupBox* NoesisGroupBox = NsDynamicCast<Noesis::Gui::GroupBox*>(NoesisComponent.GetPtr());
	check(NoesisGroupBox)


}

void UNoesisGroupBox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GroupBox* NoesisGroupBox = NsDynamicCast<Noesis::Gui::GroupBox*>(NoesisComponent.GetPtr());
	check(NoesisGroupBox)


}

