////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisPlaneProjection.h"

using namespace Noesis;
using namespace Gui;

UNoesisPlaneProjection::UNoesisPlaneProjection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisPlaneProjection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(InNoesisComponent);
	check(NoesisPlaneProjection);
}

float UNoesisPlaneProjection::GetCenterOfRotationX()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetCenterOfRotationX();
}

void UNoesisPlaneProjection::SetCenterOfRotationX(float InCenterOfRotationX)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetCenterOfRotationX(InCenterOfRotationX);
}

float UNoesisPlaneProjection::GetCenterOfRotationY()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetCenterOfRotationY();
}

void UNoesisPlaneProjection::SetCenterOfRotationY(float InCenterOfRotationY)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetCenterOfRotationY(InCenterOfRotationY);
}

float UNoesisPlaneProjection::GetCenterOfRotationZ()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetCenterOfRotationZ();
}

void UNoesisPlaneProjection::SetCenterOfRotationZ(float InCenterOfRotationZ)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetCenterOfRotationZ(InCenterOfRotationZ);
}

float UNoesisPlaneProjection::GetGlobalOffsetX()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetGlobalOffsetX();
}

void UNoesisPlaneProjection::SetGlobalOffsetX(float InGlobalOffsetX)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetGlobalOffsetX(InGlobalOffsetX);
}

float UNoesisPlaneProjection::GetGlobalOffsetY()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetGlobalOffsetY();
}

void UNoesisPlaneProjection::SetGlobalOffsetY(float InGlobalOffsetY)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetGlobalOffsetY(InGlobalOffsetY);
}

float UNoesisPlaneProjection::GetGlobalOffsetZ()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetGlobalOffsetZ();
}

void UNoesisPlaneProjection::SetGlobalOffsetZ(float InGlobalOffsetZ)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetGlobalOffsetZ(InGlobalOffsetZ);
}

float UNoesisPlaneProjection::GetLocalOffsetX()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetLocalOffsetX();
}

void UNoesisPlaneProjection::SetLocalOffsetX(float InLocalOffsetX)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetLocalOffsetX(InLocalOffsetX);
}

float UNoesisPlaneProjection::GetLocalOffsetY()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetLocalOffsetY();
}

void UNoesisPlaneProjection::SetLocalOffsetY(float InLocalOffsetY)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetLocalOffsetY(InLocalOffsetY);
}

float UNoesisPlaneProjection::GetLocalOffsetZ()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetLocalOffsetZ();
}

void UNoesisPlaneProjection::SetLocalOffsetZ(float InLocalOffsetZ)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetLocalOffsetZ(InLocalOffsetZ);
}

FMatrix UNoesisPlaneProjection::GetProjectionMatrix()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return NsMatrixToFMatrix(NoesisPlaneProjection->GetProjectionMatrix());
}

float UNoesisPlaneProjection::GetRotationX()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetRotationX();
}

void UNoesisPlaneProjection::SetRotationX(float InRotationX)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetRotationX(InRotationX);
}

float UNoesisPlaneProjection::GetRotationY()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetRotationY();
}

void UNoesisPlaneProjection::SetRotationY(float InRotationY)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetRotationY(InRotationY);
}

float UNoesisPlaneProjection::GetRotationZ()
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	return (float)NoesisPlaneProjection->GetRotationZ();
}

void UNoesisPlaneProjection::SetRotationZ(float InRotationZ)
{
	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection);
	NoesisPlaneProjection->SetRotationZ(InRotationZ);
}

void UNoesisPlaneProjection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection)


}

void UNoesisPlaneProjection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::PlaneProjection* NoesisPlaneProjection = NsDynamicCast<Noesis::Gui::PlaneProjection*>(NoesisComponent.GetPtr());
	check(NoesisPlaneProjection)


}

