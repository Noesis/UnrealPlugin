////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseTrigger.h"
#include "NoesisTrigger.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisTrigger : public UNoesisBaseTrigger
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Property
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDependencyProperty* GetProperty();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetProperty(class UNoesisDependencyProperty* InProperty);

	// Property Setters
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseSetterCollection* GetSetters();

	// Property SourceName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSourceName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSourceName(FString InSourceName);

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

