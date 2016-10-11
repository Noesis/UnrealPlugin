////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBackEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBackEase::UNoesisGuiBackEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBackEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BackEase* NoesisBackEase = NsDynamicCast<Noesis::Gui::BackEase*>(InNoesisComponent);
	check(NoesisBackEase);

}

	void UNoesisGuiBackEase::BeginDestroy()
{
	Noesis::Gui::BackEase* NoesisBackEase = NsDynamicCast<Noesis::Gui::BackEase*>(NoesisComponent.GetPtr());
	if (!NoesisBackEase)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

