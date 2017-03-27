////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisRangeBase.h"

using namespace Noesis;
using namespace Gui;

UNoesisRangeBase::UNoesisRangeBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::RangeBase::StaticGetClassType();
}

void UNoesisRangeBase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(InNoesisComponent);
	check(NoesisRangeBase);
}

float UNoesisRangeBase::GetLargeChange()
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	return (float)NoesisRangeBase->GetLargeChange();
}

void UNoesisRangeBase::SetLargeChange(float InLargeChange)
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	NoesisRangeBase->SetLargeChange(InLargeChange);
}

float UNoesisRangeBase::GetMaximum()
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	return (float)NoesisRangeBase->GetMaximum();
}

void UNoesisRangeBase::SetMaximum(float InMaximum)
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	NoesisRangeBase->SetMaximum(InMaximum);
}

float UNoesisRangeBase::GetMinimum()
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	return (float)NoesisRangeBase->GetMinimum();
}

void UNoesisRangeBase::SetMinimum(float InMinimum)
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	NoesisRangeBase->SetMinimum(InMinimum);
}

float UNoesisRangeBase::GetSmallChange()
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	return (float)NoesisRangeBase->GetSmallChange();
}

void UNoesisRangeBase::SetSmallChange(float InSmallChange)
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	NoesisRangeBase->SetSmallChange(InSmallChange);
}

float UNoesisRangeBase::GetValue()
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	return (float)NoesisRangeBase->GetValue();
}

void UNoesisRangeBase::SetValue(float InValue)
{
	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);
	NoesisRangeBase->SetValue(InValue);
}

void UNoesisRangeBase::ValueChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedPropertyChangedEventArgs<NsFloat32>& InArgs)
{
	if (!ValueChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisFloatPropertyChangedEventArgs Args(InArgs);
	ValueChanged.Broadcast(Sender, Args);
}

void UNoesisRangeBase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);

	ValueChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisRangeBase::ValueChanged_Private);
	NoesisRangeBase->ValueChanged() += ValueChanged_Delegate;

}

void UNoesisRangeBase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase);

	NoesisRangeBase->ValueChanged() -= ValueChanged_Delegate;

}

