////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiINotifyCollectionChanged.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiINotifyCollectionChanged::UNoesisGuiINotifyCollectionChanged(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiINotifyCollectionChanged::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::INotifyCollectionChanged* NoesisINotifyCollectionChanged = NsDynamicCast<Noesis::Gui::INotifyCollectionChanged*>(InNoesisInterface);
	check(NoesisINotifyCollectionChanged);

}

	void UNoesisGuiINotifyCollectionChanged::BeginDestroy()
{
	Noesis::Gui::INotifyCollectionChanged* NoesisINotifyCollectionChanged = NsDynamicCast<Noesis::Gui::INotifyCollectionChanged*>(NoesisInterface.GetPtr());
	if (!NoesisINotifyCollectionChanged)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

