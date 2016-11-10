////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisVisualStateGroup.generated.h"

UCLASS()
class NOESISGUI_API UNoesisVisualStateGroup : public UNoesisDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetName();

	// Property States
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisVisualStateCollection* GetStates();

	// Property Transitions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisVisualTransitionCollection* GetTransitions();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisVisualState* FindState(FName Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisVisualState* GetCurrentState(class UNoesisFrameworkElement* Fe);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void UpdateAnimations(class UNoesisFrameworkElement* Fe, class UNoesisStoryboard* Storyboard1, class UNoesisStoryboard* Storyboard2);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

