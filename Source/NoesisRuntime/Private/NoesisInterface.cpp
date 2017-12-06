////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisInterface.h"

UNoesisInterface::UNoesisInterface(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisInterface::SetNoesisInterface(Noesis::Interface* InNoesisInterface)
{
	NoesisInterface = Noesis::Ptr<Noesis::Interface>(InNoesisInterface);
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
