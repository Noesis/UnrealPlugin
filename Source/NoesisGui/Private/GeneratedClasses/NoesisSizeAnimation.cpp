////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisSizeAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisSizeAnimation::UNoesisSizeAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Animation<Noesis::Drawing::Size>::StaticGetClassType();
}

void UNoesisSizeAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<Noesis::Drawing::Size>* NoesisSizeAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisSizeAnimation);
}

void UNoesisSizeAnimation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Size>* NoesisSizeAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeAnimation);


}

void UNoesisSizeAnimation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Size>* NoesisSizeAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeAnimation);


}

