////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisProjection.h"

using namespace Noesis;
using namespace Gui;

UNoesisProjection::UNoesisProjection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisProjection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Projection* NoesisProjection = NsDynamicCast<Noesis::Gui::Projection*>(InNoesisComponent);
	check(NoesisProjection);
}

bool UNoesisProjection::IsIdentity()
{
	Noesis::Gui::Projection* NoesisProjection = NsDynamicCast<Noesis::Gui::Projection*>(NoesisComponent.GetPtr());
	check(NoesisProjection);
	return NoesisProjection->IsIdentity();
}

void UNoesisProjection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Projection* NoesisProjection = NsDynamicCast<Noesis::Gui::Projection*>(NoesisComponent.GetPtr());
	check(NoesisProjection)


}

void UNoesisProjection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Projection* NoesisProjection = NsDynamicCast<Noesis::Gui::Projection*>(NoesisComponent.GetPtr());
	check(NoesisProjection)


}

