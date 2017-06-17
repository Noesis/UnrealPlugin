////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisBeginStoryboard.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisBeginStoryboard::UNoesisBeginStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BeginStoryboard::StaticGetClassType();
}

void UNoesisBeginStoryboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(InNoesisComponent);
	check(NoesisBeginStoryboard);
}

ENoesisHandoffBehavior UNoesisBeginStoryboard::GetHandoffBehavior()
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	return (ENoesisHandoffBehavior)NoesisBeginStoryboard->GetHandoffBehavior();
}

void UNoesisBeginStoryboard::SetHandoffBehavior(ENoesisHandoffBehavior InHandoffBehavior)
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	NoesisBeginStoryboard->SetHandoffBehavior((Noesis::Gui::HandoffBehavior)InHandoffBehavior);
}

FString UNoesisBeginStoryboard::GetName()
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	return NsStringToFString(NoesisBeginStoryboard->GetName());
}

void UNoesisBeginStoryboard::SetName(FString InName)
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	NoesisBeginStoryboard->SetName(StringCast<NsChar>(*InName).Get());
}

class UNoesisStoryboard* UNoesisBeginStoryboard::GetStoryboard()
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	return CastChecked<UNoesisStoryboard>(CreateClassFor(NoesisBeginStoryboard->GetStoryboard(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisBeginStoryboard::SetStoryboard(class UNoesisStoryboard* InStoryboard)
{
	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);
	NoesisBeginStoryboard->SetStoryboard(NsDynamicCast<Storyboard*>(InStoryboard->NoesisComponent.GetPtr()));
}

void UNoesisBeginStoryboard::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);


}

void UNoesisBeginStoryboard::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BeginStoryboard* NoesisBeginStoryboard = NsDynamicCast<Noesis::Gui::BeginStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisBeginStoryboard);


}

