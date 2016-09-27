////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Engine includes
#include "Engine/BlueprintGeneratedClass.h"

// Generated header include
#include "NoesisGuiBlueprintGeneratedClass.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBlueprintGeneratedClass : public UBlueprintGeneratedClass
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	class UNoesisGuiXaml* BaseXaml;

	void InitInstance(class UNoesisGuiInstance* NoesisGuiInstance);
};
