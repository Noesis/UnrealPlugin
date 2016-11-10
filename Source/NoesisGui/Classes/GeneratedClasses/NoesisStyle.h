////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisStyle.generated.h"

UCLASS()
class NOESISGUI_API UNoesisStyle : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property BasedOn
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisStyle* GetBasedOn();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBasedOn(class UNoesisStyle* InBasedOn);

	// Property Resources
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisResourceDictionary* GetResources();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetResources(class UNoesisResourceDictionary* InResources);

	// Property Setters
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseSetterCollection* GetSetters();

	// Property TargetType
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisResourceKeyType* GetTargetType();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTargetType(class UNoesisResourceKeyType* InTargetType);

	// Property Triggers
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTriggerCollection* GetTriggers();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

