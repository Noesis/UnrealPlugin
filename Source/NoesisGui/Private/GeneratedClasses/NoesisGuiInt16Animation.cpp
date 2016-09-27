////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInt16Animation.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInt16Animation::UNoesisGuiInt16Animation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInt16Animation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<NsInt16>* NoesisInt16Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt16>*>(InNoesisComponent);
	check(NoesisInt16Animation);

}

	void UNoesisGuiInt16Animation::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Animation<NsInt16>* NoesisInt16Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt16>*>(NoesisComponent.GetPtr());
	if (!NoesisInt16Animation)
		return;

}

