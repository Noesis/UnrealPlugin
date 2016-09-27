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

FNoesisGuiDuration UNoesisGuiVisualTransition::GetGeneratedDuration()
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	return FNoesisGuiDuration((ENoesisGuiDurationType)NoesisVisualTransition->GetGeneratedDuration().GetDurationType(), (int32)NoesisVisualTransition->GetGeneratedDuration().GetTimeSpan().GetMilliseconds());
}

void UNoesisGuiVisualTransition::SetGeneratedDuration(FNoesisGuiDuration InGeneratedDuration)
{
	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransition);
	NoesisVisualTransition->SetGeneratedDuration(InGeneratedDuration.DurationType == DT_Automatic ? Duration::Automatic() : (InGeneratedDuration.DurationType == DT_Forever ? Duration::Forever() : Duration(Noesis::Gui::TimeSpan(0, 0, 0, 0, InGeneratedDuration.Milliseconds))));
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

	void UNoesisGuiVisualTransition::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::VisualTransition* NoesisVisualTransition = NsDynamicCast<Noesis::Gui::VisualTransition*>(NoesisComponent.GetPtr());
	if (!NoesisVisualTransition)
		return;

}

