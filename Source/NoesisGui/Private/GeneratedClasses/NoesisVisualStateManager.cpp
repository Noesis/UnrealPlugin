////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisVisualStateManager.h"

using namespace Noesis;
using namespace Gui;

UNoesisVisualStateManager::UNoesisVisualStateManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisVisualStateManager::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualStateManager* NoesisVisualStateManager = NsDynamicCast<Noesis::Gui::VisualStateManager*>(InNoesisComponent);
	check(NoesisVisualStateManager);
}

void UNoesisVisualStateManager::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VisualStateManager* NoesisVisualStateManager = NsDynamicCast<Noesis::Gui::VisualStateManager*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateManager)


}

void UNoesisVisualStateManager::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VisualStateManager* NoesisVisualStateManager = NsDynamicCast<Noesis::Gui::VisualStateManager*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateManager)


}

