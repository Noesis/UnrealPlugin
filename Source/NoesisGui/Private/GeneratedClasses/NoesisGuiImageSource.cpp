////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiImageSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiImageSource::UNoesisGuiImageSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiImageSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(InNoesisComponent);
	check(NoesisImageSource);
}

float UNoesisGuiImageSource::GetHeight()
{
	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(NoesisComponent.GetPtr());
	check(NoesisImageSource);
	return (float)NoesisImageSource->GetHeight();
}

float UNoesisGuiImageSource::GetWidth()
{
	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(NoesisComponent.GetPtr());
	check(NoesisImageSource);
	return (float)NoesisImageSource->GetWidth();
}

void UNoesisGuiImageSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(NoesisComponent.GetPtr());
	check(NoesisImageSource)


}

void UNoesisGuiImageSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(NoesisComponent.GetPtr());
	check(NoesisImageSource)


}

