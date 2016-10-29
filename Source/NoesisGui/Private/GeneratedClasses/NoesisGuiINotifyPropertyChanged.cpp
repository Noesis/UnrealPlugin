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

void UNoesisGuiINotifyPropertyChanged::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::INotifyPropertyChanged* NoesisINotifyPropertyChanged = NsDynamicCast<Noesis::Gui::INotifyPropertyChanged*>(NoesisInterface.GetPtr());
	check(NoesisINotifyPropertyChanged)


}

void UNoesisGuiINotifyPropertyChanged::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::INotifyPropertyChanged* NoesisINotifyPropertyChanged = NsDynamicCast<Noesis::Gui::INotifyPropertyChanged*>(NoesisInterface.GetPtr());
	check(NoesisINotifyPropertyChanged)


}

