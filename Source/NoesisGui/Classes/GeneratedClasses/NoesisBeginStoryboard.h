////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTriggerAction.h"
#include "NoesisBeginStoryboard.generated.h"

UCLASS()
class NOESISGUI_API UNoesisBeginStoryboard : public UNoesisTriggerAction
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property HandoffBehavior
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisHandoffBehavior GetHandoffBehavior();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHandoffBehavior(ENoesisHandoffBehavior InHandoffBehavior);

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetName(FString InName);

	// Property Storyboard
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisStoryboard* GetStoryboard();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStoryboard(class UNoesisStoryboard* InStoryboard);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

