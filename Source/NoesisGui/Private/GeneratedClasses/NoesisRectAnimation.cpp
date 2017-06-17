////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisRectAnimation.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisRectAnimation::UNoesisRectAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Animation<Noesis::Drawing::Rect>::StaticGetClassType();
}

void UNoesisRectAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<Noesis::Drawing::Rect>* NoesisRectAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisRectAnimation);
}

void UNoesisRectAnimation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Rect>* NoesisRectAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectAnimation);


}

void UNoesisRectAnimation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Rect>* NoesisRectAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectAnimation);


}

