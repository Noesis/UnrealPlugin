////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDashStyle.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDashStyle::UNoesisGuiDashStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDashStyle::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(InNoesisComponent);
	check(NoesisDashStyle);
}

void UNoesisGuiDashStyle::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(NoesisComponent.GetPtr());
	check(NoesisDashStyle)


}

void UNoesisGuiDashStyle::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(NoesisComponent.GetPtr());
	check(NoesisDashStyle)


}

