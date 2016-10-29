////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInt32Animation.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInt32Animation::UNoesisGuiInt32Animation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInt32Animation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<NsInt32>* NoesisInt32Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt32>*>(InNoesisComponent);
	check(NoesisInt32Animation);
}

void UNoesisGuiInt32Animation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animation<NsInt32>* NoesisInt32Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32Animation)


}

void UNoesisGuiInt32Animation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animation<NsInt32>* NoesisInt32Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32Animation)


}

