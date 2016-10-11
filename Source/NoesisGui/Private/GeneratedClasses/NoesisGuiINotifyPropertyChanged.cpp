////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiINotifyPropertyChanged.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiINotifyPropertyChanged::UNoesisGuiINotifyPropertyChanged(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiINotifyPropertyChanged::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::INotifyPropertyChanged* NoesisINotifyPropertyChanged = NsDynamicCast<Noesis::Gui::INotifyPropertyChanged*>(InNoesisInterface);
	check(NoesisINotifyPropertyChanged);

}

	void UNoesisGuiINotifyPropertyChanged::BeginDestroy()
{
	Noesis::Gui::INotifyPropertyChanged* NoesisINotifyPropertyChanged = NsDynamicCast<Noesis::Gui::INotifyPropertyChanged*>(NoesisInterface.GetPtr());
	if (!NoesisINotifyPropertyChanged)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

