////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiBaseComponent.h"

UNoesisGuiBaseComponent::UNoesisGuiBaseComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseComponent::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	NoesisComponent = Noesis::Ptr<Noesis::Core::BaseComponent>(InNoesisComponent);
}
