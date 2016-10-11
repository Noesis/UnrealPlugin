////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIRecyclingItemContainerGenerator.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIRecyclingItemContainerGenerator::UNoesisGuiIRecyclingItemContainerGenerator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIRecyclingItemContainerGenerator::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IRecyclingItemContainerGenerator* NoesisIRecyclingItemContainerGenerator = NsDynamicCast<Noesis::Gui::IRecyclingItemContainerGenerator*>(InNoesisInterface);
	check(NoesisIRecyclingItemContainerGenerator);

}

void UNoesisGuiIRecyclingItemContainerGenerator::Recycle(FNoesisGuiGeneratorPosition InPosition, int32 InCount)
{
	Noesis::Gui::IRecyclingItemContainerGenerator* NoesisIRecyclingItemContainerGenerator = NsDynamicCast<Noesis::Gui::IRecyclingItemContainerGenerator*>(NoesisInterface.GetPtr());
	check(NoesisIRecyclingItemContainerGenerator);
	const GeneratorPosition NoesisInPosition = InPosition.ToNoesis();
	NsSize NoesisInCount = InCount;
	return NoesisIRecyclingItemContainerGenerator->Recycle(NoesisInPosition, NoesisInCount);
}

	void UNoesisGuiIRecyclingItemContainerGenerator::BeginDestroy()
{
	Noesis::Gui::IRecyclingItemContainerGenerator* NoesisIRecyclingItemContainerGenerator = NsDynamicCast<Noesis::Gui::IRecyclingItemContainerGenerator*>(NoesisInterface.GetPtr());
	if (!NoesisIRecyclingItemContainerGenerator)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

