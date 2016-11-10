////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisVisualTransition.generated.h"

UCLASS()
class NOESISGUI_API UNoesisVisualTransition : public UNoesisDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property From
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FName GetFrom();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFrom(FName InFrom);

	// Property GeneratedDuration
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDuration GetGeneratedDuration();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGeneratedDuration(FNoesisDuration InGeneratedDuration);

	// Property GeneratedEasingFunction
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisEasingFunctionBase* GetGeneratedEasingFunction();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGeneratedEasingFunction(class UNoesisEasingFunctionBase* InGeneratedEasingFunction);

	// Property Storyboard
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisStoryboard* GetStoryboard();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStoryboard(class UNoesisStoryboard* InStoryboard);

	// Property To
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FName GetTo();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTo(FName InTo);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsDefault();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

