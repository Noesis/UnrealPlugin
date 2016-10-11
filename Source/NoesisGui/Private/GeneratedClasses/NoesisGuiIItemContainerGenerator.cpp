////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIItemContainerGenerator.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIItemContainerGenerator::UNoesisGuiIItemContainerGenerator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIItemContainerGenerator::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(InNoesisInterface);
	check(NoesisIItemContainerGenerator);

}

class UNoesisGuiDependencyObject* UNoesisGuiIItemContainerGenerator::GenerateNext()
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	return CastChecked<UNoesisGuiDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisIItemContainerGenerator->GenerateNext()));
}

class UNoesisGuiDependencyObject* UNoesisGuiIItemContainerGenerator::GenerateNext_(bool& InIsNewlyRealized)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	NsBool NoesisInIsNewlyRealized = InIsNewlyRealized;
	return CastChecked<UNoesisGuiDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisIItemContainerGenerator->GenerateNext(NoesisInIsNewlyRealized)));
}

FNoesisGuiGeneratorPosition UNoesisGuiIItemContainerGenerator::GeneratorPositionFromIndex(int32 InItemIndex)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	NsInt NoesisInItemIndex = InItemIndex;
	return FNoesisGuiGeneratorPosition(NoesisIItemContainerGenerator->GeneratorPositionFromIndex(NoesisInItemIndex));
}

class UNoesisGuiItemContainerGenerator* UNoesisGuiIItemContainerGenerator::GetItemContainerGeneratorForPanel(class UNoesisGuiPanel* InPanel)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	Panel* NoesisInPanel = NsDynamicCast<Panel*>(InPanel->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiItemContainerGenerator>(Instance->FindUnrealComponentForNoesisComponent(NoesisIItemContainerGenerator->GetItemContainerGeneratorForPanel(NoesisInPanel)));
}

int32 UNoesisGuiIItemContainerGenerator::IndexFromGeneratorPosition(FNoesisGuiGeneratorPosition InPosition)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	return NoesisIItemContainerGenerator->IndexFromGeneratorPosition(NoesisInPosition);
}

void UNoesisGuiIItemContainerGenerator::PrepareItemContainer(class UNoesisGuiDependencyObject* InContainer)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return NoesisIItemContainerGenerator->PrepareItemContainer(NoesisInContainer);
}

void UNoesisGuiIItemContainerGenerator::Remove(FNoesisGuiGeneratorPosition InPosition, int32 InCount)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	NsSize NoesisInCount = InCount;
	return NoesisIItemContainerGenerator->Remove(NoesisInPosition, NoesisInCount);
}

void UNoesisGuiIItemContainerGenerator::RemoveAll()
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	return NoesisIItemContainerGenerator->RemoveAll();
}

void UNoesisGuiIItemContainerGenerator::Stop()
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	return NoesisIItemContainerGenerator->Stop();
}

	void UNoesisGuiIItemContainerGenerator::BeginDestroy()
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	if (!NoesisIItemContainerGenerator)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

