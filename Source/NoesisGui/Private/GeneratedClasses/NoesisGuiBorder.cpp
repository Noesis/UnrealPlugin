////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBorder.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBorder::UNoesisGuiBorder(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBorder::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(InNoesisComponent);
	check(NoesisBorder);

}

	void UNoesisGuiBorder::BeginDestroy()
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	if (!NoesisBorder)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

