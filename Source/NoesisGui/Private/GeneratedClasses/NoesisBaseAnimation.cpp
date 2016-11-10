////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBaseAnimation.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseAnimation::UNoesisBaseAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBaseAnimation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseAnimation* NoesisBaseAnimation = NsDynamicCast<Noesis::Gui::BaseAnimation*>(InNoesisComponent);
	check(NoesisBaseAnimation);
}

class UNoesisEasingFunctionBase* UNoesisBaseAnimation::GetEasingFunction()
{
	Noesis::Gui::BaseAnimation* NoesisBaseAnimation = NsDynamicCast<Noesis::Gui::BaseAnimation*>(NoesisComponent.GetPtr());
	check(NoesisBaseAnimation);
	return CastChecked<UNoesisEasingFunctionBase>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseAnimation->GetEasingFunction()));
}

void UNoesisBaseAnimation::SetEasingFunction(class UNoesisEasingFunctionBase* InEasingFunction)
{
	Noesis::Gui::BaseAnimation* NoesisBaseAnimation = NsDynamicCast<Noesis::Gui::BaseAnimation*>(NoesisComponent.GetPtr());
	check(NoesisBaseAnimation);
	NoesisBaseAnimation->SetEasingFunction(NsDynamicCast<EasingFunctionBase*>(InEasingFunction->NoesisComponent.GetPtr()));
}

void UNoesisBaseAnimation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseAnimation* NoesisBaseAnimation = NsDynamicCast<Noesis::Gui::BaseAnimation*>(NoesisComponent.GetPtr());
	check(NoesisBaseAnimation)


}

void UNoesisBaseAnimation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseAnimation* NoesisBaseAnimation = NsDynamicCast<Noesis::Gui::BaseAnimation*>(NoesisComponent.GetPtr());
	check(NoesisBaseAnimation)


}

