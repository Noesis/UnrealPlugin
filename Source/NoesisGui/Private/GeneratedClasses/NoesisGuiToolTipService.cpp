////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiToolTipService.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiToolTipService::UNoesisGuiToolTipService(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiToolTipService::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolTipService* NoesisToolTipService = NsDynamicCast<Noesis::Gui::ToolTipService*>(InNoesisComponent);
	check(NoesisToolTipService);
}

void UNoesisGuiToolTipService::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToolTipService* NoesisToolTipService = NsDynamicCast<Noesis::Gui::ToolTipService*>(NoesisComponent.GetPtr());
	check(NoesisToolTipService)


}

void UNoesisGuiToolTipService::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToolTipService* NoesisToolTipService = NsDynamicCast<Noesis::Gui::ToolTipService*>(NoesisComponent.GetPtr());
	check(NoesisToolTipService)


}

