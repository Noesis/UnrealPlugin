////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiInterface.h"

UNoesisGuiInterface::UNoesisGuiInterface(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInterface::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	NoesisInterface = Noesis::Ptr<Noesis::Core::Interface>(InNoesisInterface);
}

void UNoesisGuiInterface::BeginDestroy()
{
	Super::BeginDestroy();

	if (NoesisInterface)
	{
		UnbindEvents();
		NoesisInterface.Reset();
	}
}

void UNoesisGuiInterface::BindEvents()
{
}

void UNoesisGuiInterface::UnbindEvents()
{
}
