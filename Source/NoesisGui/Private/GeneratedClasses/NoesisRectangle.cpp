////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisRectangle.h"

using namespace Noesis;
using namespace Gui;

UNoesisRectangle::UNoesisRectangle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Rectangle::StaticGetClassType();
}

void UNoesisRectangle::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(InNoesisComponent);
	check(NoesisRectangle);
}

float UNoesisRectangle::GetRadiusX()
{
	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(NoesisComponent.GetPtr());
	check(NoesisRectangle);
	return (float)NoesisRectangle->GetRadiusX();
}

void UNoesisRectangle::SetRadiusX(float InRadiusX)
{
	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(NoesisComponent.GetPtr());
	check(NoesisRectangle);
	NoesisRectangle->SetRadiusX(InRadiusX);
}

float UNoesisRectangle::GetRadiusY()
{
	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(NoesisComponent.GetPtr());
	check(NoesisRectangle);
	return (float)NoesisRectangle->GetRadiusY();
}

void UNoesisRectangle::SetRadiusY(float InRadiusY)
{
	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(NoesisComponent.GetPtr());
	check(NoesisRectangle);
	NoesisRectangle->SetRadiusY(InRadiusY);
}

void UNoesisRectangle::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(NoesisComponent.GetPtr());
	check(NoesisRectangle);


}

void UNoesisRectangle::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(NoesisComponent.GetPtr());
	check(NoesisRectangle);


}

