////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisualStateGroup.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisualStateGroup::UNoesisGuiVisualStateGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisualStateGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(InNoesisComponent);
	check(NoesisVisualStateGroup);

}

FString UNoesisGuiVisualStateGroup::GetName()
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	return NsStringToFString(NoesisVisualStateGroup->GetName());
}

class UNoesisGuiVisualStateCollection* UNoesisGuiVisualStateGroup::GetStates()
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	return CastChecked<UNoesisGuiVisualStateCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualStateGroup->GetStates()));
}

class UNoesisGuiVisualTransitionCollection* UNoesisGuiVisualStateGroup::GetTransitions()
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	return CastChecked<UNoesisGuiVisualTransitionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualStateGroup->GetTransitions()));
}

class UNoesisGuiVisualState* UNoesisGuiVisualStateGroup::FindState(FName InName)
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	NsSymbol NoesisInName = Noesis::Core::Symbol(InName.GetPlainANSIString());
	return CastChecked<UNoesisGuiVisualState>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualStateGroup->FindState(NoesisInName)));
}

class UNoesisGuiVisualState* UNoesisGuiVisualStateGroup::GetCurrentState(class UNoesisGuiFrameworkElement* InFe)
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	FrameworkElement* NoesisInFe = NsDynamicCast<FrameworkElement*>(InFe->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiVisualState>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualStateGroup->GetCurrentState(NoesisInFe)));
}

void UNoesisGuiVisualStateGroup::UpdateAnimations(class UNoesisGuiFrameworkElement* InFe, class UNoesisGuiStoryboard* InStoryboard1, class UNoesisGuiStoryboard* InStoryboard2)
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	FrameworkElement* NoesisInFe = NsDynamicCast<FrameworkElement*>(InFe->NoesisComponent.GetPtr());
	Storyboard* NoesisInStoryboard1 = NsDynamicCast<Storyboard*>(InStoryboard1->NoesisComponent.GetPtr());
	Storyboard* NoesisInStoryboard2 = NsDynamicCast<Storyboard*>(InStoryboard2->NoesisComponent.GetPtr());
	return NoesisVisualStateGroup->UpdateAnimations(NoesisInFe, NoesisInStoryboard1, NoesisInStoryboard2);
}

	void UNoesisGuiVisualStateGroup::BeginDestroy()
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	if (!NoesisVisualStateGroup)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

