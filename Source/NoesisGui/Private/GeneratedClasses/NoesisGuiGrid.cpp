////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGrid.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGrid::UNoesisGuiGrid(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGrid::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(InNoesisComponent);
	check(NoesisGrid);
}

class UNoesisGuiColumnDefinitionCollection* UNoesisGuiGrid::GetColumnDefinitions()
{
	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid);
	return CastChecked<UNoesisGuiColumnDefinitionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisGrid->GetColumnDefinitions()));
}

class UNoesisGuiRowDefinitionCollection* UNoesisGuiGrid::GetRowDefinitions()
{
	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid);
	return CastChecked<UNoesisGuiRowDefinitionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisGrid->GetRowDefinitions()));
}

void UNoesisGuiGrid::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid)


}

void UNoesisGuiGrid::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid)


}

