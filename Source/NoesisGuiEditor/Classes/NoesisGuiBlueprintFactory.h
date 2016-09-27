////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// UnrealEd includes
#include "Factories/Factory.h"

// Generated header include
#include "NoesisGuiBlueprintFactory.generated.h"

UCLASS()
class NOESISGUIEDITOR_API UNoesisGuiBlueprintFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = NoesisGuiBlueprintFactory, meta = (AllowAbstract = ""))
	TSubclassOf<class UNoesisGuiInstance> ParentClass;

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	// End of UFactory interface
};
