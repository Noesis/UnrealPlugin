////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisSelector.h"

using namespace Noesis;
using namespace Gui;

UNoesisSelector::UNoesisSelector(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisSelector::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(InNoesisComponent);
	check(NoesisSelector);
}

int32 UNoesisSelector::GetSelectedIndex()
{
	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector);
	return NoesisSelector->GetSelectedIndex();
}

void UNoesisSelector::SetSelectedIndex(int32 InSelectedIndex)
{
	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector);
	NoesisSelector->SetSelectedIndex(InSelectedIndex);
}

class UNoesisBaseComponent* UNoesisSelector::GetSelectedItem()
{
	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisSelector->GetSelectedItem()));
}

void UNoesisSelector::SetSelectedItem(class UNoesisBaseComponent* InSelectedItem)
{
	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector);
	NoesisSelector->SetSelectedItem(NsDynamicCast<Core::BaseComponent*>(InSelectedItem->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisSelector::GetSelectedValue()
{
	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisSelector->GetSelectedValue()));
}

void UNoesisSelector::SetSelectedValue(class UNoesisBaseComponent* InSelectedValue)
{
	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector);
	NoesisSelector->SetSelectedValue(NsDynamicCast<Core::BaseComponent*>(InSelectedValue->NoesisComponent.GetPtr()));
}

FString UNoesisSelector::GetSelectedValuePath()
{
	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector);
	return NsStringToFString(NoesisSelector->GetSelectedValuePath());
}

void UNoesisSelector::SetSelectedValuePath(FString InSelectedValuePath)
{
	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector);
	NoesisSelector->SetSelectedValuePath(StringCast<NsChar>(*InSelectedValuePath).Get());
}

void UNoesisSelector::SelectionChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::SelectionChangedEventArgs& InArgs)
{
	if (!SelectionChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisSelectionChangedEventArgs Args(Instance, InArgs);
	SelectionChanged.Broadcast(Sender, Args);
}

void UNoesisSelector::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector)

	SelectionChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisSelector::SelectionChanged_Private);
	if (SelectionChanged.IsBound())
	{
		NoesisSelector->SelectionChanged() += SelectionChanged_Delegate;
	}

}

void UNoesisSelector::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	check(NoesisSelector)

	if (SelectionChanged.IsBound())
	{
		NoesisSelector->SelectionChanged() -= SelectionChanged_Delegate;
	}

}

