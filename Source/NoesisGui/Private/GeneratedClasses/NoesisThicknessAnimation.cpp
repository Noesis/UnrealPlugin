////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisThicknessAnimation.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisThicknessAnimation::UNoesisThicknessAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Animation<Noesis::Drawing::Thickness>::StaticGetClassType();
}

void UNoesisThicknessAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<Noesis::Drawing::Thickness>* NoesisThicknessAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisThicknessAnimation);
}

void UNoesisThicknessAnimation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Thickness>* NoesisThicknessAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisThicknessAnimation);


}

void UNoesisThicknessAnimation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animation<Noesis::Drawing::Thickness>* NoesisThicknessAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisThicknessAnimation);


}

