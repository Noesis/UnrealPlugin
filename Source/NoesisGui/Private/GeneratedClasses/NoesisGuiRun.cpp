////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRun.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRun::UNoesisGuiRun(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRun::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Run* NoesisRun = NsDynamicCast<Noesis::Gui::Run*>(InNoesisComponent);
	check(NoesisRun);
}

void UNoesisGuiRun::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Run* NoesisRun = NsDynamicCast<Noesis::Gui::Run*>(NoesisComponent.GetPtr());
	check(NoesisRun)


}

void UNoesisGuiRun::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Run* NoesisRun = NsDynamicCast<Noesis::Gui::Run*>(NoesisComponent.GetPtr());
	check(NoesisRun)


}

