////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisRotateTransform.h"

using namespace Noesis;
using namespace Gui;

UNoesisRotateTransform::UNoesisRotateTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisRotateTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(InNoesisComponent);
	check(NoesisRotateTransform);
}

float UNoesisRotateTransform::GetAngle()
{
	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(NoesisComponent.GetPtr());
	check(NoesisRotateTransform);
	return (float)NoesisRotateTransform->GetAngle();
}

void UNoesisRotateTransform::SetAngle(float InAngle)
{
	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(NoesisComponent.GetPtr());
	check(NoesisRotateTransform);
	NoesisRotateTransform->SetAngle(InAngle);
}

float UNoesisRotateTransform::GetCenterX()
{
	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(NoesisComponent.GetPtr());
	check(NoesisRotateTransform);
	return (float)NoesisRotateTransform->GetCenterX();
}

void UNoesisRotateTransform::SetCenterX(float InCenterX)
{
	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(NoesisComponent.GetPtr());
	check(NoesisRotateTransform);
	NoesisRotateTransform->SetCenterX(InCenterX);
}

float UNoesisRotateTransform::GetCenterY()
{
	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(NoesisComponent.GetPtr());
	check(NoesisRotateTransform);
	return (float)NoesisRotateTransform->GetCenterY();
}

void UNoesisRotateTransform::SetCenterY(float InCenterY)
{
	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(NoesisComponent.GetPtr());
	check(NoesisRotateTransform);
	NoesisRotateTransform->SetCenterY(InCenterY);
}

void UNoesisRotateTransform::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(NoesisComponent.GetPtr());
	check(NoesisRotateTransform)


}

void UNoesisRotateTransform::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(NoesisComponent.GetPtr());
	check(NoesisRotateTransform)


}

