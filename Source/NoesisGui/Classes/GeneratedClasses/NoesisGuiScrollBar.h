////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiRangeBase.h"
#include "NoesisGuiScrollBar.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiScrollBar : public UNoesisGuiRangeBase
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Track
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiTrack* GetTrack();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiScrollEventHandler Scroll;

	void Scroll_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ScrollEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ScrollEventArgs& InArgs)> Scroll_Delegate;

};

