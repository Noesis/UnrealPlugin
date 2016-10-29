////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPath.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPath::UNoesisGuiPath(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPath::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Path* NoesisPath = NsDynamicCast<Noesis::Gui::Path*>(InNoesisComponent);
	check(NoesisPath);
}

void UNoesisGuiPath::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Path* NoesisPath = NsDynamicCast<Noesis::Gui::Path*>(NoesisComponent.GetPtr());
	check(NoesisPath)


}

void UNoesisGuiPath::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Path* NoesisPath = NsDynamicCast<Noesis::Gui::Path*>(NoesisComponent.GetPtr());
	check(NoesisPath)


}

