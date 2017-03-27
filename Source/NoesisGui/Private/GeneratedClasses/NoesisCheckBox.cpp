////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisCheckBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisCheckBox::UNoesisCheckBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::CheckBox::StaticGetClassType();
}

void UNoesisCheckBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CheckBox* NoesisCheckBox = NsDynamicCast<Noesis::Gui::CheckBox*>(InNoesisComponent);
	check(NoesisCheckBox);
}

void UNoesisCheckBox::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CheckBox* NoesisCheckBox = NsDynamicCast<Noesis::Gui::CheckBox*>(NoesisComponent.GetPtr());
	check(NoesisCheckBox);


}

void UNoesisCheckBox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CheckBox* NoesisCheckBox = NsDynamicCast<Noesis::Gui::CheckBox*>(NoesisComponent.GetPtr());
	check(NoesisCheckBox);


}

