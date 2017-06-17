////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisCommandBinding.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisCommandBinding::UNoesisCommandBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::CommandBinding::StaticGetClassType();
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
	return CastChecked<UNoesisICommand>(CreateInterfaceFor(NoesisCommandBinding->GetCommand(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisCommandBinding::SetCommand(class UNoesisICommand* InCommand)
{
	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding);
	NoesisCommandBinding->SetCommand(NsDynamicCast<ICommand*>(InCommand->NoesisInterface.GetPtr()));
}

void UNoesisCommandBinding::CanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	if (!CanExecute.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisCanExecuteRoutedEventArgs Args(InArgs);
	CanExecute.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisCommandBinding::Executed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)
{
	if (!Executed.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisExecutedRoutedEventArgs Args(InArgs);
	Executed.Broadcast(Sender, Args);
}

void UNoesisCommandBinding::PreviewCanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)
{
	if (!PreviewCanExecute.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisCanExecuteRoutedEventArgs Args(InArgs);
	PreviewCanExecute.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisCommandBinding::PreviewExecuted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)
{
	if (!PreviewExecuted.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisExecutedRoutedEventArgs Args(InArgs);
	PreviewExecuted.Broadcast(Sender, Args);
}

void UNoesisCommandBinding::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding);

	CanExecute_Delegate = Noesis::MakeDelegate(this, &UNoesisCommandBinding::CanExecute_Private);
	NoesisCommandBinding->CanExecute() += CanExecute_Delegate;
	Executed_Delegate = Noesis::MakeDelegate(this, &UNoesisCommandBinding::Executed_Private);
	NoesisCommandBinding->Executed() += Executed_Delegate;
	PreviewCanExecute_Delegate = Noesis::MakeDelegate(this, &UNoesisCommandBinding::PreviewCanExecute_Private);
	NoesisCommandBinding->PreviewCanExecute() += PreviewCanExecute_Delegate;
	PreviewExecuted_Delegate = Noesis::MakeDelegate(this, &UNoesisCommandBinding::PreviewExecuted_Private);
	NoesisCommandBinding->PreviewExecuted() += PreviewExecuted_Delegate;

}

void UNoesisCommandBinding::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	check(NoesisCommandBinding);

	NoesisCommandBinding->CanExecute() -= CanExecute_Delegate;
	NoesisCommandBinding->Executed() -= Executed_Delegate;
	NoesisCommandBinding->PreviewCanExecute() -= PreviewCanExecute_Delegate;
	NoesisCommandBinding->PreviewExecuted() -= PreviewExecuted_Delegate;

}

