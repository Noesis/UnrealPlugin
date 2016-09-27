////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRangeBase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRangeBase::UNoesisGuiRangeBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRangeBase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(InNoesisComponent);
	check(NoesisRangeBase);

}

	void UNoesisGuiRangeBase::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::RangeBase* NoesisRangeBase = NsDynamicCast<Noesis::Gui::RangeBase*>(NoesisComponent.GetPtr());
	if (!NoesisRangeBase)
		return;

}

