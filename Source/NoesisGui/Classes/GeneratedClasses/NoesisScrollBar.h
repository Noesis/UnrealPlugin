////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisRangeBase.h"
#include "NoesisScrollBar.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisScrollBar : public UNoesisRangeBase
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Orientation
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisOrientation GetOrientation();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOrientation(ENoesisOrientation InOrientation);

	// Property Track
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTrack* GetTrack();

	// Property ViewportSize
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetViewportSize();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetViewportSize(float InViewportSize);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisScrollEventHandler Scroll;

	void Scroll_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ScrollEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ScrollEventArgs& InArgs)> Scroll_Delegate;

};

