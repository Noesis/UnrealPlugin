////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDoubleAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDoubleAnimation::UNoesisGuiDoubleAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDoubleAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<NsFloat32>* NoesisDoubleAnimation = NsDynamicCast<Noesis::Gui::Animation<NsFloat32>*>(InNoesisComponent);
	check(NoesisDoubleAnimation);

}

	void UNoesisGuiDoubleAnimation::BeginDestroy()
{
	Noesis::Gui::Animation<NsFloat32>* NoesisDoubleAnimation = NsDynamicCast<Noesis::Gui::Animation<NsFloat32>*>(NoesisComponent.GetPtr());
	if (!NoesisDoubleAnimation)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

