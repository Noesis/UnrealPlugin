////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseButton.h"
#include "NoesisGridViewColumnHeader.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisGridViewColumnHeader : public UNoesisBaseButton
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Column
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGridViewColumn* GetColumn();

	// Property Role
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisGridViewColumnHeaderRole GetRole();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

