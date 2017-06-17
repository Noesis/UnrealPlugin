////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisScaleTransform.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisScaleTransform::UNoesisScaleTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ScaleTransform::StaticGetClassType();
}

void UNoesisScaleTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(InNoesisComponent);
	check(NoesisScaleTransform);
}

float UNoesisScaleTransform::GetCenterX()
{
	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);
	return (float)NoesisScaleTransform->GetCenterX();
}

void UNoesisScaleTransform::SetCenterX(float InCenterX)
{
	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);
	NoesisScaleTransform->SetCenterX(InCenterX);
}

float UNoesisScaleTransform::GetCenterY()
{
	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);
	return (float)NoesisScaleTransform->GetCenterY();
}

void UNoesisScaleTransform::SetCenterY(float InCenterY)
{
	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);
	NoesisScaleTransform->SetCenterY(InCenterY);
}

float UNoesisScaleTransform::GetScaleX()
{
	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);
	return (float)NoesisScaleTransform->GetScaleX();
}

void UNoesisScaleTransform::SetScaleX(float InScaleX)
{
	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);
	NoesisScaleTransform->SetScaleX(InScaleX);
}

float UNoesisScaleTransform::GetScaleY()
{
	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);
	return (float)NoesisScaleTransform->GetScaleY();
}

void UNoesisScaleTransform::SetScaleY(float InScaleY)
{
	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);
	NoesisScaleTransform->SetScaleY(InScaleY);
}

void UNoesisScaleTransform::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);


}

void UNoesisScaleTransform::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ScaleTransform* NoesisScaleTransform = NsDynamicCast<Noesis::Gui::ScaleTransform*>(NoesisComponent.GetPtr());
	check(NoesisScaleTransform);


}

