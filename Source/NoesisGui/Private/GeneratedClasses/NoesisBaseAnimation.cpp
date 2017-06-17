////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisBaseAnimation.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseAnimation::UNoesisBaseAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BaseAnimation::StaticGetClassType();
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
	return CastChecked<UNoesisEasingFunctionBase>(CreateClassFor(NoesisBaseAnimation->GetEasingFunction(), nullptr), ECastCheckedType::NullAllowed);
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
	check(NoesisBaseAnimation);


}

void UNoesisBaseAnimation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseAnimation* NoesisBaseAnimation = NsDynamicCast<Noesis::Gui::BaseAnimation*>(NoesisComponent.GetPtr());
	check(NoesisBaseAnimation);


}

