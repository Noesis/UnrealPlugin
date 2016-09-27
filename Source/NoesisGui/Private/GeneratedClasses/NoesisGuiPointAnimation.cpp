////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPointAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPointAnimation::UNoesisGuiPointAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPointAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<Noesis::Drawing::Point>* NoesisPointAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisPointAnimation);

}

	void UNoesisGuiPointAnimation::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Animation<Noesis::Drawing::Point>* NoesisPointAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	if (!NoesisPointAnimation)
		return;

}

