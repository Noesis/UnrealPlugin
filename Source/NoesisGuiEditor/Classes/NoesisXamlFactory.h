////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// UnrealEd includes
#include "Factories/Factory.h"

// Generated header include
#include "NoesisXamlFactory.generated.h"

UCLASS()
class NOESISGUIEDITOR_API UNoesisXamlFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	// UFactory interface
		virtual UObject* FactoryCreateBinary(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn) override;
	// End of UFactory interface
};
