////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisualStateManager.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisualStateManager::UNoesisGuiVisualStateManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisualStateManager::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualStateManager* NoesisVisualStateManager = NsDynamicCast<Noesis::Gui::VisualStateManager*>(InNoesisComponent);
	check(NoesisVisualStateManager);
}

void UNoesisGuiVisualStateManager::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VisualStateManager* NoesisVisualStateManager = NsDynamicCast<Noesis::Gui::VisualStateManager*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateManager)


}

void UNoesisGuiVisualStateManager::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VisualStateManager* NoesisVisualStateManager = NsDynamicCast<Noesis::Gui::VisualStateManager*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateManager)


}

