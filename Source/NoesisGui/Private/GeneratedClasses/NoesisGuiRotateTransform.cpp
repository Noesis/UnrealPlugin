////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRotateTransform.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRotateTransform::UNoesisGuiRotateTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRotateTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(InNoesisComponent);
	check(NoesisRotateTransform);

}

	void UNoesisGuiRotateTransform::BeginDestroy()
{
	Noesis::Gui::RotateTransform* NoesisRotateTransform = NsDynamicCast<Noesis::Gui::RotateTransform*>(NoesisComponent.GetPtr());
	if (!NoesisRotateTransform)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

