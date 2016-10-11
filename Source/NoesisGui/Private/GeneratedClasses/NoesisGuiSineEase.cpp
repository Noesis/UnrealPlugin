////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSineEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSineEase::UNoesisGuiSineEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSineEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SineEase* NoesisSineEase = NsDynamicCast<Noesis::Gui::SineEase*>(InNoesisComponent);
	check(NoesisSineEase);

}

	void UNoesisGuiSineEase::BeginDestroy()
{
	Noesis::Gui::SineEase* NoesisSineEase = NsDynamicCast<Noesis::Gui::SineEase*>(NoesisComponent.GetPtr());
	if (!NoesisSineEase)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

