////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Engine includes
#include "Engine/Blueprint.h"

// Generated header include
#include "NoesisBlueprint.generated.h"

UCLASS()
class NOESISGUI_API UNoesisBlueprint : public UBlueprint
{
	GENERATED_UCLASS_BODY()

	// UBlueprint interface
	virtual UClass* GetBlueprintClass() const override;
	virtual bool SupportedByDefaultBlueprintFactory() const override;
	// End of UBlueprint interface

	UPROPERTY(EditAnywhere, Category = "NoesisGui")
	class UNoesisXaml* BaseXaml;
};
