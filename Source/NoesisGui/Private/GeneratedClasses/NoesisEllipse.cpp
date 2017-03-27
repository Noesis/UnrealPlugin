////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisEllipse.h"

using namespace Noesis;
using namespace Gui;

UNoesisEllipse::UNoesisEllipse(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Ellipse::StaticGetClassType();
}

void UNoesisEllipse::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Ellipse* NoesisEllipse = NsDynamicCast<Noesis::Gui::Ellipse*>(InNoesisComponent);
	check(NoesisEllipse);
}

void UNoesisEllipse::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Ellipse* NoesisEllipse = NsDynamicCast<Noesis::Gui::Ellipse*>(NoesisComponent.GetPtr());
	check(NoesisEllipse);


}

void UNoesisEllipse::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Ellipse* NoesisEllipse = NsDynamicCast<Noesis::Gui::Ellipse*>(NoesisComponent.GetPtr());
	check(NoesisEllipse);


}

