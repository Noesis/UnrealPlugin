////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiClock.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiClock : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CurrentIteration
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetCurrentIteration();

	// Property CurrentProgress
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetCurrentProgress();

	// Property CurrentTime
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetCurrentTime();

	// Property Parent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiClockGroup* GetParent();

	// Property Timeline
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiTimeline* GetTimeline();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

#pragma pop_macro("GetCurrentTime")

