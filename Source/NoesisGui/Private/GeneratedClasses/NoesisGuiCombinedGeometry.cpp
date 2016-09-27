////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCombinedGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCombinedGeometry::UNoesisGuiCombinedGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCombinedGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(InNoesisComponent);
	check(NoesisCombinedGeometry);

}

	void UNoesisGuiCombinedGeometry::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(NoesisComponent.GetPtr());
	if (!NoesisCombinedGeometry)
		return;

}

