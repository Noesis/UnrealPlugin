////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisualTransition.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisualTransition::UNoesisGuiVisualTransition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisualTransition::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(InNoesisComponent);
	check(NoesisVisualTransition);

}

FName UNoesisGuiVisualTransition::GetFrom()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return FName(NoesisVisualTransition->GetFrom().GetStr());
}

void UNoesisGuiVisualTransition::SetFrom(FName InFrom)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetFrom(Noesis::Core::Symbol(InFrom.GetPlainANSIString()));
}

FNoesisGuiDuration UNoesisGuiVisualTransition::GetGeneratedDuration()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return FNoesisGuiDuration(NoesisVisualTransition->GetGeneratedDuration());
}

void UNoesisGuiVisualTransition::SetGeneratedDuration(FNoesisGuiDuration InGeneratedDuration)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetGeneratedDuration(InGeneratedDuration.ToNoesis());
}

class UNoesisGuiEasingFunctionBase* UNoesisGuiVisualTransition::GetGeneratedEasingFunction()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return CastChecked<UNoesisGuiEasingFunctionBase>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualTransition->GetGeneratedEasingFunction()));
}

void UNoesisGuiVisualTransition::SetGeneratedEasingFunction(class UNoesisGuiEasingFunctionBase* InGeneratedEasingFunction)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetGeneratedEasingFunction(NsDynamicCast<EasingFunctionBase*>(InGeneratedEasingFunction->NoesisComponent.GetPtr()));
}

class UNoesisGuiStoryboard* UNoesisGuiVisualTransition::GetStoryboard()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return CastChecked<UNoesisGuiStoryboard>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualTransition->GetStoryboard()));
}

void UNoesisGuiVisualTransition::SetStoryboard(class UNoesisGuiStoryboard* InStoryboard)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetStoryboard(NsDynamicCast<Storyboard*>(InStoryboard->NoesisComponent.GetPtr()));
}

FName UNoesisGuiVisualTransition::GetTo()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return FName(NoesisVisualTransition->GetTo().GetStr());
}

void UNoesisGuiVisualTransition::SetTo(FName InTo)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetTo(Noesis::Core::Symbol(InTo.GetPlainANSIString()));
}

bool UNoesisGuiVisualTransition::IsDefault()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return NoesisVisualTransition->IsDefault();
}

	void UNoesisGuiVisualTransition::BeginDestroy()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	if (!NoesisVisualTransition)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

