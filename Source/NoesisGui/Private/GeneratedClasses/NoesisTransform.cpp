////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTransform.h"

using namespace Noesis;
using namespace Gui;

UNoesisTransform::UNoesisTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Transform* NoesisTransform = NsDynamicCast<Noesis::Gui::Transform*>(InNoesisComponent);
	check(NoesisTransform);
}

void UNoesisTransform::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Transform* NoesisTransform = NsDynamicCast<Noesis::Gui::Transform*>(NoesisComponent.GetPtr());
	check(NoesisTransform)


}

void UNoesisTransform::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Transform* NoesisTransform = NsDynamicCast<Noesis::Gui::Transform*>(NoesisComponent.GetPtr());
	check(NoesisTransform)


}

