////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisBaseComponent.h"

UNoesisBaseComponent::UNoesisBaseComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBaseComponent::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	NoesisComponent = Noesis::Ptr<Noesis::Core::BaseComponent>(InNoesisComponent);
}

void UNoesisBaseComponent::BeginDestroy()
{
	Super::BeginDestroy();

	if (NoesisComponent)
	{
		UnbindEvents();
		NoesisComponent.Reset();
	}
}

void UNoesisBaseComponent::BindEvents()
{
}

void UNoesisBaseComponent::UnbindEvents()
{
}
