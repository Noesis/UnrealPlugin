////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTimeline.h"
#include "NoesisAnimationTimeline.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisAnimationTimeline : public UNoesisTimeline
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property IsAdditive
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsAdditive();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsAdditive(bool InIsAdditive);

	// Property IsCumulative
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsCumulative();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsCumulative(bool InIsCumulative);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisAnimationTimeline* CreateTransitionFrom();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetAnimatedValue(class UNoesisBaseComponent* DefaultOrigin, class UNoesisBaseComponent* DefaultDestination, class UNoesisAnimationClock* Clock);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void Start(class UNoesisDependencyObject* Target, const class UNoesisDependencyProperty* Dp, class UNoesisITimeManager* TimeManager, ENoesisHandoffBehavior Handoff);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

