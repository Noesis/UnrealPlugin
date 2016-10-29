////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBitmapImage.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBitmapImage::UNoesisGuiBitmapImage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBitmapImage::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(InNoesisComponent);
	check(NoesisBitmapImage);
}

FString UNoesisGuiBitmapImage::GetUriSource()
{
	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(NoesisComponent.GetPtr());
	check(NoesisBitmapImage);
	return NsStringToFString(NoesisBitmapImage->GetUriSource());
}

void UNoesisGuiBitmapImage::SetUriSource(FString InUriSource)
{
	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(NoesisComponent.GetPtr());
	check(NoesisBitmapImage);
	NoesisBitmapImage->SetUriSource(StringCast<NsChar>(*InUriSource).Get());
}

void UNoesisGuiBitmapImage::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(NoesisComponent.GetPtr());
	check(NoesisBitmapImage)


}

void UNoesisGuiBitmapImage::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(NoesisComponent.GetPtr());
	check(NoesisBitmapImage)


}

