////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisGrid.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisGrid::UNoesisGrid(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Grid::StaticGetClassType();
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
	return CastChecked<UNoesisColumnDefinitionCollection>(CreateClassFor(NoesisGrid->GetColumnDefinitions(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisRowDefinitionCollection* UNoesisGrid::GetRowDefinitions()
{
	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid);
	return CastChecked<UNoesisRowDefinitionCollection>(CreateClassFor(NoesisGrid->GetRowDefinitions(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisGrid::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid);


}

void UNoesisGrid::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Grid* NoesisGrid = NsDynamicCast<Noesis::Gui::Grid*>(NoesisComponent.GetPtr());
	check(NoesisGrid);


}

