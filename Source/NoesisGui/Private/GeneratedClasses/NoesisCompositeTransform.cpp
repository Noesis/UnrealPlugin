////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisCompositeTransform.h"

using namespace Noesis;
using namespace Gui;

UNoesisCompositeTransform::UNoesisCompositeTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisCompositeTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(InNoesisComponent);
	check(NoesisCompositeTransform);
}

float UNoesisCompositeTransform::GetCenterX()
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	return (float)NoesisCompositeTransform->GetCenterX();
}

void UNoesisCompositeTransform::SetCenterX(float InCenterX)
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	NoesisCompositeTransform->SetCenterX(InCenterX);
}

float UNoesisCompositeTransform::GetCenterY()
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	return (float)NoesisCompositeTransform->GetCenterY();
}

void UNoesisCompositeTransform::SetCenterY(float InCenterY)
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	NoesisCompositeTransform->SetCenterY(InCenterY);
}

float UNoesisCompositeTransform::GetRotation()
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	return (float)NoesisCompositeTransform->GetRotation();
}

void UNoesisCompositeTransform::SetRotation(float InRotation)
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	NoesisCompositeTransform->SetRotation(InRotation);
}

float UNoesisCompositeTransform::GetScaleX()
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	return (float)NoesisCompositeTransform->GetScaleX();
}

void UNoesisCompositeTransform::SetScaleX(float InScaleX)
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	NoesisCompositeTransform->SetScaleX(InScaleX);
}

float UNoesisCompositeTransform::GetScaleY()
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	return (float)NoesisCompositeTransform->GetScaleY();
}

void UNoesisCompositeTransform::SetScaleY(float InScaleY)
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	NoesisCompositeTransform->SetScaleY(InScaleY);
}

float UNoesisCompositeTransform::GetSkewX()
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	return (float)NoesisCompositeTransform->GetSkewX();
}

void UNoesisCompositeTransform::SetSkewX(float InSkewX)
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	NoesisCompositeTransform->SetSkewX(InSkewX);
}

float UNoesisCompositeTransform::GetSkewY()
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	return (float)NoesisCompositeTransform->GetSkewY();
}

void UNoesisCompositeTransform::SetSkewY(float InSkewY)
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	NoesisCompositeTransform->SetSkewY(InSkewY);
}

float UNoesisCompositeTransform::GetTranslateX()
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	return (float)NoesisCompositeTransform->GetTranslateX();
}

void UNoesisCompositeTransform::SetTranslateX(float InTranslateX)
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	NoesisCompositeTransform->SetTranslateX(InTranslateX);
}

float UNoesisCompositeTransform::GetTranslateY()
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	return (float)NoesisCompositeTransform->GetTranslateY();
}

void UNoesisCompositeTransform::SetTranslateY(float InTranslateY)
{
	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform);
	NoesisCompositeTransform->SetTranslateY(InTranslateY);
}

void UNoesisCompositeTransform::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform)


}

void UNoesisCompositeTransform::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CompositeTransform* NoesisCompositeTransform = NsDynamicCast<Noesis::Gui::CompositeTransform*>(NoesisComponent.GetPtr());
	check(NoesisCompositeTransform)


}

