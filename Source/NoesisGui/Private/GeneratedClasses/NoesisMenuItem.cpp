////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisMenuItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisMenuItem::UNoesisMenuItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
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
	return CastChecked<UNoesisICommand>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisMenuItem->GetCommand()));
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
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisMenuItem->GetCommandParameter()));
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
	return CastChecked<UNoesisUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisMenuItem->GetCommandTarget()));
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
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisMenuItem->GetIcon()));
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
	if (!Checked.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Checked.Broadcast(Sender, Args);
}

void UNoesisMenuItem::Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Click.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Click.Broadcast(Sender, Args);
}

void UNoesisMenuItem::SubmenuClosed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!SubmenuClosed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	SubmenuClosed.Broadcast(Sender, Args);
}

void UNoesisMenuItem::SubmenuOpened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!SubmenuOpened.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	SubmenuOpened.Broadcast(Sender, Args);
}

void UNoesisMenuItem::Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unchecked.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Unchecked.Broadcast(Sender, Args);
}

void UNoesisMenuItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem)

	Checked_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::Checked_Private);
	if (Checked.IsBound())
	{
		NoesisMenuItem->Checked() += Checked_Delegate;
	}
	Click_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::Click_Private);
	if (Click.IsBound())
	{
		NoesisMenuItem->Click() += Click_Delegate;
	}
	SubmenuClosed_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::SubmenuClosed_Private);
	if (SubmenuClosed.IsBound())
	{
		NoesisMenuItem->SubmenuClosed() += SubmenuClosed_Delegate;
	}
	SubmenuOpened_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::SubmenuOpened_Private);
	if (SubmenuOpened.IsBound())
	{
		NoesisMenuItem->SubmenuOpened() += SubmenuOpened_Delegate;
	}
	Unchecked_Delegate = Noesis::MakeDelegate(this, &UNoesisMenuItem::Unchecked_Private);
	if (Unchecked.IsBound())
	{
		NoesisMenuItem->Unchecked() += Unchecked_Delegate;
	}

}

void UNoesisMenuItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem)

	if (Checked.IsBound())
	{
		NoesisMenuItem->Checked() -= Checked_Delegate;
	}
	if (Click.IsBound())
	{
		NoesisMenuItem->Click() -= Click_Delegate;
	}
	if (SubmenuClosed.IsBound())
	{
		NoesisMenuItem->SubmenuClosed() -= SubmenuClosed_Delegate;
	}
	if (SubmenuOpened.IsBound())
	{
		NoesisMenuItem->SubmenuOpened() -= SubmenuOpened_Delegate;
	}
	if (Unchecked.IsBound())
	{
		NoesisMenuItem->Unchecked() -= Unchecked_Delegate;
	}

}

