////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisToolTipService.h"

using namespace Noesis;
using namespace Gui;

UNoesisToolTipService::UNoesisToolTipService(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ToolTipService::StaticGetClassType();
}

void UNoesisToolTipService::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolTipService* NoesisToolTipService = NsDynamicCast<Noesis::Gui::ToolTipService*>(InNoesisComponent);
	check(NoesisToolTipService);
}

void UNoesisToolTipService::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToolTipService* NoesisToolTipService = NsDynamicCast<Noesis::Gui::ToolTipService*>(NoesisComponent.GetPtr());
	check(NoesisToolTipService);


}

void UNoesisToolTipService::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToolTipService* NoesisToolTipService = NsDynamicCast<Noesis::Gui::ToolTipService*>(NoesisComponent.GetPtr());
	check(NoesisToolTipService);


}

