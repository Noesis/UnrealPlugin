////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiStopStoryboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiStopStoryboard::UNoesisGuiStopStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiStopStoryboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StopStoryboard* NoesisStopStoryboard = NsDynamicCast<Noesis::Gui::StopStoryboard*>(InNoesisComponent);
	check(NoesisStopStoryboard);
}

void UNoesisGuiStopStoryboard::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::StopStoryboard* NoesisStopStoryboard = NsDynamicCast<Noesis::Gui::StopStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisStopStoryboard)


}

void UNoesisGuiStopStoryboard::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::StopStoryboard* NoesisStopStoryboard = NsDynamicCast<Noesis::Gui::StopStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisStopStoryboard)


}

