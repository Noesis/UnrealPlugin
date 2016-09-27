////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Engine includes
#include "Engine/Blueprint.h"

// Generated header include
#include "NoesisGuiBlueprint.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBlueprint : public UBlueprint
{
	GENERATED_UCLASS_BODY()

	// UBlueprint interface
	virtual UClass* GetBlueprintClass() const override;
	virtual bool SupportedByDefaultBlueprintFactory() const override;
	// End of UBlueprint interface

	UPROPERTY(Category = NoesisGui, EditAnywhere)
	class UNoesisGuiXaml* BaseXaml;
};
