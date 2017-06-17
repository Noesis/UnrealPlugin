////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisINotifyPropertyChanged.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisINotifyPropertyChanged::UNoesisINotifyPropertyChanged(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::INotifyPropertyChanged::StaticGetClassType();
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
	check(NoesisINotifyPropertyChanged);


}

void UNoesisINotifyPropertyChanged::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::INotifyPropertyChanged* NoesisINotifyPropertyChanged = NsDynamicCast<Noesis::Gui::INotifyPropertyChanged*>(NoesisInterface.GetPtr());
	check(NoesisINotifyPropertyChanged);


}

