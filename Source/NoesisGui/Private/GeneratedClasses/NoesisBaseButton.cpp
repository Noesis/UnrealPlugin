////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisBaseButton.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseButton::UNoesisBaseButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BaseButton::StaticGetClassType();
}

void UNoesisBaseButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(InNoesisComponent);
	check(NoesisBaseButton);
}

ENoesisClickMode UNoesisBaseButton::GetClickMode()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return (ENoesisClickMode)NoesisBaseButton->GetClickMode();
}

void UNoesisBaseButton::SetClickMode(ENoesisClickMode InClickMode)
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	NoesisBaseButton->SetClickMode((Noesis::Gui::ClickMode)InClickMode);
}

class UNoesisICommand* UNoesisBaseButton::GetCommand()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return CastChecked<UNoesisICommand>(CreateInterfaceFor(NoesisBaseButton->GetCommand(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisBaseButton::SetCommand(class UNoesisICommand* InCommand)
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	NoesisBaseButton->SetCommand(NsDynamicCast<ICommand*>(InCommand->NoesisInterface.GetPtr()));
}

class UNoesisBaseComponent* UNoesisBaseButton::GetCommandParameter()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisBaseButton->GetCommandParameter(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisBaseButton::SetCommandParameter(class UNoesisBaseComponent* InCommandParameter)
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	NoesisBaseButton->SetCommandParameter(NsDynamicCast<Core::BaseComponent*>(InCommandParameter->NoesisComponent.GetPtr()));
}

class UNoesisUIElement* UNoesisBaseButton::GetCommandTarget()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisBaseButton->GetCommandTarget(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisBaseButton::SetCommandTarget(class UNoesisUIElement* InCommandTarget)
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	NoesisBaseButton->SetCommandTarget(NsDynamicCast<UIElement*>(InCommandTarget->NoesisComponent.GetPtr()));
}

bool UNoesisBaseButton::GetIsPressed()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return NoesisBaseButton->GetIsPressed();
}

void UNoesisBaseButton::Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Click.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Click.Broadcast(Sender, Args);
}

void UNoesisBaseButton::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);

	Click_Delegate = Noesis::MakeDelegate(this, &UNoesisBaseButton::Click_Private);
	NoesisBaseButton->Click() += Click_Delegate;

}

void UNoesisBaseButton::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);

	NoesisBaseButton->Click() -= Click_Delegate;

}

