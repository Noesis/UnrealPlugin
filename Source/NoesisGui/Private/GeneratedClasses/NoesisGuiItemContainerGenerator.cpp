////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiItemContainerGenerator.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiItemContainerGenerator::UNoesisGuiItemContainerGenerator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiItemContainerGenerator::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(InNoesisComponent);
	check(NoesisItemContainerGenerator);
}

ENoesisGuiGeneratorStatus UNoesisGuiItemContainerGenerator::GetStatus()
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	return (ENoesisGuiGeneratorStatus)NoesisItemContainerGenerator->GetStatus();
}

class UNoesisGuiDependencyObject* UNoesisGuiItemContainerGenerator::ContainerFromIndex(int32 InIndex)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	NsInt NoesisInIndex = InIndex;
	return CastChecked<UNoesisGuiDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->ContainerFromIndex(NoesisInIndex)));
}

class UNoesisGuiDependencyObject* UNoesisGuiItemContainerGenerator::ContainerFromItem(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->ContainerFromItem(NoesisInItem)));
}

class UNoesisGuiDependencyObject* UNoesisGuiItemContainerGenerator::GenerateNext()
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	return CastChecked<UNoesisGuiDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->GenerateNext()));
}

class UNoesisGuiDependencyObject* UNoesisGuiItemContainerGenerator::GenerateNext_(bool& InIsNewlyRealized)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	NsBool NoesisInIsNewlyRealized = InIsNewlyRealized;
	return CastChecked<UNoesisGuiDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->GenerateNext(NoesisInIsNewlyRealized)));
}

FNoesisGuiGeneratorPosition UNoesisGuiItemContainerGenerator::GeneratorPositionFromIndex(int32 InItemIndex)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	NsInt NoesisInItemIndex = InItemIndex;
	return FNoesisGuiGeneratorPosition(NoesisItemContainerGenerator->GeneratorPositionFromIndex(NoesisInItemIndex));
}

class UNoesisGuiItemContainerGenerator* UNoesisGuiItemContainerGenerator::GetItemContainerGeneratorForPanel(class UNoesisGuiPanel* InPanel)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	Panel* NoesisInPanel = NsDynamicCast<Panel*>(InPanel->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiItemContainerGenerator>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->GetItemContainerGeneratorForPanel(NoesisInPanel)));
}

int32 UNoesisGuiItemContainerGenerator::IndexFromContainer(class UNoesisGuiDependencyObject* InContainer)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return NoesisItemContainerGenerator->IndexFromContainer(NoesisInContainer);
}

int32 UNoesisGuiItemContainerGenerator::IndexFromGeneratorPosition(FNoesisGuiGeneratorPosition InPosition)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	return NoesisItemContainerGenerator->IndexFromGeneratorPosition(NoesisInPosition);
}

class UNoesisGuiBaseComponent* UNoesisGuiItemContainerGenerator::ItemFromContainer(class UNoesisGuiDependencyObject* InContainer)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisItemContainerGenerator->ItemFromContainer(NoesisInContainer)));
}

void UNoesisGuiItemContainerGenerator::PrepareItemContainer(class UNoesisGuiDependencyObject* InContainer)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return NoesisItemContainerGenerator->PrepareItemContainer(NoesisInContainer);
}

void UNoesisGuiItemContainerGenerator::Remove(FNoesisGuiGeneratorPosition InPosition, int32 InCount)
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	NsSize NoesisInCount = InCount;
	return NoesisItemContainerGenerator->Remove(NoesisInPosition, NoesisInCount);
}

void UNoesisGuiItemContainerGenerator::RemoveAll()
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	return NoesisItemContainerGenerator->RemoveAll();
}

void UNoesisGuiItemContainerGenerator::Stop()
{
	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator);
	return NoesisItemContainerGenerator->Stop();
}

void UNoesisGuiItemContainerGenerator::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator)


}

void UNoesisGuiItemContainerGenerator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	check(NoesisItemContainerGenerator)


}

