////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiColumnDefinition.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiColumnDefinition::UNoesisGuiColumnDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiColumnDefinition::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(InNoesisComponent);
	check(NoesisColumnDefinition);
}

void UNoesisGuiColumnDefinition::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition)


}

void UNoesisGuiColumnDefinition::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ColumnDefinition* NoesisColumnDefinition = NsDynamicCast<Noesis::Gui::ColumnDefinition*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinition)


}

