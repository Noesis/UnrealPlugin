////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGrid.h"

using namespace Noesis;
using namespace Gui;

UNoesisGrid::UNoesisGrid(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGrid::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(InNoesisComponent);
	check(NoesisGrid);
}

class UNoesisColumnDefinitionCollection* UNoesisGrid::GetColumnDefinitions()
{
	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid);
	return CastChecked<UNoesisColumnDefinitionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisGrid->GetColumnDefinitions()));
}

class UNoesisRowDefinitionCollection* UNoesisGrid::GetRowDefinitions()
{
	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid);
	return CastChecked<UNoesisRowDefinitionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisGrid->GetRowDefinitions()));
}

void UNoesisGrid::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid)


}

void UNoesisGrid::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid)


}

