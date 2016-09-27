////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseAnimation::UNoesisGuiBaseAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseAnimation* NoesisBaseAnimation = NsDynamicCast<Noesis::Gui::BaseAnimation*>(InNoesisComponent);
	check(NoesisBaseAnimation);

}

	void UNoesisGuiBaseAnimation::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::BaseAnimation* NoesisBaseAnimation = NsDynamicCast<Noesis::Gui::BaseAnimation*>(NoesisComponent.GetPtr());
	if (!NoesisBaseAnimation)
		return;

}

