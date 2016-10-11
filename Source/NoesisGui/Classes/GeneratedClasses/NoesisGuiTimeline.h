////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiAnimatable.h"
#include "NoesisGuiTimeline.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTimeline : public UNoesisGuiAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void CalculateEffectiveDurations();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisGuiDuration GetNaturalDuration(class UNoesisGuiClock* Clock);

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTimelineEventHandler Completed;

	void Completed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TimelineEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TimelineEventArgs& InArgs)> Completed_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

