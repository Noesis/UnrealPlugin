////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisControl.h"
#include "NoesisRangeBase.generated.h"

UCLASS()
class NOESISGUI_API UNoesisRangeBase : public UNoesisControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property LargeChange
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetLargeChange();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetLargeChange(float InLargeChange);

	// Property Maximum
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMaximum();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaximum(float InMaximum);

	// Property Minimum
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMinimum();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMinimum(float InMinimum);

	// Property SmallChange
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetSmallChange();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSmallChange(float InSmallChange);

	// Property Value
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetValue(float InValue);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisFloatPropertyChangedEventHandler ValueChanged;

	void ValueChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedPropertyChangedEventArgs<NsFloat32>& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedPropertyChangedEventArgs<NsFloat32>& InArgs)> ValueChanged_Delegate;

};

