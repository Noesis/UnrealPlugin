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

	void UNoesisGuiVisualStateGroup::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::VisualStateGroup* NoesisVisualStateGroup = NsDynamicCast<Noesis::Gui::VisualStateGroup*>(NoesisComponent.GetPtr());
	if (!NoesisVisualStateGroup)
		return;

}

