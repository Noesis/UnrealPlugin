////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiProjection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiProjection::UNoesisGuiProjection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiProjection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Projection* NoesisProjection = NsDynamicCast<Noesis::Gui::Projection*>(InNoesisComponent);
	check(NoesisProjection);

}

bool UNoesisGuiProjection::IsIdentity()
{
	Noesis::Gui::Projection* NoesisProjection = NsDynamicCast<Noesis::Gui::Projection*>(NoesisComponent.GetPtr());
	check(NoesisProjection);
	return NoesisProjection->IsIdentity();
}

	void UNoesisGuiProjection::BeginDestroy()
{
	Noesis::Gui::Projection* NoesisProjection = NsDynamicCast<Noesis::Gui::Projection*>(NoesisComponent.GetPtr());
	if (!NoesisProjection)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

