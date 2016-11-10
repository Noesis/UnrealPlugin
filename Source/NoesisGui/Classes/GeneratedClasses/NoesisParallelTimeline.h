////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTimelineGroup.h"
#include "NoesisParallelTimeline.generated.h"

UCLASS()
class NOESISGUI_API UNoesisParallelTimeline : public UNoesisTimelineGroup
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property SlipBehavior
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisSlipBehavior GetSlipBehavior();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSlipBehavior(ENoesisSlipBehavior InSlipBehavior);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisDuration GetNaturalDuration(class UNoesisClock* Clock);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

