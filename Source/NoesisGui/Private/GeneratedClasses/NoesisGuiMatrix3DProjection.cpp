////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiMatrix3DProjection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiMatrix3DProjection::UNoesisGuiMatrix3DProjection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiMatrix3DProjection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Matrix3DProjection* NoesisMatrix3DProjection = NsDynamicCast<Noesis::Gui::Matrix3DProjection*>(InNoesisComponent);
	check(NoesisMatrix3DProjection);
}

void UNoesisGuiMatrix3DProjection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Matrix3DProjection* NoesisMatrix3DProjection = NsDynamicCast<Noesis::Gui::Matrix3DProjection*>(NoesisComponent.GetPtr());
	check(NoesisMatrix3DProjection)


}

void UNoesisGuiMatrix3DProjection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Matrix3DProjection* NoesisMatrix3DProjection = NsDynamicCast<Noesis::Gui::Matrix3DProjection*>(NoesisComponent.GetPtr());
	check(NoesisMatrix3DProjection)


}

