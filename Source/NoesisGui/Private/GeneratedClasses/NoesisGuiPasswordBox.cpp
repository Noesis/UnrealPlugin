////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPasswordBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPasswordBox::UNoesisGuiPasswordBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPasswordBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(InNoesisComponent);
	check(NoesisPasswordBox);

	NoesisPasswordBox->PasswordChanged() += Noesis::MakeDelegate(this, &UNoesisGuiPasswordBox::PasswordChanged_Private);
}

FString UNoesisGuiPasswordBox::GetPassword()
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	return NsStringToFString(NoesisPasswordBox->GetPassword());
}

void UNoesisGuiPasswordBox::SetPassword(FString InPassword)
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	NoesisPasswordBox->SetPassword(StringCast<NsChar>(*InPassword).Get());
}

	void UNoesisGuiPasswordBox::PasswordChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	PasswordChanged.Broadcast(Sender, Args);
}

	void UNoesisGuiPasswordBox::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	if (!NoesisPasswordBox)
		return;

	NoesisPasswordBox->PasswordChanged() -= Noesis::MakeDelegate(this, &UNoesisGuiPasswordBox::PasswordChanged_Private);
}

