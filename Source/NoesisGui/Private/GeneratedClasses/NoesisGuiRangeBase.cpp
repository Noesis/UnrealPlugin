////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRangeBase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRangeBase::UNoesisGuiRangeBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRangeBase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(InNoesisComponent);
	check(NoesisRangeBase);
}

void UNoesisGuiRangeBase::ValueChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedPropertyChangedEventArgs<NsFloat32>& InArgs)
{
	if (!ValueChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiFloatPropertyChangedEventArgs Args(Instance, InArgs);
	ValueChanged.Broadcast(Sender, Args);
}

void UNoesisGuiRangeBase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase)

	ValueChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiRangeBase::ValueChanged_Private);
	if (ValueChanged.IsBound())
	{
		NoesisRangeBase->ValueChanged() += ValueChanged_Delegate;
	}

}

void UNoesisGuiRangeBase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	check(NoesisRangeBase)

	if (ValueChanged.IsBound())
	{
		NoesisRangeBase->ValueChanged() -= ValueChanged_Delegate;
	}

}

