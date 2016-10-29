////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCommandBinding.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCommandBinding::UNoesisGuiCommandBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCommandBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(InNoesisComponent);
	check(NoesisCommandBinding);
}

UNoesisGuiICommand* UNoesisGuiCommandBinding::GetCommand()
{
	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding);
	return CastChecked<UNoesisGuiICommand>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisCommandBinding->GetCommand()));
}

void UNoesisGuiCommandBinding::SetCommand(UNoesisGuiICommand* InCommand)
{
	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding);
	NoesisCommandBinding->SetCommand(NsDynamicCast<ICommand*>(InCommand->NoesisInterface.GetPtr()));
}

void UNoesisGuiCommandBinding::CanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	if (!CanExecute.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiCanExecuteRoutedEventArgs Args(Instance, InArgs);
	CanExecute.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisGuiCommandBinding::Executed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)
{
	if (!Executed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiExecutedRoutedEventArgs Args(Instance, InArgs);
	Executed.Broadcast(Sender, Args);
}

void UNoesisGuiCommandBinding::PreviewCanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	if (!PreviewCanExecute.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiCanExecuteRoutedEventArgs Args(Instance, InArgs);
	PreviewCanExecute.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisGuiCommandBinding::PreviewExecuted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)
{
	if (!PreviewExecuted.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiExecutedRoutedEventArgs Args(Instance, InArgs);
	PreviewExecuted.Broadcast(Sender, Args);
}

void UNoesisGuiCommandBinding::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding)

	CanExecute_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiCommandBinding::CanExecute_Private);
	if (CanExecute.IsBound())
	{
		NoesisCommandBinding->CanExecute() += CanExecute_Delegate;
	}
	Executed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiCommandBinding::Executed_Private);
	if (Executed.IsBound())
	{
		NoesisCommandBinding->Executed() += Executed_Delegate;
	}
	PreviewCanExecute_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiCommandBinding::PreviewCanExecute_Private);
	if (PreviewCanExecute.IsBound())
	{
		NoesisCommandBinding->PreviewCanExecute() += PreviewCanExecute_Delegate;
	}
	PreviewExecuted_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiCommandBinding::PreviewExecuted_Private);
	if (PreviewExecuted.IsBound())
	{
		NoesisCommandBinding->PreviewExecuted() += PreviewExecuted_Delegate;
	}

}

void UNoesisGuiCommandBinding::UnbindEvents()
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

