////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseTrigger.h"
#include "NoesisGuiDataTrigger.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiDataTrigger : public UNoesisGuiBaseTrigger
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Binding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseBinding* GetBinding();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBinding(class UNoesisGuiBaseBinding* InBinding);

	// Property Setters
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseSetterCollection* GetSetters();

	// Property Value
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* GetValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetValue(class UNoesisGuiBaseComponent* InValue);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

