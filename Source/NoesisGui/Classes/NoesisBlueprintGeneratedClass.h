////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Engine includes
#include "Engine/BlueprintGeneratedClass.h"

// Generated header include
#include "NoesisBlueprintGeneratedClass.generated.h"

UCLASS()
class NOESISGUI_API UNoesisBlueprintGeneratedClass : public UBlueprintGeneratedClass
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	class UNoesisXaml* BaseXaml;

	UPROPERTY()
	TArray<class UNoesisBaseComponent*> Components;

	void InitComponents(class UNoesisInstance* NoesisInstance);
};
