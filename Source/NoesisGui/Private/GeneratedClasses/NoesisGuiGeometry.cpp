////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGeometry::UNoesisGuiGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(InNoesisComponent);
	check(NoesisGeometry);

}

FNoesisGuiDrawingRect UNoesisGuiGeometry::GetBounds()
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	return FNoesisGuiDrawingRect(NoesisGeometry->GetBounds().x, NoesisGeometry->GetBounds().y, NoesisGeometry->GetBounds().width, NoesisGeometry->GetBounds().height);
}

	void UNoesisGuiGeometry::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	if (!NoesisGeometry)
		return;

}

