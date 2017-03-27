////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisAnimatable.h"
#include "NoesisTimeline.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisTimeline : public UNoesisAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property AccelerationRatio
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetAccelerationRatio();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAccelerationRatio(float InAccelerationRatio);

	// Property AutoReverse
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetAutoReverse();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAutoReverse(bool InAutoReverse);

	// Property DecelerationRatio
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetDecelerationRatio();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDecelerationRatio(float InDecelerationRatio);

	// Property Duration
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDuration GetDuration();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDuration(FNoesisDuration InDuration);

	// Property FillBehavior
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisFillBehavior GetFillBehavior();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFillBehavior(ENoesisFillBehavior InFillBehavior);

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetName(FString InName);

	// Property RepeatBehavior
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisRepeatBehavior GetRepeatBehavior();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRepeatBehavior(FNoesisRepeatBehavior InRepeatBehavior);

	// Property SpeedRatio
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetSpeedRatio();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSpeedRatio(float InSpeedRatio);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void CalculateEffectiveDurations();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDuration GetNaturalDuration(class UNoesisClock* Clock);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTimelineEventHandler Completed;

	void Completed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TimelineEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TimelineEventArgs& InArgs)> Completed_Delegate;

};

