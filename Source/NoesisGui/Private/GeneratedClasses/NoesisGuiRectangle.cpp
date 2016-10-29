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

void UNoesisGuiRectangle::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(NoesisComponent.GetPtr());
	check(NoesisRectangle)


}

void UNoesisGuiRectangle::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Rectangle* NoesisRectangle = NsDynamicCast<Noesis::Gui::Rectangle*>(NoesisComponent.GetPtr());
	check(NoesisRectangle)


}

