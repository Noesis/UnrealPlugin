////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisItemsPanelTemplate.h"

using namespace Noesis;
using namespace Gui;

UNoesisItemsPanelTemplate::UNoesisItemsPanelTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ItemsPanelTemplate::StaticGetClassType();
}

void UNoesisItemsPanelTemplate::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemsPanelTemplate* NoesisItemsPanelTemplate = NsDynamicCast<Noesis::Gui::ItemsPanelTemplate*>(InNoesisComponent);
	check(NoesisItemsPanelTemplate);
}

void UNoesisItemsPanelTemplate::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ItemsPanelTemplate* NoesisItemsPanelTemplate = NsDynamicCast<Noesis::Gui::ItemsPanelTemplate*>(NoesisComponent.GetPtr());
	check(NoesisItemsPanelTemplate);


}

void UNoesisItemsPanelTemplate::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ItemsPanelTemplate* NoesisItemsPanelTemplate = NsDynamicCast<Noesis::Gui::ItemsPanelTemplate*>(NoesisComponent.GetPtr());
	check(NoesisItemsPanelTemplate);


}

