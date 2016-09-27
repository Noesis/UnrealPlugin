////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"
#include "NoesisGuiVisualStateGroup.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiVisualStateGroup : public UNoesisGuiDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetName();

	// Property States
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiVisualStateCollection* GetStates();

	// Property Transitions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiVisualTransitionCollection* GetTransitions();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

