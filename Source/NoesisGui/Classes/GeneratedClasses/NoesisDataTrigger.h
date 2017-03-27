////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseTrigger.h"
#include "NoesisDataTrigger.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisDataTrigger : public UNoesisBaseTrigger
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Binding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseBinding* GetBinding();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBinding(class UNoesisBaseBinding* InBinding);

	// Property Setters
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseSetterCollection* GetSetters();

	// Property Value
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetValue(class UNoesisBaseComponent* InValue);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

