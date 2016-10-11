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

class UNoesisGuiTransform* UNoesisGuiTransformGroup::GetChild(int32 InIndex)
{
	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	check(NoesisTransformGroup);
	NsSize NoesisInIndex = InIndex;
	return CastChecked<UNoesisGuiTransform>(Instance->FindUnrealComponentForNoesisComponent(NoesisTransformGroup->GetChild(NoesisInIndex)));
}

int32 UNoesisGuiTransformGroup::GetNumChildren()
{
	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	check(NoesisTransformGroup);
	return (int32)NoesisTransformGroup->GetNumChildren();
}

	void UNoesisGuiTransformGroup::BeginDestroy()
{
	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	if (!NoesisTransformGroup)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

