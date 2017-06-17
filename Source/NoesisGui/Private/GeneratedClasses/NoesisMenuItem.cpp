////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisMenuItem.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisMenuItem::UNoesisMenuItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::MenuItem::StaticGetClassType();
}

void UNoesisMenuItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(InNoesisComponent);
	check(NoesisMenuItem);
}

class UNoesisICommand* UNoesisMenuItem::GetCommand()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return CastChecked<UNoesisICommand>(CreateInterfaceFor(NoesisMenuItem->GetCommand(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisMenuItem::SetCommand(class UNoesisICommand* InCommand)
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	NoesisMenuItem->SetCommand(NsDynamicCast<ICommand*>(InCommand->NoesisInterface.GetPtr()));
}

class UNoesisBaseComponent* UNoesisMenuItem::GetCommandParameter()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisMenuItem->GetCommandParameter(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisMenuItem::SetCommandParameter(class UNoesisBaseComponent* InCommandParameter)
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	NoesisMenuItem->SetCommandParameter(NsDynamicCast<Core::BaseComponent*>(InCommandParameter->NoesisComponent.GetPtr()));
}

class UNoesisUIElement* UNoesisMenuItem::GetCommandTarget()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisMenuItem->GetCommandTarget(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisMenuItem::SetCommandTarget(class UNoesisUIElement* InCommandTarget)
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	NoesisMenuItem->SetCommandTarget(NsDynamicCast<UIElement*>(InCommandTarget->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisMenuItem::GetIcon()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisMenuItem->GetIcon(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisMenuItem::SetIcon(class UNoesisBaseComponent* InIcon)
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	NoesisMenuItem->SetIcon(NsDynamicCast<Core::BaseComponent*>(InIcon->NoesisComponent.GetPtr()));
}

FString UNoesisMenuItem::GetInputGestureText()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return NsStringToFString(NoesisMenuItem->GetInputGestureText());
}

void UNoesisMenuItem::SetInputGestureText(FString InInputGestureText)
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	NoesisMenuItem->SetInputGestureText(StringCast<NsChar>(*InInputGestureText).Get());
}

bool UNoesisMenuItem::GetIsCheckable()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return NoesisMenuItem->GetIsCheckable();
}

void UNoesisMenuItem::SetIsCheckable(bool InIsCheckable)
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	NoesisMenuItem->SetIsCheckable(InIsCheckable);
}

bool UNoesisMenuItem::GetIsChecked()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return NoesisMenuItem->GetIsChecked();
}

void UNoesisMenuItem::SetIsChecked(bool InIsChecked)
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	NoesisMenuItem->SetIsChecked(InIsChecked);
}

bool UNoesisMenuItem::GetIsHighlighted()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return NoesisMenuItem->GetIsHighlighted();
}

bool UNoesisMenuItem::GetIsPressed()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return NoesisMenuItem->GetIsPressed();
}

bool UNoesisMenuItem::GetIsSubmenuOpen()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return NoesisMenuItem->GetIsSubmenuOpen();
}

void UNoesisMenuItem::SetIsSubmenuOpen(bool InIsSubmenuOpen)
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	NoesisMenuItem->SetIsSubmenuOpen(InIsSubmenuOpen);
}

ENoesisMenuItemRole UNoesisMenuItem::GetRole()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return (ENoesisMenuItemRole)NoesisMenuItem->GetRole();
}

bool UNoesisMenuItem::GetStaysOpenOnClick()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	return NoesisMenuItem->GetStaysOpenOnClick();
}

void UNoesisMenuItem::SetStaysOpenOnClick(bool InStaysOpenOnClick)
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);
	NoesisMenuItem->SetStaysOpenOnClick(InStaysOpenOnClick);
}

void UNoesisMenuItem::Checked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Checked.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Checked.Broadcast(Sender, Args);
}

void UNoesisMenuItem::Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Click.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Click.Broadcast(Sender, Args);
}

void UNoesisMenuItem::SubmenuClosed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!SubmenuClosed.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	SubmenuClosed.Broadcast(Sender, Args);
}

void UNoesisMenuItem::SubmenuOpened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!SubmenuOpened.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	SubmenuOpened.Broadcast(Sender, Args);
}

void UNoesisMenuItem::Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unchecked.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Unchecked.Broadcast(Sender, Args);
}

void UNoesisMenuItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);

	Checked_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::Checked_Private);
	NoesisMenuItem->Checked() += Checked_Delegate;
	Click_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::Click_Private);
	NoesisMenuItem->Click() += Click_Delegate;
	SubmenuClosed_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::SubmenuClosed_Private);
	NoesisMenuItem->SubmenuClosed() += SubmenuClosed_Delegate;
	SubmenuOpened_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::SubmenuOpened_Private);
	NoesisMenuItem->SubmenuOpened() += SubmenuOpened_Delegate;
	Unchecked_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::Unchecked_Private);
	NoesisMenuItem->Unchecked() += Unchecked_Delegate;

}

void UNoesisMenuItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem);

	NoesisMenuItem->Checked() -= Checked_Delegate;
	NoesisMenuItem->Click() -= Click_Delegate;
	NoesisMenuItem->SubmenuClosed() -= SubmenuClosed_Delegate;
	NoesisMenuItem->SubmenuOpened() -= SubmenuOpened_Delegate;
	NoesisMenuItem->Unchecked() -= Unchecked_Delegate;

}

