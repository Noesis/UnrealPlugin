////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRectAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRectAnimation::UNoesisGuiRectAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRectAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<Noesis::Drawing::Rect>* NoesisRectAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisRectAnimation);

}

	void UNoesisGuiRectAnimation::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Animation<Noesis::Drawing::Rect>* NoesisRectAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	if (!NoesisRectAnimation)
		return;

}

