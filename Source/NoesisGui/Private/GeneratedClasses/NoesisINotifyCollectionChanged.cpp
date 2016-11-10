////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisINotifyCollectionChanged.h"

using namespace Noesis;
using namespace Gui;

UNoesisINotifyCollectionChanged::UNoesisINotifyCollectionChanged(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisINotifyCollectionChanged::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::INotifyCollectionChanged* NoesisINotifyCollectionChanged = NsDynamicCast<Noesis::Gui::INotifyCollectionChanged*>(InNoesisInterface);
	check(NoesisINotifyCollectionChanged);
}

void UNoesisINotifyCollectionChanged::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::INotifyCollectionChanged* NoesisINotifyCollectionChanged = NsDynamicCast<Noesis::Gui::INotifyCollectionChanged*>(NoesisInterface.GetPtr());
	check(NoesisINotifyCollectionChanged)


}

void UNoesisINotifyCollectionChanged::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::INotifyCollectionChanged* NoesisINotifyCollectionChanged = NsDynamicCast<Noesis::Gui::INotifyCollectionChanged*>(NoesisInterface.GetPtr());
	check(NoesisINotifyCollectionChanged)


}

