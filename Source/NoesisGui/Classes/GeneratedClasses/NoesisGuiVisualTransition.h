////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"
#include "NoesisGuiVisualTransition.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiVisualTransition : public UNoesisGuiDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property GeneratedDuration
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDuration GetGeneratedDuration();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGeneratedDuration(FNoesisGuiDuration InGeneratedDuration);

	// Property GeneratedEasingFunction
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiEasingFunctionBase* GetGeneratedEasingFunction();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGeneratedEasingFunction(class UNoesisGuiEasingFunctionBase* InGeneratedEasingFunction);

	// Property Storyboard
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiStoryboard* GetStoryboard();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStoryboard(class UNoesisGuiStoryboard* InStoryboard);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

