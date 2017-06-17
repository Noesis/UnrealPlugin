////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisUniformGrid.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisUniformGrid::UNoesisUniformGrid(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::UniformGrid::StaticGetClassType();
}

void UNoesisUniformGrid::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(InNoesisComponent);
	check(NoesisUniformGrid);
}

int32 UNoesisUniformGrid::GetColumns()
{
	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid);
	return NoesisUniformGrid->GetColumns();
}

void UNoesisUniformGrid::SetColumns(int32 InColumns)
{
	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid);
	NoesisUniformGrid->SetColumns(InColumns);
}

int32 UNoesisUniformGrid::GetFirstColumn()
{
	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid);
	return NoesisUniformGrid->GetFirstColumn();
}

void UNoesisUniformGrid::SetFirstColumn(int32 InFirstColumn)
{
	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid);
	NoesisUniformGrid->SetFirstColumn(InFirstColumn);
}

int32 UNoesisUniformGrid::GetRows()
{
	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid);
	return NoesisUniformGrid->GetRows();
}

void UNoesisUniformGrid::SetRows(int32 InRows)
{
	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid);
	NoesisUniformGrid->SetRows(InRows);
}

void UNoesisUniformGrid::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid);


}

void UNoesisUniformGrid::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::UniformGrid* NoesisUniformGrid = NsDynamicCast<Noesis::Gui::UniformGrid*>(NoesisComponent.GetPtr());
	check(NoesisUniformGrid);


}

