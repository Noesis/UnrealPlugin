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

	CanExecute_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiCommandBinding::CanExecute_Private);
	NoesisCommandBinding->CanExecute() += CanExecute_Delegate;
	Executed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiCommandBinding::Executed_Private);
	NoesisCommandBinding->Executed() += Executed_Delegate;
	PreviewCanExecute_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiCommandBinding::PreviewCanExecute_Private);
	NoesisCommandBinding->PreviewCanExecute() += PreviewCanExecute_Delegate;
	PreviewExecuted_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiCommandBinding::PreviewExecuted_Private);
	NoesisCommandBinding->PreviewExecuted() += PreviewExecuted_Delegate;
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
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiCanExecuteRoutedEventArgs Args(Instance, InArgs);
	CanExecute.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

	void UNoesisGuiCommandBinding::Executed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiExecutedRoutedEventArgs Args(Instance, InArgs);
	Executed.Broadcast(Sender, Args);
}

	void UNoesisGuiCommandBinding::PreviewCanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiCanExecuteRoutedEventArgs Args(Instance, InArgs);
	PreviewCanExecute.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

	void UNoesisGuiCommandBinding::PreviewExecuted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiExecutedRoutedEventArgs Args(Instance, InArgs);
	PreviewExecuted.Broadcast(Sender, Args);
}

	void UNoesisGuiCommandBinding::BeginDestroy()
{
	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	if (!NoesisCommandBinding)
		return Super::BeginDestroy();

	NoesisCommandBinding->CanExecute() -= CanExecute_Delegate;
	NoesisCommandBinding->Executed() -= Executed_Delegate;
	NoesisCommandBinding->PreviewCanExecute() -= PreviewCanExecute_Delegate;
	NoesisCommandBinding->PreviewExecuted() -= PreviewExecuted_Delegate;

	Super::BeginDestroy();
}

