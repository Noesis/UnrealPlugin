////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEllipse.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEllipse::UNoesisGuiEllipse(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEllipse::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Ellipse* NoesisEllipse = NsDynamicCast<Noesis::Gui::Ellipse*>(InNoesisComponent);
	check(NoesisEllipse);
}

void UNoesisGuiEllipse::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Ellipse* NoesisEllipse = NsDynamicCast<Noesis::Gui::Ellipse*>(NoesisComponent.GetPtr());
	check(NoesisEllipse)


}

void UNoesisGuiEllipse::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Ellipse* NoesisEllipse = NsDynamicCast<Noesis::Gui::Ellipse*>(NoesisComponent.GetPtr());
	check(NoesisEllipse)


}

