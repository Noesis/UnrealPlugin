////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSolidColorBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSolidColorBrush::UNoesisGuiSolidColorBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSolidColorBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SolidColorBrush* NoesisSolidColorBrush = NsDynamicCast<Noesis::Gui::SolidColorBrush*>(InNoesisComponent);
	check(NoesisSolidColorBrush);
}

void UNoesisGuiSolidColorBrush::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SolidColorBrush* NoesisSolidColorBrush = NsDynamicCast<Noesis::Gui::SolidColorBrush*>(NoesisComponent.GetPtr());
	check(NoesisSolidColorBrush)


}

void UNoesisGuiSolidColorBrush::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SolidColorBrush* NoesisSolidColorBrush = NsDynamicCast<Noesis::Gui::SolidColorBrush*>(NoesisComponent.GetPtr());
	check(NoesisSolidColorBrush)


}

