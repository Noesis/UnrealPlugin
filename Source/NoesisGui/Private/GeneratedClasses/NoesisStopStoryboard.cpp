////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisStopStoryboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisStopStoryboard::UNoesisStopStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::StopStoryboard::StaticGetClassType();
}

void UNoesisStopStoryboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StopStoryboard* NoesisStopStoryboard = NsDynamicCast<Noesis::Gui::StopStoryboard*>(InNoesisComponent);
	check(NoesisStopStoryboard);
}

void UNoesisStopStoryboard::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::StopStoryboard* NoesisStopStoryboard = NsDynamicCast<Noesis::Gui::StopStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisStopStoryboard);


}

void UNoesisStopStoryboard::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::StopStoryboard* NoesisStopStoryboard = NsDynamicCast<Noesis::Gui::StopStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisStopStoryboard);


}

