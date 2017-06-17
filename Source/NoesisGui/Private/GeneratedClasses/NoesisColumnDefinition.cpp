////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisColumnDefinition.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisColumnDefinition::UNoesisColumnDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ColumnDefinition::StaticGetClassType();
}

void UNoesisColumnDefinition::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(InNoesisComponent);
	check(NoesisColumnDefinition);
}

float UNoesisColumnDefinition::GetMaxWidth()
{
	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition);
	return (float)NoesisColumnDefinition->GetMaxWidth();
}

void UNoesisColumnDefinition::SetMaxWidth(float InMaxWidth)
{
	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition);
	NoesisColumnDefinition->SetMaxWidth(InMaxWidth);
}

float UNoesisColumnDefinition::GetMinWidth()
{
	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition);
	return (float)NoesisColumnDefinition->GetMinWidth();
}

void UNoesisColumnDefinition::SetMinWidth(float InMinWidth)
{
	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition);
	NoesisColumnDefinition->SetMinWidth(InMinWidth);
}

FNoesisGridLength UNoesisColumnDefinition::GetGridLengthWidth()
{
	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition);
	return FNoesisGridLength(NoesisColumnDefinition->GetWidth());
}

void UNoesisColumnDefinition::SetGridLengthWidth(FNoesisGridLength InWidth)
{
	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition);
	NoesisColumnDefinition->SetWidth(InWidth.ToNoesis());
}

void UNoesisColumnDefinition::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition);


}

void UNoesisColumnDefinition::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition);


}

