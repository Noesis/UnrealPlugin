////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisVisualTransition.h"

using namespace Noesis;
using namespace Gui;

UNoesisVisualTransition::UNoesisVisualTransition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisVisualTransition::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(InNoesisComponent);
	check(NoesisVisualTransition);
}

FName UNoesisVisualTransition::GetFrom()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return FName(NoesisVisualTransition->GetFrom().GetStr());
}

void UNoesisVisualTransition::SetFrom(FName InFrom)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetFrom(Noesis::Core::Symbol(InFrom.GetPlainANSIString()));
}

FNoesisDuration UNoesisVisualTransition::GetGeneratedDuration()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return FNoesisDuration(NoesisVisualTransition->GetGeneratedDuration());
}

void UNoesisVisualTransition::SetGeneratedDuration(FNoesisDuration InGeneratedDuration)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetGeneratedDuration(InGeneratedDuration.ToNoesis());
}

class UNoesisEasingFunctionBase* UNoesisVisualTransition::GetGeneratedEasingFunction()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return CastChecked<UNoesisEasingFunctionBase>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualTransition->GetGeneratedEasingFunction()));
}

void UNoesisVisualTransition::SetGeneratedEasingFunction(class UNoesisEasingFunctionBase* InGeneratedEasingFunction)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetGeneratedEasingFunction(NsDynamicCast<EasingFunctionBase*>(InGeneratedEasingFunction->NoesisComponent.GetPtr()));
}

class UNoesisStoryboard* UNoesisVisualTransition::GetStoryboard()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return CastChecked<UNoesisStoryboard>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualTransition->GetStoryboard()));
}

void UNoesisVisualTransition::SetStoryboard(class UNoesisStoryboard* InStoryboard)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetStoryboard(NsDynamicCast<Storyboard*>(InStoryboard->NoesisComponent.GetPtr()));
}

FName UNoesisVisualTransition::GetTo()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return FName(NoesisVisualTransition->GetTo().GetStr());
}

void UNoesisVisualTransition::SetTo(FName InTo)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetTo(Noesis::Core::Symbol(InTo.GetPlainANSIString()));
}

bool UNoesisVisualTransition::IsDefault()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return NoesisVisualTransition->IsDefault();
}

void UNoesisVisualTransition::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition)


}

void UNoesisVisualTransition::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition)


}

