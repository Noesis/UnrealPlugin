////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiThicknessAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiThicknessAnimation::UNoesisGuiThicknessAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiThicknessAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<Noesis::Drawing::Thickness>* NoesisThicknessAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisThicknessAnimation);

}

	void UNoesisGuiThicknessAnimation::BeginDestroy()
{
	Noesis::Gui::Animation<Noesis::Drawing::Thickness>* NoesisThicknessAnimation = NsDynamicCast<Noesis::Gui::Animation<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	if (!NoesisThicknessAnimation)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

