////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisItemContainerGenerator.h"

using namespace Noesis;
using namespace Gui;

UNoesisItemContainerGenerator::UNoesisItemContainerGenerator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
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
	return CastChecked<UNoesisDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->ContainerFromIndex(NoesisInIndex)));
}

class UNoesisDependencyObject* UNoesisItemContainerGenerator::ContainerFromItem(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return CastChecked<UNoesisDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->ContainerFromItem(NoesisInItem)));
}

class UNoesisDependencyObject* UNoesisItemContainerGenerator::GenerateNext()
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	return CastChecked<UNoesisDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->GenerateNext()));
}

class UNoesisDependencyObject* UNoesisItemContainerGenerator::GenerateNext_(bool& InIsNewlyRealized)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	NsBool NoesisInIsNewlyRealized = InIsNewlyRealized;
	return CastChecked<UNoesisDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->GenerateNext(NoesisInIsNewlyRealized)));
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
	return CastChecked<UNoesisItemContainerGenerator>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->GetItemContainerGeneratorForPanel(NoesisInPanel)));
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
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->ItemFromContainer(NoesisInContainer)));
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

void UNoesisItemContainerGenerator::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator)


}

void UNoesisItemContainerGenerator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator)


}

