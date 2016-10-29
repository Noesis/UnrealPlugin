////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiStyle.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiStyle : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property BasedOn
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiStyle* GetBasedOn();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBasedOn(class UNoesisGuiStyle* InBasedOn);

	// Property Resources
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiResourceDictionary* GetResources();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetResources(class UNoesisGuiResourceDictionary* InResources);

	// Property Setters
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseSetterCollection* GetSetters();

	// Property TargetType
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiResourceKeyType* GetTargetType();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTargetType(class UNoesisGuiResourceKeyType* InTargetType);

	// Property Triggers
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiTriggerCollection* GetTriggers();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

