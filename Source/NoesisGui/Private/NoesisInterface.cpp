////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisInterface.h"

UNoesisInterface::UNoesisInterface(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisInterface::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	NoesisInterface = Noesis::Ptr<Noesis::Core::Interface>(InNoesisInterface);
}

void UNoesisInterface::BeginDestroy()
{
	Super::BeginDestroy();

	if (NoesisInterface)
	{
		UnbindEvents();
		NoesisInterface.Reset();
	}
}

void UNoesisInterface::BindEvents()
{
}

void UNoesisInterface::UnbindEvents()
{
}
