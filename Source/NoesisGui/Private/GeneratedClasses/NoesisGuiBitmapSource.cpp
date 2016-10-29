////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBitmapSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBitmapSource::UNoesisGuiBitmapSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBitmapSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(InNoesisComponent);
	check(NoesisBitmapSource);
}

float UNoesisGuiBitmapSource::GetDpiX()
{
	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);
	return (float)NoesisBitmapSource->GetDpiX();
}

float UNoesisGuiBitmapSource::GetDpiY()
{
	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);
	return (float)NoesisBitmapSource->GetDpiY();
}

int32 UNoesisGuiBitmapSource::GetPixelHeight()
{
	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);
	return NoesisBitmapSource->GetPixelHeight();
}

int32 UNoesisGuiBitmapSource::GetPixelWidth()
{
	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource);
	return NoesisBitmapSource->GetPixelWidth();
}

void UNoesisGuiBitmapSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource)


}

void UNoesisGuiBitmapSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BitmapSource* NoesisBitmapSource = NsDynamicCast<Noesis::Gui::BitmapSource*>(NoesisComponent.GetPtr());
	check(NoesisBitmapSource)


}

