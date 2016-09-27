////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLineGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLineGeometry::UNoesisGuiLineGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLineGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LineGeometry* NoesisLineGeometry = NsDynamicCast<Noesis::Gui::LineGeometry*>(InNoesisComponent);
	check(NoesisLineGeometry);

}

	void UNoesisGuiLineGeometry::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::LineGeometry* NoesisLineGeometry = NsDynamicCast<Noesis::Gui::LineGeometry*>(NoesisComponent.GetPtr());
	if (!NoesisLineGeometry)
		return;

}

