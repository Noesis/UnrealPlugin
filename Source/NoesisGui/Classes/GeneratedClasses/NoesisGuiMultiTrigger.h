////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseTrigger.h"
#include "NoesisGuiMultiTrigger.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiMultiTrigger : public UNoesisGuiBaseTrigger
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Conditions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiConditionCollection* GetConditions();

	// Property Setters
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseSetterCollection* GetSetters();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

