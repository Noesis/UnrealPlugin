////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisBaseValueConverter.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseValueConverter::UNoesisBaseValueConverter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BaseValueConverter::StaticGetClassType();
}

void UNoesisBaseValueConverter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseValueConverter* NoesisBaseValueConverter = NsDynamicCast<Noesis::Gui::BaseValueConverter*>(InNoesisComponent);
	check(NoesisBaseValueConverter);
}

void UNoesisBaseValueConverter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseValueConverter* NoesisBaseValueConverter = NsDynamicCast<Noesis::Gui::BaseValueConverter*>(NoesisComponent.GetPtr());
	check(NoesisBaseValueConverter);


}

void UNoesisBaseValueConverter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseValueConverter* NoesisBaseValueConverter = NsDynamicCast<Noesis::Gui::BaseValueConverter*>(NoesisComponent.GetPtr());
	check(NoesisBaseValueConverter);


}

