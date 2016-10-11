////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSkewTransform.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSkewTransform::UNoesisGuiSkewTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSkewTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(InNoesisComponent);
	check(NoesisSkewTransform);

}

	void UNoesisGuiSkewTransform::BeginDestroy()
{
	Noesis::Gui::SkewTransform* NoesisSkewTransform = NsDynamicCast<Noesis::Gui::SkewTransform*>(NoesisComponent.GetPtr());
	if (!NoesisSkewTransform)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

