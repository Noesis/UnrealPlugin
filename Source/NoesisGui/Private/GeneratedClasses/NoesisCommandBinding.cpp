////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisCommandBinding.h"

using namespace Noesis;
using namespace Gui;

UNoesisCommandBinding::UNoesisCommandBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisCommandBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(InNoesisComponent);
	check(NoesisCommandBinding);
}

class UNoesisICommand* UNoesisCommandBinding::GetCommand()
{
	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding);
	return CastChecked<UNoesisICommand>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisCommandBinding->GetCommand()));
}

void UNoesisCommandBinding::SetCommand(class UNoesisICommand* InCommand)
{
	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding);
	NoesisCommandBinding->SetCommand(NsDynamicCast<ICommand*>(InCommand->NoesisInterface.GetPtr()));
}

void UNoesisCommandBinding::CanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	if (!CanExecute.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisCanExecuteRoutedEventArgs Args(Instance, InArgs);
	CanExecute.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisCommandBinding::Executed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)
{
	if (!Executed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisExecutedRoutedEventArgs Args(Instance, InArgs);
	Executed.Broadcast(Sender, Args);
}

void UNoesisCommandBinding::PreviewCanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	if (!PreviewCanExecute.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisCanExecuteRoutedEventArgs Args(Instance, InArgs);
	PreviewCanExecute.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisCommandBinding::PreviewExecuted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)
{
	if (!PreviewExecuted.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisExecutedRoutedEventArgs Args(Instance, InArgs);
	PreviewExecuted.Broadcast(Sender, Args);
}

void UNoesisCommandBinding::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding)

	CanExecute_Delegate = Noesis::MakeDelegate(this, &UNoesisCommandBinding::CanExecute_Private);
	if (CanExecute.IsBound())
	{
		NoesisCommandBinding->CanExecute() += CanExecute_Delegate;
	}
	Executed_Delegate = Noesis::MakeDelegate(this, &UNoesisCommandBinding::Executed_Private);
	if (Executed.IsBound())
	{
		NoesisCommandBinding->Executed() += Executed_Delegate;
	}
	PreviewCanExecute_Delegate = Noesis::MakeDelegate(this, &UNoesisCommandBinding::PreviewCanExecute_Private);
	if (PreviewCanExecute.IsBound())
	{
		NoesisCommandBinding->PreviewCanExecute() += PreviewCanExecute_Delegate;
	}
	PreviewExecuted_Delegate = Noesis::MakeDelegate(this, &UNoesisCommandBinding::PreviewExecuted_Private);
	if (PreviewExecuted.IsBound())
	{
		NoesisCommandBinding->PreviewExecuted() += PreviewExecuted_Delegate;
	}

}

void UNoesisCommandBinding::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding)

	if (CanExecute.IsBound())
	{
		NoesisCommandBinding->CanExecute() -= CanExecute_Delegate;
	}
	if (Executed.IsBound())
	{
		NoesisCommandBinding->Executed() -= Executed_Delegate;
	}
	if (PreviewCanExecute.IsBound())
	{
		NoesisCommandBinding->PreviewCanExecute() -= PreviewCanExecute_Delegate;
	}
	if (PreviewExecuted.IsBound())
	{
		NoesisCommandBinding->PreviewExecuted() -= PreviewExecuted_Delegate;
	}

}

