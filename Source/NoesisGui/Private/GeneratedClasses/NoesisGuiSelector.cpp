////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSelector.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSelector::UNoesisGuiSelector(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSelector::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(InNoesisComponent);
	check(NoesisSelector);

	SelectionChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiSelector::SelectionChanged_Private);
	NoesisSelector->SelectionChanged() += SelectionChanged_Delegate;
}

	void UNoesisGuiSelector::SelectionChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::SelectionChangedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiSelectionChangedEventArgs Args(Instance, InArgs);
	SelectionChanged.Broadcast(Sender, Args);
}

	void UNoesisGuiSelector::BeginDestroy()
{
	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	if (!NoesisSelector)
		return Super::BeginDestroy();

	NoesisSelector->SelectionChanged() -= SelectionChanged_Delegate;

	Super::BeginDestroy();
}

