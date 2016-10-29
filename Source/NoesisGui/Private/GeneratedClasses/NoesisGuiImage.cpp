////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiImage.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiImage::UNoesisGuiImage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiImage::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Image* NoesisImage = NsDynamicCast<Noesis::Gui::Image*>(InNoesisComponent);
	check(NoesisImage);
}

void UNoesisGuiImage::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Image* NoesisImage = NsDynamicCast<Noesis::Gui::Image*>(NoesisComponent.GetPtr());
	check(NoesisImage)


}

void UNoesisGuiImage::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Image* NoesisImage = NsDynamicCast<Noesis::Gui::Image*>(NoesisComponent.GetPtr());
	check(NoesisImage)


}

