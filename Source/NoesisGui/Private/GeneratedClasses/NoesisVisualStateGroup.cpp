////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisVisualStateGroup.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisVisualStateGroup::UNoesisVisualStateGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::VisualStateGroup::StaticGetClassType();
}

void UNoesisVisualStateGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(InNoesisComponent);
	check(NoesisVisualStateGroup);
}

FString UNoesisVisualStateGroup::GetName()
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	return NsStringToFString(NoesisVisualStateGroup->GetName());
}

class UNoesisVisualStateCollection* UNoesisVisualStateGroup::GetStates()
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	return CastChecked<UNoesisVisualStateCollection>(CreateClassFor(NoesisVisualStateGroup->GetStates(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisVisualTransitionCollection* UNoesisVisualStateGroup::GetTransitions()
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	return CastChecked<UNoesisVisualTransitionCollection>(CreateClassFor(NoesisVisualStateGroup->GetTransitions(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisVisualState* UNoesisVisualStateGroup::FindState(FName InName)
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	NsSymbol NoesisInName = Noesis::Core::Symbol(InName.GetPlainANSIString());
	return CastChecked<UNoesisVisualState>(CreateClassFor(NoesisVisualStateGroup->FindState(NoesisInName), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisVisualState* UNoesisVisualStateGroup::GetCurrentState(class UNoesisFrameworkElement* InFe)
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	FrameworkElement* NoesisInFe = NsDynamicCast<FrameworkElement*>(InFe->NoesisComponent.GetPtr());
	return CastChecked<UNoesisVisualState>(CreateClassFor(NoesisVisualStateGroup->GetCurrentState(NoesisInFe), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisVisualStateGroup::UpdateAnimations(class UNoesisFrameworkElement* InFe, class UNoesisStoryboard* InStoryboard1, class UNoesisStoryboard* InStoryboard2)
{
	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);
	FrameworkElement* NoesisInFe = NsDynamicCast<FrameworkElement*>(InFe->NoesisComponent.GetPtr());
	Storyboard* NoesisInStoryboard1 = NsDynamicCast<Storyboard*>(InStoryboard1->NoesisComponent.GetPtr());
	Storyboard* NoesisInStoryboard2 = NsDynamicCast<Storyboard*>(InStoryboard2->NoesisComponent.GetPtr());
	return NoesisVisualStateGroup->UpdateAnimations(NoesisInFe, NoesisInStoryboard1, NoesisInStoryboard2);
}

void UNoesisVisualStateGroup::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);


}

void UNoesisVisualStateGroup::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateGroup);


}

