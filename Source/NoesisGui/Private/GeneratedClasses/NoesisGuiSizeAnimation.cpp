////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSizeAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSizeAnimation::UNoesisGuiSizeAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSizeAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<Noesis::Drawing::Size>* NoesisSizeAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisSizeAnimation);
}

void UNoesisGuiSizeAnimation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Size>* NoesisSizeAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeAnimation)


}

void UNoesisGuiSizeAnimation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Size>* NoesisSizeAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeAnimation)


}

