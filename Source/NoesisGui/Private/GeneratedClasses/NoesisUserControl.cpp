////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisUserControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisUserControl::UNoesisUserControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisUserControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::UserControl* NoesisUserControl = NsDynamicCast<Noesis::Gui::UserControl*>(InNoesisComponent);
	check(NoesisUserControl);
}

void UNoesisUserControl::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::UserControl* NoesisUserControl = NsDynamicCast<Noesis::Gui::UserControl*>(NoesisComponent.GetPtr());
	check(NoesisUserControl)


}

void UNoesisUserControl::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::UserControl* NoesisUserControl = NsDynamicCast<Noesis::Gui::UserControl*>(NoesisComponent.GetPtr());
	check(NoesisUserControl)


}

