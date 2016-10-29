////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEllipseGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEllipseGeometry::UNoesisGuiEllipseGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEllipseGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(InNoesisComponent);
	check(NoesisEllipseGeometry);
}

void UNoesisGuiEllipseGeometry::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry)


}

void UNoesisGuiEllipseGeometry::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry)


}

