////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisIValueConverter.h"

using namespace Noesis;
using namespace Gui;

UNoesisIValueConverter::UNoesisIValueConverter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::IValueConverter::StaticGetClassType();
}

void UNoesisIValueConverter::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IValueConverter* NoesisIValueConverter = NsDynamicCast<Noesis::Gui::IValueConverter*>(InNoesisInterface);
	check(NoesisIValueConverter);
}

void UNoesisIValueConverter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IValueConverter* NoesisIValueConverter = NsDynamicCast<Noesis::Gui::IValueConverter*>(NoesisInterface.GetPtr());
	check(NoesisIValueConverter);


}

void UNoesisIValueConverter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IValueConverter* NoesisIValueConverter = NsDynamicCast<Noesis::Gui::IValueConverter*>(NoesisInterface.GetPtr());
	check(NoesisIValueConverter);


}

