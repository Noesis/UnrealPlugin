////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisBitmapImage.h"

using namespace Noesis;
using namespace Gui;

UNoesisBitmapImage::UNoesisBitmapImage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BitmapImage::StaticGetClassType();
}

void UNoesisBitmapImage::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(InNoesisComponent);
	check(NoesisBitmapImage);
}

FString UNoesisBitmapImage::GetUriSource()
{
	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(NoesisComponent.GetPtr());
	check(NoesisBitmapImage);
	return NsStringToFString(NoesisBitmapImage->GetUriSource());
}

void UNoesisBitmapImage::SetUriSource(FString InUriSource)
{
	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(NoesisComponent.GetPtr());
	check(NoesisBitmapImage);
	NoesisBitmapImage->SetUriSource(StringCast<NsChar>(*InUriSource).Get());
}

void UNoesisBitmapImage::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(NoesisComponent.GetPtr());
	check(NoesisBitmapImage);


}

void UNoesisBitmapImage::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BitmapImage* NoesisBitmapImage = NsDynamicCast<Noesis::Gui::BitmapImage*>(NoesisComponent.GetPtr());
	check(NoesisBitmapImage);


}

