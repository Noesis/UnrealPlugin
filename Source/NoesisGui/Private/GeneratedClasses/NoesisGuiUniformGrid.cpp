////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiUniformGrid.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiUniformGrid::UNoesisGuiUniformGrid(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiUniformGrid::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(InNoesisComponent);
	check(NoesisUniformGrid);
}

void UNoesisGuiUniformGrid::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid)


}

void UNoesisGuiUniformGrid::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid)


}

