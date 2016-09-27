////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBeginStoryboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBeginStoryboard::UNoesisGuiBeginStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBeginStoryboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(InNoesisComponent);
	check(NoesisBeginStoryboard);

}

ENoesisGuiHandoffBehavior UNoesisGuiBeginStoryboard::GetHandoffBehavior()
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	return (ENoesisGuiHandoffBehavior)NoesisBeginStoryboard->GetHandoffBehavior();
}

void UNoesisGuiBeginStoryboard::SetHandoffBehavior(ENoesisGuiHandoffBehavior InHandoffBehavior)
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	NoesisBeginStoryboard->SetHandoffBehavior((HandoffBehavior)InHandoffBehavior);
}

FString UNoesisGuiBeginStoryboard::GetName()
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	return NsStringToFString(NoesisBeginStoryboard->GetName());
}

void UNoesisGuiBeginStoryboard::SetName(FString InName)
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	NoesisBeginStoryboard->SetName(StringCast<NsChar>(*InName).Get());
}

	void UNoesisGuiBeginStoryboard::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	if (!NoesisBeginStoryboard)
		return;

}

