////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIValueConverter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIValueConverter::UNoesisGuiIValueConverter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIValueConverter::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IValueConverter* NoesisIValueConverter = NsDynamicCast<Noesis::Gui::IValueConverter*>(InNoesisInterface);
	check(NoesisIValueConverter);
}

void UNoesisGuiIValueConverter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IValueConverter* NoesisIValueConverter = NsDynamicCast<Noesis::Gui::IValueConverter*>(NoesisInterface.GetPtr());
	check(NoesisIValueConverter)


}

void UNoesisGuiIValueConverter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IValueConverter* NoesisIValueConverter = NsDynamicCast<Noesis::Gui::IValueConverter*>(NoesisInterface.GetPtr());
	check(NoesisIValueConverter)


}

