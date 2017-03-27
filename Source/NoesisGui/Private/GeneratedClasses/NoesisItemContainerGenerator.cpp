////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisItemContainerGenerator.h"

using namespace Noesis;
using namespace Gui;

UNoesisItemContainerGenerator::UNoesisItemContainerGenerator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ItemContainerGenerator::StaticGetClassType();
}

void UNoesisItemContainerGenerator::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(InNoesisComponent);
	check(NoesisItemContainerGenerator);
}

ENoesisGeneratorStatus UNoesisItemContainerGenerator::GetStatus()
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	return (ENoesisGeneratorStatus)NoesisItemContainerGenerator->GetStatus();
}

class UNoesisDependencyObject* UNoesisItemContainerGenerator::ContainerFromIndex(int32 InIndex)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	NsInt NoesisInIndex = InIndex;
	return CastChecked<UNoesisDependencyObject>(CreateClassFor(NoesisItemContainerGenerator->ContainerFromIndex(NoesisInIndex), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisDependencyObject* UNoesisItemContainerGenerator::ContainerFromItem(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return CastChecked<UNoesisDependencyObject>(CreateClassFor(NoesisItemContainerGenerator->ContainerFromItem(NoesisInItem), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisDependencyObject* UNoesisItemContainerGenerator::GenerateNext()
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	return CastChecked<UNoesisDependencyObject>(CreateClassFor(NoesisItemContainerGenerator->GenerateNext(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisDependencyObject* UNoesisItemContainerGenerator::GenerateNext_(bool& InIsNewlyRealized)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	NsBool NoesisInIsNewlyRealized = InIsNewlyRealized;
	return CastChecked<UNoesisDependencyObject>(CreateClassFor(NoesisItemContainerGenerator->GenerateNext(NoesisInIsNewlyRealized), nullptr), ECastCheckedType::NullAllowed);
}

FNoesisGeneratorPosition UNoesisItemContainerGenerator::GeneratorPositionFromIndex(int32 InItemIndex)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	NsInt NoesisInItemIndex = InItemIndex;
	return FNoesisGeneratorPosition(NoesisItemContainerGenerator->GeneratorPositionFromIndex(NoesisInItemIndex));
}

class UNoesisItemContainerGenerator* UNoesisItemContainerGenerator::GetItemContainerGeneratorForPanel(class UNoesisPanel* InPanel)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	Panel* NoesisInPanel = NsDynamicCast<Panel*>(InPanel->NoesisComponent.GetPtr());
	return CastChecked<UNoesisItemContainerGenerator>(CreateClassFor(NoesisItemContainerGenerator->GetItemContainerGeneratorForPanel(NoesisInPanel), nullptr), ECastCheckedType::NullAllowed);
}

int32 UNoesisItemContainerGenerator::IndexFromContainer(class UNoesisDependencyObject* InContainer)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return NoesisItemContainerGenerator->IndexFromContainer(NoesisInContainer);
}

int32 UNoesisItemContainerGenerator::IndexFromGeneratorPosition(FNoesisGeneratorPosition InPosition)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	return NoesisItemContainerGenerator->IndexFromGeneratorPosition(NoesisInPosition);
}

class UNoesisBaseComponent* UNoesisItemContainerGenerator::ItemFromContainer(class UNoesisDependencyObject* InContainer)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisItemContainerGenerator->ItemFromContainer(NoesisInContainer), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisItemContainerGenerator::PrepareItemContainer(class UNoesisDependencyObject* InContainer)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return NoesisItemContainerGenerator->PrepareItemContainer(NoesisInContainer);
}

void UNoesisItemContainerGenerator::Remove(FNoesisGeneratorPosition InPosition, int32 InCount)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	NsSize NoesisInCount = (NsSize)InCount;
	return NoesisItemContainerGenerator->Remove(NoesisInPosition, NoesisInCount);
}

void UNoesisItemContainerGenerator::RemoveAll()
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	return NoesisItemContainerGenerator->RemoveAll();
}

void UNoesisItemContainerGenerator::Stop()
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	return NoesisItemContainerGenerator->Stop();
}

void UNoesisItemContainerGenerator::ItemsChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ItemsChangedEventArgs& InArgs)
{
	if (!ItemsChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisItemsChangedEventArgs Args(InArgs);
	ItemsChanged.Broadcast(Sender, Args);
}

void UNoesisItemContainerGenerator::StatusChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)
{
	if (!StatusChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisEventArgs Args(InArgs);
	StatusChanged.Broadcast(Sender, Args);
}

void UNoesisItemContainerGenerator::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);

	ItemsChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisItemContainerGenerator::ItemsChanged_Private);
	NoesisItemContainerGenerator->ItemsChanged() += ItemsChanged_Delegate;
	StatusChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisItemContainerGenerator::StatusChanged_Private);
	NoesisItemContainerGenerator->StatusChanged() += StatusChanged_Delegate;

}

void UNoesisItemContainerGenerator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);

	NoesisItemContainerGenerator->ItemsChanged() -= ItemsChanged_Delegate;
	NoesisItemContainerGenerator->StatusChanged() -= StatusChanged_Delegate;

}

