////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisPasswordBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisPasswordBox::UNoesisPasswordBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisPasswordBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(InNoesisComponent);
	check(NoesisPasswordBox);
}

class UNoesisBrush* UNoesisPasswordBox::GetCaretBrush()
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisPasswordBox->GetCaretBrush()));
}

void UNoesisPasswordBox::SetCaretBrush(class UNoesisBrush* InCaretBrush)
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	NoesisPasswordBox->SetCaretBrush(NsDynamicCast<Brush*>(InCaretBrush->NoesisComponent.GetPtr()));
}

int32 UNoesisPasswordBox::GetMaxLength()
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	return NoesisPasswordBox->GetMaxLength();
}

void UNoesisPasswordBox::SetMaxLength(int32 InMaxLength)
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	NoesisPasswordBox->SetMaxLength(InMaxLength);
}

FString UNoesisPasswordBox::GetPassword()
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	return NsStringToFString(NoesisPasswordBox->GetPassword());
}

void UNoesisPasswordBox::SetPassword(FString InPassword)
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	NoesisPasswordBox->SetPassword(StringCast<NsChar>(*InPassword).Get());
}

int32 UNoesisPasswordBox::GetPasswordChar()
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	return (int32)CharCast<TCHAR>(NoesisPasswordBox->GetPasswordChar());
}

void UNoesisPasswordBox::SetPasswordChar(int32 InPasswordChar)
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	NoesisPasswordBox->SetPasswordChar(CharCast<NsChar>((NsChar)InPasswordChar));
}

class UNoesisBrush* UNoesisPasswordBox::GetSelectionBrush()
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisPasswordBox->GetSelectionBrush()));
}

void UNoesisPasswordBox::SetSelectionBrush(class UNoesisBrush* InSelectionBrush)
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	NoesisPasswordBox->SetSelectionBrush(NsDynamicCast<Brush*>(InSelectionBrush->NoesisComponent.GetPtr()));
}

float UNoesisPasswordBox::GetSelectionOpacity()
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	return (float)NoesisPasswordBox->GetSelectionOpacity();
}

void UNoesisPasswordBox::SetSelectionOpacity(float InSelectionOpacity)
{
	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox);
	NoesisPasswordBox->SetSelectionOpacity(InSelectionOpacity);
}

void UNoesisPasswordBox::PasswordChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!PasswordChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	PasswordChanged.Broadcast(Sender, Args);
}

void UNoesisPasswordBox::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox)

	PasswordChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisPasswordBox::PasswordChanged_Private);
	if (PasswordChanged.IsBound())
	{
		NoesisPasswordBox->PasswordChanged() += PasswordChanged_Delegate;
	}

}

void UNoesisPasswordBox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::PasswordBox* NoesisPasswordBox = NsDynamicCast<Noesis::Gui::PasswordBox*>(NoesisComponent.GetPtr());
	check(NoesisPasswordBox)

	if (PasswordChanged.IsBound())
	{
		NoesisPasswordBox->PasswordChanged() -= PasswordChanged_Delegate;
	}

}

