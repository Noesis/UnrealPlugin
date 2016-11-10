////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// UnrealEd includes
#include "Factories/Factory.h"

// Generated header include
#include "NoesisBlueprintFactory.generated.h"

UCLASS()
class NOESISGUIEDITOR_API UNoesisBlueprintFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = NoesisBlueprintFactory, meta = (AllowAbstract = ""))
	TSubclassOf<class UNoesisInstance> ParentClass;

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	// End of UFactory interface
};
