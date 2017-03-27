////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisTrack.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisTrack : public UNoesisFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property DecreaseRepeatButton
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisRepeatButton* GetDecreaseRepeatButton();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDecreaseRepeatButton(class UNoesisRepeatButton* InDecreaseRepeatButton);

	// Property IncreaseRepeatButton
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisRepeatButton* GetIncreaseRepeatButton();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIncreaseRepeatButton(class UNoesisRepeatButton* InIncreaseRepeatButton);

	// Property IsDirectionReversed
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsDirectionReversed();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsDirectionReversed(bool InIsDirectionReversed);

	// Property Maximum
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMaximum();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaximum(float InMaximum);

	// Property Minimum
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMinimum();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMinimum(float InMinimum);

	// Property Orientation
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisOrientation GetOrientation();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOrientation(ENoesisOrientation InOrientation);

	// Property Thumb
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisThumb* GetThumb();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetThumb(class UNoesisThumb* InThumb);

	// Property Value
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetValue(float InValue);

	// Property ViewportSize
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetViewportSize();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetViewportSize(float InViewportSize);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float ValueFromDistance(float Horizontal, float Vertical);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float ValueFromPoint(FNoesisDrawingPoint Point);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

