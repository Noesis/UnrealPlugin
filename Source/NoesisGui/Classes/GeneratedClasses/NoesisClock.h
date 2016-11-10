////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisClock.generated.h"

UCLASS()
class NOESISGUI_API UNoesisClock : public UNoesisBaseComponent
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
	class UNoesisClockGroup* GetParent();

	// Property Timeline
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTimeline* GetTimeline();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
ENoesisClockState GetCurrentState();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool HasControllableRoot();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisEventHandler Completed;

	void Completed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)> Completed_Delegate;

};

#pragma pop_macro("GetCurrentTime")

