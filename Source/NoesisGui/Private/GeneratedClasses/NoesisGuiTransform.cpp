////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTransform.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTransform::UNoesisGuiTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Transform* NoesisTransform = NsDynamicCast<Noesis::Gui::Transform*>(InNoesisComponent);
	check(NoesisTransform);

}

	void UNoesisGuiTransform::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Transform* NoesisTransform = NsDynamicCast<Noesis::Gui::Transform*>(NoesisComponent.GetPtr());
	if (!NoesisTransform)
		return;

}

