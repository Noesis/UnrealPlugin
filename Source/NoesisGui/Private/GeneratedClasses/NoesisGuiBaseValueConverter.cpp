////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseValueConverter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseValueConverter::UNoesisGuiBaseValueConverter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseValueConverter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseValueConverter* NoesisBaseValueConverter = NsDynamicCast<Noesis::Gui::BaseValueConverter*>(InNoesisComponent);
	check(NoesisBaseValueConverter);
}

void UNoesisGuiBaseValueConverter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseValueConverter* NoesisBaseValueConverter = NsDynamicCast<Noesis::Gui::BaseValueConverter*>(NoesisComponent.GetPtr());
	check(NoesisBaseValueConverter)


}

void UNoesisGuiBaseValueConverter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseValueConverter* NoesisBaseValueConverter = NsDynamicCast<Noesis::Gui::BaseValueConverter*>(NoesisComponent.GetPtr());
	check(NoesisBaseValueConverter)


}

