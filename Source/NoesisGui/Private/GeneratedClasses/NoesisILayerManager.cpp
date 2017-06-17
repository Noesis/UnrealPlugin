////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisILayerManager.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisILayerManager::UNoesisILayerManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::ILayerManager::StaticGetClassType();
}

void UNoesisILayerManager::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ILayerManager* NoesisILayerManager = NsDynamicCast<Noesis::Gui::ILayerManager*>(InNoesisInterface);
	check(NoesisILayerManager);
}

void UNoesisILayerManager::AddLayer(class UNoesisVisual* InLayerRoot)
{
	Noesis::Gui::ILayerManager* NoesisILayerManager = NsDynamicCast<Noesis::Gui::ILayerManager*>(NoesisInterface.GetPtr());
	check(NoesisILayerManager);
	Visual* NoesisInLayerRoot = NsDynamicCast<Visual*>(InLayerRoot->NoesisComponent.GetPtr());
	return NoesisILayerManager->AddLayer(NoesisInLayerRoot);
}

void UNoesisILayerManager::RemoveLayer(class UNoesisVisual* InLayerRoot)
{
	Noesis::Gui::ILayerManager* NoesisILayerManager = NsDynamicCast<Noesis::Gui::ILayerManager*>(NoesisInterface.GetPtr());
	check(NoesisILayerManager);
	Visual* NoesisInLayerRoot = NsDynamicCast<Visual*>(InLayerRoot->NoesisComponent.GetPtr());
	return NoesisILayerManager->RemoveLayer(NoesisInLayerRoot);
}

void UNoesisILayerManager::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ILayerManager* NoesisILayerManager = NsDynamicCast<Noesis::Gui::ILayerManager*>(NoesisInterface.GetPtr());
	check(NoesisILayerManager);


}

void UNoesisILayerManager::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ILayerManager* NoesisILayerManager = NsDynamicCast<Noesis::Gui::ILayerManager*>(NoesisInterface.GetPtr());
	check(NoesisILayerManager);


}

