////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiILayerManager.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiILayerManager::UNoesisGuiILayerManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiILayerManager::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ILayerManager* NoesisILayerManager = NsDynamicCast<Noesis::Gui::ILayerManager*>(InNoesisInterface);
	check(NoesisILayerManager);

}

void UNoesisGuiILayerManager::AddLayer(class UNoesisGuiVisual* InLayerRoot)
{
	Noesis::Gui::ILayerManager* NoesisILayerManager = NsDynamicCast<Noesis::Gui::ILayerManager*>(NoesisInterface.GetPtr());
	check(NoesisILayerManager);
	Visual* NoesisInLayerRoot = NsDynamicCast<Visual*>(InLayerRoot->NoesisComponent.GetPtr());
	return NoesisILayerManager->AddLayer(NoesisInLayerRoot);
}

void UNoesisGuiILayerManager::RemoveLayer(class UNoesisGuiVisual* InLayerRoot)
{
	Noesis::Gui::ILayerManager* NoesisILayerManager = NsDynamicCast<Noesis::Gui::ILayerManager*>(NoesisInterface.GetPtr());
	check(NoesisILayerManager);
	Visual* NoesisInLayerRoot = NsDynamicCast<Visual*>(InLayerRoot->NoesisComponent.GetPtr());
	return NoesisILayerManager->RemoveLayer(NoesisInLayerRoot);
}

	void UNoesisGuiILayerManager::BeginDestroy()
{
	Noesis::Gui::ILayerManager* NoesisILayerManager = NsDynamicCast<Noesis::Gui::ILayerManager*>(NoesisInterface.GetPtr());
	if (!NoesisILayerManager)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

