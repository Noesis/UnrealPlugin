////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisImageSource.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisImageSource::UNoesisImageSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ImageSource::StaticGetClassType();
}

void UNoesisImageSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(InNoesisComponent);
	check(NoesisImageSource);
}

float UNoesisImageSource::GetHeight()
{
	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(NoesisComponent.GetPtr());
	check(NoesisImageSource);
	return (float)NoesisImageSource->GetHeight();
}

float UNoesisImageSource::GetWidth()
{
	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(NoesisComponent.GetPtr());
	check(NoesisImageSource);
	return (float)NoesisImageSource->GetWidth();
}

void UNoesisImageSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(NoesisComponent.GetPtr());
	check(NoesisImageSource);


}

void UNoesisImageSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ImageSource* NoesisImageSource = NsDynamicCast<Noesis::Gui::ImageSource*>(NoesisComponent.GetPtr());
	check(NoesisImageSource);


}

