////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisSkewTransform.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisSkewTransform::UNoesisSkewTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::SkewTransform::StaticGetClassType();
}

void UNoesisSkewTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(InNoesisComponent);
	check(NoesisSkewTransform);
}

float UNoesisSkewTransform::GetAngleX()
{
	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);
	return (float)NoesisSkewTransform->GetAngleX();
}

void UNoesisSkewTransform::SetAngleX(float InAngleX)
{
	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);
	NoesisSkewTransform->SetAngleX(InAngleX);
}

float UNoesisSkewTransform::GetAngleY()
{
	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);
	return (float)NoesisSkewTransform->GetAngleY();
}

void UNoesisSkewTransform::SetAngleY(float InAngleY)
{
	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);
	NoesisSkewTransform->SetAngleY(InAngleY);
}

float UNoesisSkewTransform::GetCenterX()
{
	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);
	return (float)NoesisSkewTransform->GetCenterX();
}

void UNoesisSkewTransform::SetCenterX(float InCenterX)
{
	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);
	NoesisSkewTransform->SetCenterX(InCenterX);
}

float UNoesisSkewTransform::GetCenterY()
{
	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);
	return (float)NoesisSkewTransform->GetCenterY();
}

void UNoesisSkewTransform::SetCenterY(float InCenterY)
{
	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);
	NoesisSkewTransform->SetCenterY(InCenterY);
}

void UNoesisSkewTransform::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);


}

void UNoesisSkewTransform::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	check(NoesisSkewTransform);


}

