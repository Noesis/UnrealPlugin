////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseSetter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseSetter::UNoesisGuiBaseSetter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseSetter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseSetter* NoesisBaseSetter = NsDynamicCast<Noesis::Gui::BaseSetter*>(InNoesisComponent);
	check(NoesisBaseSetter);

}

	void UNoesisGuiBaseSetter::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::BaseSetter* NoesisBaseSetter = NsDynamicCast<Noesis::Gui::BaseSetter*>(NoesisComponent.GetPtr());
	if (!NoesisBaseSetter)
		return;

}

