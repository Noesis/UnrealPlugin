////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRectangleGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRectangleGeometry::UNoesisGuiRectangleGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRectangleGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(InNoesisComponent);
	check(NoesisRectangleGeometry);

}

	void UNoesisGuiRectangleGeometry::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(NoesisComponent.GetPtr());
	if (!NoesisRectangleGeometry)
		return;

}

