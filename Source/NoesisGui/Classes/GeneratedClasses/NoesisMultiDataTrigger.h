////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseTrigger.h"
#include "NoesisMultiDataTrigger.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisMultiDataTrigger : public UNoesisBaseTrigger
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Conditions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisConditionCollection* GetConditions();

	// Property Setters
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseSetterCollection* GetSetters();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

