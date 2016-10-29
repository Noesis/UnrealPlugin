////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPropertyMetadata.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPropertyMetadata::UNoesisGuiPropertyMetadata(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPropertyMetadata::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PropertyMetadata* NoesisPropertyMetadata = NsDynamicCast<Noesis::Gui::PropertyMetadata*>(InNoesisComponent);
	check(NoesisPropertyMetadata);
}

void UNoesisGuiPropertyMetadata::ClearInheritedValues()
{
	Noesis::Gui::PropertyMetadata* NoesisPropertyMetadata = NsDynamicCast<Noesis::Gui::PropertyMetadata*>(NoesisComponent.GetPtr());
	check(NoesisPropertyMetadata);
	return NoesisPropertyMetadata->ClearInheritedValues();
}

void UNoesisGuiPropertyMetadata::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::PropertyMetadata* NoesisPropertyMetadata = NsDynamicCast<Noesis::Gui::PropertyMetadata*>(NoesisComponent.GetPtr());
	check(NoesisPropertyMetadata)


}

void UNoesisGuiPropertyMetadata::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::PropertyMetadata* NoesisPropertyMetadata = NsDynamicCast<Noesis::Gui::PropertyMetadata*>(NoesisComponent.GetPtr());
	check(NoesisPropertyMetadata)


}

