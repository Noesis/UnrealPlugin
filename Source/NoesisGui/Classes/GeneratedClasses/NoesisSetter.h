////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseSetter.h"
#include "NoesisSetter.generated.h"

UCLASS()
class NOESISGUI_API UNoesisSetter : public UNoesisBaseSetter
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Property
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDependencyProperty* GetProperty();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetProperty(class UNoesisDependencyProperty* InProperty);

	// Property TargetName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetTargetName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTargetName(FString InTargetName);

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

