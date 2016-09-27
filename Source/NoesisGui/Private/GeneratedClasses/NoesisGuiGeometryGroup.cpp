////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGeometryGroup.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGeometryGroup::UNoesisGuiGeometryGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGeometryGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GeometryGroup* NoesisGeometryGroup = NsDynamicCast<Noesis::Gui::GeometryGroup*>(InNoesisComponent);
	check(NoesisGeometryGroup);

}

	void UNoesisGuiGeometryGroup::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::GeometryGroup* NoesisGeometryGroup = NsDynamicCast<Noesis::Gui::GeometryGroup*>(NoesisComponent.GetPtr());
	if (!NoesisGeometryGroup)
		return;

}

