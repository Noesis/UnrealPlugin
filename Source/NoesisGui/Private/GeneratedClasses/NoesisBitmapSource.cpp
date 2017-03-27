////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisBitmapSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisBitmapSource::UNoesisBitmapSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BitmapSource::StaticGetClassType();
}

void UNoesisBitmapSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(InNoesisComponent);
	check(NoesisBitmapSource);
}

float UNoesisBitmapSource::GetDpiX()
{
	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);
	return (float)NoesisBitmapSource->GetDpiX();
}

float UNoesisBitmapSource::GetDpiY()
{
	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);
	return (float)NoesisBitmapSource->GetDpiY();
}

int32 UNoesisBitmapSource::GetPixelHeight()
{
	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);
	return NoesisBitmapSource->GetPixelHeight();
}

int32 UNoesisBitmapSource::GetPixelWidth()
{
	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);
	return NoesisBitmapSource->GetPixelWidth();
}

void UNoesisBitmapSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);


}

void UNoesisBitmapSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);


}

