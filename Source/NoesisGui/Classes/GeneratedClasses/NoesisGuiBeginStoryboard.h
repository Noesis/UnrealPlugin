////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiTriggerAction.h"
#include "NoesisGuiBeginStoryboard.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBeginStoryboard : public UNoesisGuiTriggerAction
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property HandoffBehavior
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisGuiHandoffBehavior GetHandoffBehavior();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHandoffBehavior(ENoesisGuiHandoffBehavior InHandoffBehavior);

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetName(FString InName);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

