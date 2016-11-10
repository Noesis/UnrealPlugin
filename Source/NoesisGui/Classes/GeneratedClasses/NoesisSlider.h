////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisRangeBase.h"
#include "NoesisSlider.generated.h"

UCLASS()
class NOESISGUI_API UNoesisSlider : public UNoesisRangeBase
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Delay
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetDelay();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDelay(int32 InDelay);

	// Property Interval
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetInterval();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetInterval(int32 InInterval);

	// Property IsDirectionReversed
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsDirectionReversed();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsDirectionReversed(bool InIsDirectionReversed);

	// Property IsMoveToPointEnabled
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsMoveToPointEnabled();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsMoveToPointEnabled(bool InIsMoveToPointEnabled);

	// Property IsSelectionRangeEnabled
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsSelectionRangeEnabled();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsSelectionRangeEnabled(bool InIsSelectionRangeEnabled);

	// Property IsSnapToTickEnabled
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsSnapToTickEnabled();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsSnapToTickEnabled(bool InIsSnapToTickEnabled);

	// Property Orientation
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisOrientation GetOrientation();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOrientation(ENoesisOrientation InOrientation);

	// Property SelectionEnd
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetSelectionEnd();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectionEnd(float InSelectionEnd);

	// Property SelectionStart
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetSelectionStart();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectionStart(float InSelectionStart);

	// Property TickFrequency
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetTickFrequency();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTickFrequency(float InTickFrequency);

	// Property TickPlacement
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisTickPlacement GetTickPlacement();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTickPlacement(ENoesisTickPlacement InTickPlacement);

	// Property Ticks
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetTicks();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTicks(FString InTicks);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

