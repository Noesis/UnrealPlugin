////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisGradientBrush.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisGradientBrush::UNoesisGradientBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::GradientBrush::StaticGetClassType();
}

void UNoesisGradientBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(InNoesisComponent);
	check(NoesisGradientBrush);
}

ENoesisColorInterpolationMode UNoesisGradientBrush::GetColorInterpolationMode()
{
	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);
	return (ENoesisColorInterpolationMode)NoesisGradientBrush->GetColorInterpolationMode();
}

void UNoesisGradientBrush::SetColorInterpolationMode(ENoesisColorInterpolationMode InColorInterpolationMode)
{
	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);
	NoesisGradientBrush->SetColorInterpolationMode((Noesis::Gui::ColorInterpolationMode)InColorInterpolationMode);
}

class UNoesisGradientStopCollection* UNoesisGradientBrush::GetGradientStops()
{
	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);
	return CastChecked<UNoesisGradientStopCollection>(CreateClassFor(NoesisGradientBrush->GetGradientStops(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisGradientBrush::SetGradientStops(class UNoesisGradientStopCollection* InGradientStops)
{
	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);
	NoesisGradientBrush->SetGradientStops(NsDynamicCast<GradientStopCollection*>(InGradientStops->NoesisComponent.GetPtr()));
}

ENoesisBrushMappingMode UNoesisGradientBrush::GetMappingMode()
{
	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);
	return (ENoesisBrushMappingMode)NoesisGradientBrush->GetMappingMode();
}

void UNoesisGradientBrush::SetMappingMode(ENoesisBrushMappingMode InMappingMode)
{
	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);
	NoesisGradientBrush->SetMappingMode((Noesis::Gui::BrushMappingMode)InMappingMode);
}

ENoesisGradientSpreadMethod UNoesisGradientBrush::GetSpreadMethod()
{
	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);
	return (ENoesisGradientSpreadMethod)NoesisGradientBrush->GetSpreadMethod();
}

void UNoesisGradientBrush::SetSpreadMethod(ENoesisGradientSpreadMethod InSpreadMethod)
{
	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);
	NoesisGradientBrush->SetSpreadMethod((Noesis::Gui::GradientSpreadMethod)InSpreadMethod);
}

void UNoesisGradientBrush::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);


}

void UNoesisGradientBrush::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisGradientBrush);


}

