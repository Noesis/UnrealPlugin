////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDoubleAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisDoubleAnimation::UNoesisDoubleAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDoubleAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<NsFloat32>* NoesisDoubleAnimation = NsDynamicCast<Noesis::Gui::Animation<NsFloat32>*>(InNoesisComponent);
	check(NoesisDoubleAnimation);
}

void UNoesisDoubleAnimation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animation<NsFloat32>* NoesisDoubleAnimation = NsDynamicCast<Noesis::Gui::Animation<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleAnimation)


}

void UNoesisDoubleAnimation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animation<NsFloat32>* NoesisDoubleAnimation = NsDynamicCast<Noesis::Gui::Animation<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleAnimation)


}

