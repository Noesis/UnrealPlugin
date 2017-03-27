////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisPauseStoryboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisPauseStoryboard::UNoesisPauseStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::PauseStoryboard::StaticGetClassType();
}

void UNoesisPauseStoryboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PauseStoryboard* NoesisPauseStoryboard = NsDynamicCast<Noesis::Gui::PauseStoryboard*>(InNoesisComponent);
	check(NoesisPauseStoryboard);
}

void UNoesisPauseStoryboard::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::PauseStoryboard* NoesisPauseStoryboard = NsDynamicCast<Noesis::Gui::PauseStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisPauseStoryboard);


}

void UNoesisPauseStoryboard::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::PauseStoryboard* NoesisPauseStoryboard = NsDynamicCast<Noesis::Gui::PauseStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisPauseStoryboard);


}

