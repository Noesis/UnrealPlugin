////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisControl::UNoesisControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Control::StaticGetClassType();
}

void UNoesisControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(InNoesisComponent);
	check(NoesisControl);
}

class UNoesisBrush* UNoesisControl::GetBackground()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisControl->GetBackground(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisControl::SetBackground(class UNoesisBrush* InBackground)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetBackground(NsDynamicCast<Brush*>(InBackground->NoesisComponent.GetPtr()));
}

class UNoesisBrush* UNoesisControl::GetBorderBrush()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisControl->GetBorderBrush(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisControl::SetBorderBrush(class UNoesisBrush* InBorderBrush)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetBorderBrush(NsDynamicCast<Brush*>(InBorderBrush->NoesisComponent.GetPtr()));
}

FNoesisDrawingThickness UNoesisControl::GetBorderThickness()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return FNoesisDrawingThickness(NoesisControl->GetBorderThickness());
}

void UNoesisControl::SetBorderThickness(FNoesisDrawingThickness InBorderThickness)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetBorderThickness(InBorderThickness.ToNoesis());
}

class UNoesisFontFamily* UNoesisControl::GetFontFamily()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return CastChecked<UNoesisFontFamily>(CreateClassFor(NoesisControl->GetFontFamily(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisControl::SetFontFamily(class UNoesisFontFamily* InFontFamily)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetFontFamily(NsDynamicCast<FontFamily*>(InFontFamily->NoesisComponent.GetPtr()));
}

float UNoesisControl::GetFontSize()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return (float)NoesisControl->GetFontSize();
}

void UNoesisControl::SetFontSize(float InFontSize)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetFontSize(InFontSize);
}

ENoesisFontStretch UNoesisControl::GetFontStretch()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return (ENoesisFontStretch)NoesisControl->GetFontStretch();
}

void UNoesisControl::SetFontStretch(ENoesisFontStretch InFontStretch)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetFontStretch((Noesis::Gui::FontStretch)InFontStretch);
}

ENoesisFontStyle UNoesisControl::GetFontStyle()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return (ENoesisFontStyle)NoesisControl->GetFontStyle();
}

void UNoesisControl::SetFontStyle(ENoesisFontStyle InFontStyle)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetFontStyle((Noesis::Gui::FontStyle)InFontStyle);
}

ENoesisFontWeight UNoesisControl::GetFontWeight()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return (ENoesisFontWeight)(NoesisControl->GetFontWeight() / 10);
}

void UNoesisControl::SetFontWeight(ENoesisFontWeight InFontWeight)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetFontWeight((Noesis::Gui::FontWeight)(((int32)InFontWeight) * 10));
}

class UNoesisBrush* UNoesisControl::GetForeground()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisControl->GetForeground(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisControl::SetForeground(class UNoesisBrush* InForeground)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetForeground(NsDynamicCast<Brush*>(InForeground->NoesisComponent.GetPtr()));
}

ENoesisHorizontalAlignment UNoesisControl::GetHorizontalContentAlignment()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return (ENoesisHorizontalAlignment)NoesisControl->GetHorizontalContentAlignment();
}

void UNoesisControl::SetHorizontalContentAlignment(ENoesisHorizontalAlignment InHorizontalContentAlignment)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetHorizontalContentAlignment((Noesis::Gui::HorizontalAlignment)InHorizontalContentAlignment);
}

bool UNoesisControl::GetIsTabStop()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return NoesisControl->GetIsTabStop();
}

void UNoesisControl::SetIsTabStop(bool InIsTabStop)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetIsTabStop(InIsTabStop);
}

FNoesisDrawingThickness UNoesisControl::GetPadding()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return FNoesisDrawingThickness(NoesisControl->GetPadding());
}

void UNoesisControl::SetPadding(FNoesisDrawingThickness InPadding)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetPadding(InPadding.ToNoesis());
}

int32 UNoesisControl::GetTabIndex()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return NoesisControl->GetTabIndex();
}

void UNoesisControl::SetTabIndex(int32 InTabIndex)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetTabIndex(InTabIndex);
}

class UNoesisControlTemplate* UNoesisControl::GetTemplate()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return CastChecked<UNoesisControlTemplate>(CreateClassFor(NoesisControl->GetTemplate(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisControl::SetTemplate(class UNoesisControlTemplate* InTemplate)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetTemplate(NsDynamicCast<ControlTemplate*>(InTemplate->NoesisComponent.GetPtr()));
}

ENoesisVerticalAlignment UNoesisControl::GetVerticalContentAlignment()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	return (ENoesisVerticalAlignment)NoesisControl->GetVerticalContentAlignment();
}

void UNoesisControl::SetVerticalContentAlignment(ENoesisVerticalAlignment InVerticalContentAlignment)
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);
	NoesisControl->SetVerticalContentAlignment((Noesis::Gui::VerticalAlignment)InVerticalContentAlignment);
}

void UNoesisControl::MouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseDoubleClick.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	MouseDoubleClick.Broadcast(Sender, Args);
}

void UNoesisControl::PreviewMouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseDoubleClick.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	PreviewMouseDoubleClick.Broadcast(Sender, Args);
}

void UNoesisControl::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);

	MouseDoubleClick_Delegate = Noesis::MakeDelegate(this, &UNoesisControl::MouseDoubleClick_Private);
	NoesisControl->MouseDoubleClick() += MouseDoubleClick_Delegate;
	PreviewMouseDoubleClick_Delegate = Noesis::MakeDelegate(this, &UNoesisControl::PreviewMouseDoubleClick_Private);
	NoesisControl->PreviewMouseDoubleClick() += PreviewMouseDoubleClick_Delegate;

}

void UNoesisControl::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl);

	NoesisControl->MouseDoubleClick() -= MouseDoubleClick_Delegate;
	NoesisControl->PreviewMouseDoubleClick() -= PreviewMouseDoubleClick_Delegate;

}

