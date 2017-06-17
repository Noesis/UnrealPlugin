////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisIRecyclingItemContainerGenerator.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisIRecyclingItemContainerGenerator::UNoesisIRecyclingItemContainerGenerator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::IRecyclingItemContainerGenerator::StaticGetClassType();
}

void UNoesisIRecyclingItemContainerGenerator::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IRecyclingItemContainerGenerator* NoesisIRecyclingItemContainerGenerator = NsDynamicCast<Noesis::Gui::IRecyclingItemContainerGenerator*>(InNoesisInterface);
	check(NoesisIRecyclingItemContainerGenerator);
}

void UNoesisIRecyclingItemContainerGenerator::Recycle(FNoesisGeneratorPosition InPosition, int32 InCount)
{
	Noesis::Gui::IRecyclingItemContainerGenerator* NoesisIRecyclingItemContainerGenerator = NsDynamicCast<Noesis::Gui::IRecyclingItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIRecyclingItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	NsSize NoesisInCount = (NsSize)InCount;
	return NoesisIRecyclingItemContainerGenerator->Recycle(NoesisInPosition, NoesisInCount);
}

void UNoesisIRecyclingItemContainerGenerator::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IRecyclingItemContainerGenerator* NoesisIRecyclingItemContainerGenerator = NsDynamicCast<Noesis::Gui::IRecyclingItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIRecyclingItemContainerGenerator);


}

void UNoesisIRecyclingItemContainerGenerator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IRecyclingItemContainerGenerator* NoesisIRecyclingItemContainerGenerator = NsDynamicCast<Noesis::Gui::IRecyclingItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIRecyclingItemContainerGenerator);


}

