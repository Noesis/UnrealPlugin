////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiScrollViewer.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiScrollViewer::UNoesisGuiScrollViewer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiScrollViewer::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(InNoesisComponent);
	check(NoesisScrollViewer);

}

	void UNoesisGuiScrollViewer::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	if (!NoesisScrollViewer)
		return;

}

