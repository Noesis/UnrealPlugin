////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiImageBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiImageBrush::UNoesisGuiImageBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiImageBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ImageBrush* NoesisImageBrush = NsDynamicCast<Noesis::Gui::ImageBrush*>(InNoesisComponent);
	check(NoesisImageBrush);

}

	void UNoesisGuiImageBrush::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ImageBrush* NoesisImageBrush = NsDynamicCast<Noesis::Gui::ImageBrush*>(NoesisComponent.GetPtr());
	if (!NoesisImageBrush)
		return;

}

