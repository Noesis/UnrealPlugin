////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRectangle.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRectangle::UNoesisGuiRectangle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRectangle::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(InNoesisComponent);
	check(NoesisRectangle);

}

	void UNoesisGuiRectangle::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(NoesisComponent.GetPtr());
	if (!NoesisRectangle)
		return;

}

