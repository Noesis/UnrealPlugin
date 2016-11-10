////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisTickBar.generated.h"

UCLASS()
class NOESISGUI_API UNoesisTickBar : public UNoesisFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Fill
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetFill();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFill(class UNoesisBrush* InFill);

	// Property IsDirectionReversed
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsDirectionReversed();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsDirectionReversed(bool InIsDirectionReversed);

	// Property IsSelectionRangeEnabled
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsSelectionRangeEnabled();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsSelectionRangeEnabled(bool InIsSelectionRangeEnabled);

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

	// Property Placement
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisTickBarPlacement GetPlacement();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPlacement(ENoesisTickBarPlacement InPlacement);

	// Property ReservedSpace
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetReservedSpace();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetReservedSpace(float InReservedSpace);

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

