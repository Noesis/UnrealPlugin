////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisMatrix3DProjection.h"

using namespace Noesis;
using namespace Gui;

UNoesisMatrix3DProjection::UNoesisMatrix3DProjection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisMatrix3DProjection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Matrix3DProjection* NoesisMatrix3DProjection = NsDynamicCast<Noesis::Gui::Matrix3DProjection*>(InNoesisComponent);
	check(NoesisMatrix3DProjection);
}

FMatrix UNoesisMatrix3DProjection::GetProjectionMatrix()
{
	Noesis::Gui::Matrix3DProjection* NoesisMatrix3DProjection = NsDynamicCast<Noesis::Gui::Matrix3DProjection*>(NoesisComponent.GetPtr());
	check(NoesisMatrix3DProjection);
	return NsMatrixToFMatrix(NoesisMatrix3DProjection->GetProjectionMatrix());
}

void UNoesisMatrix3DProjection::SetProjectionMatrix(FMatrix InProjectionMatrix)
{
	Noesis::Gui::Matrix3DProjection* NoesisMatrix3DProjection = NsDynamicCast<Noesis::Gui::Matrix3DProjection*>(NoesisComponent.GetPtr());
	check(NoesisMatrix3DProjection);
	NoesisMatrix3DProjection->SetProjectionMatrix(FMatrixToNsMatrix(InProjectionMatrix));
}

void UNoesisMatrix3DProjection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Matrix3DProjection* NoesisMatrix3DProjection = NsDynamicCast<Noesis::Gui::Matrix3DProjection*>(NoesisComponent.GetPtr());
	check(NoesisMatrix3DProjection)


}

void UNoesisMatrix3DProjection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Matrix3DProjection* NoesisMatrix3DProjection = NsDynamicCast<Noesis::Gui::Matrix3DProjection*>(NoesisComponent.GetPtr());
	check(NoesisMatrix3DProjection)


}

