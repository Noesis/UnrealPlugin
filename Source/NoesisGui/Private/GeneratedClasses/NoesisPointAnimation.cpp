////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisPointAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisPointAnimation::UNoesisPointAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Animation<Noesis::Drawing::Point>::StaticGetClassType();
}

void UNoesisPointAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<Noesis::Drawing::Point>* NoesisPointAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisPointAnimation);
}

void UNoesisPointAnimation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Point>* NoesisPointAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisPointAnimation);


}

void UNoesisPointAnimation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Point>* NoesisPointAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisPointAnimation);


}

