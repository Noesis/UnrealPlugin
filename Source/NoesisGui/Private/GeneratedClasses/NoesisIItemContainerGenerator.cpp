////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisIItemContainerGenerator.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisIItemContainerGenerator::UNoesisIItemContainerGenerator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::IItemContainerGenerator::StaticGetClassType();
}

void UNoesisIItemContainerGenerator::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(InNoesisInterface);
	check(NoesisIItemContainerGenerator);
}

class UNoesisDependencyObject* UNoesisIItemContainerGenerator::GenerateNext()
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	return CastChecked<UNoesisDependencyObject>(CreateClassFor(NoesisIItemContainerGenerator->GenerateNext(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisDependencyObject* UNoesisIItemContainerGenerator::GenerateNext_(bool& InIsNewlyRealized)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	NsBool NoesisInIsNewlyRealized = InIsNewlyRealized;
	return CastChecked<UNoesisDependencyObject>(CreateClassFor(NoesisIItemContainerGenerator->GenerateNext(NoesisInIsNewlyRealized), nullptr), ECastCheckedType::NullAllowed);
}

FNoesisGeneratorPosition UNoesisIItemContainerGenerator::GeneratorPositionFromIndex(int32 InItemIndex)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	NsInt NoesisInItemIndex = InItemIndex;
	return FNoesisGeneratorPosition(NoesisIItemContainerGenerator->GeneratorPositionFromIndex(NoesisInItemIndex));
}

class UNoesisItemContainerGenerator* UNoesisIItemContainerGenerator::GetItemContainerGeneratorForPanel(class UNoesisPanel* InPanel)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	Panel* NoesisInPanel = NsDynamicCast<Panel*>(InPanel->NoesisComponent.GetPtr());
	return CastChecked<UNoesisItemContainerGenerator>(CreateClassFor(NoesisIItemContainerGenerator->GetItemContainerGeneratorForPanel(NoesisInPanel), nullptr), ECastCheckedType::NullAllowed);
}

int32 UNoesisIItemContainerGenerator::IndexFromGeneratorPosition(FNoesisGeneratorPosition InPosition)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	return NoesisIItemContainerGenerator->IndexFromGeneratorPosition(NoesisInPosition);
}

void UNoesisIItemContainerGenerator::PrepareItemContainer(class UNoesisDependencyObject* InContainer)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	DependencyObject* NoesisInContainer = NsDynamicCast<DependencyObject*>(InContainer->NoesisComponent.GetPtr());
	return NoesisIItemContainerGenerator->PrepareItemContainer(NoesisInContainer);
}

void UNoesisIItemContainerGenerator::Remove(FNoesisGeneratorPosition InPosition, int32 InCount)
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	NsSize NoesisInCount = (NsSize)InCount;
	return NoesisIItemContainerGenerator->Remove(NoesisInPosition, NoesisInCount);
}

void UNoesisIItemContainerGenerator::RemoveAll()
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	return NoesisIItemContainerGenerator->RemoveAll();
}

void UNoesisIItemContainerGenerator::Stop()
{
	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);
	return NoesisIItemContainerGenerator->Stop();
}

void UNoesisIItemContainerGenerator::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);


}

void UNoesisIItemContainerGenerator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IItemContainerGenerator* NoesisIItemContainerGenerator = NsDynamicCast<Noesis::Gui::IItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIItemContainerGenerator);


}

