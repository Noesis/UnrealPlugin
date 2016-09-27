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

	void UNoesisGuiItemContainerGenerator::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ItemContainerGenerator* NoesisItemContainerGenerator = NsDynamicCast<Noesis::Gui::ItemContainerGenerator*>(NoesisComponent.GetPtr());
	if (!NoesisItemContainerGenerator)
		return;

}

