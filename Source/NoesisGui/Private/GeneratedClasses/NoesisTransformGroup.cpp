////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisTransformGroup.h"

using namespace Noesis;
using namespace Gui;

UNoesisTransformGroup::UNoesisTransformGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TransformGroup::StaticGetClassType();
}

void UNoesisTransformGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(InNoesisComponent);
	check(NoesisTransformGroup);
}

class UNoesisTransformCollection* UNoesisTransformGroup::GetChildren()
{
	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	check(NoesisTransformGroup);
	return CastChecked<UNoesisTransformCollection>(CreateClassFor(NoesisTransformGroup->GetChildren(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTransformGroup::SetChildren(class UNoesisTransformCollection* InChildren)
{
	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	check(NoesisTransformGroup);
	NoesisTransformGroup->SetChildren(NsDynamicCast<TransformCollection*>(InChildren->NoesisComponent.GetPtr()));
}

class UNoesisTransform* UNoesisTransformGroup::GetChild(int32 InIndex)
{
	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	check(NoesisTransformGroup);
	NsSize NoesisInIndex = (NsSize)InIndex;
	return CastChecked<UNoesisTransform>(CreateClassFor(NoesisTransformGroup->GetChild(NoesisInIndex), nullptr), ECastCheckedType::NullAllowed);
}

int32 UNoesisTransformGroup::GetNumChildren()
{
	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	check(NoesisTransformGroup);
	return (int32)NoesisTransformGroup->GetNumChildren();
}

void UNoesisTransformGroup::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	check(NoesisTransformGroup);


}

void UNoesisTransformGroup::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TransformGroup* NoesisTransformGroup = NsDynamicCast<Noesis::Gui::TransformGroup*>(NoesisComponent.GetPtr());
	check(NoesisTransformGroup);


}

