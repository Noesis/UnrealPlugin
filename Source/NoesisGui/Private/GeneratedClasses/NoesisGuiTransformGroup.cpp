////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTransformGroup.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTransformGroup::UNoesisGuiTransformGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTransformGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(InNoesisComponent);
	check(NoesisTransformGroup);

}

	void UNoesisGuiTransformGroup::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	if (!NoesisTransformGroup)
		return;

}

