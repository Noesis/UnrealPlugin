////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisINotifyPropertyChanged.h"

using namespace Noesis;
using namespace Gui;

UNoesisINotifyPropertyChanged::UNoesisINotifyPropertyChanged(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisINotifyPropertyChanged::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::INotifyPropertyChanged* NoesisINotifyPropertyChanged = NsDynamicCast<Noesis::Gui::INotifyPropertyChanged*>(InNoesisInterface);
	check(NoesisINotifyPropertyChanged);
}

void UNoesisINotifyPropertyChanged::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::INotifyPropertyChanged* NoesisINotifyPropertyChanged = NsDynamicCast<Noesis::Gui::INotifyPropertyChanged*>(NoesisInterface.GetPtr());
	check(NoesisINotifyPropertyChanged)


}

void UNoesisINotifyPropertyChanged::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::INotifyPropertyChanged* NoesisINotifyPropertyChanged = NsDynamicCast<Noesis::Gui::INotifyPropertyChanged*>(NoesisInterface.GetPtr());
	check(NoesisINotifyPropertyChanged)


}

