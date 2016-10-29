////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPlaneProjection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPlaneProjection::UNoesisGuiPlaneProjection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPlaneProjection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(InNoesisComponent);
	check(NoesisPlaneProjection);
}

void UNoesisGuiPlaneProjection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection)


}

void UNoesisGuiPlaneProjection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection)


}

