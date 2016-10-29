////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiTimeline.h"
#include "NoesisGuiAnimationTimeline.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiAnimationTimeline : public UNoesisGuiTimeline
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiAnimationTimeline* CreateTransitionFrom();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* GetAnimatedValue(class UNoesisGuiBaseComponent* DefaultOrigin, class UNoesisGuiBaseComponent* DefaultDestination, class UNoesisGuiAnimationClock* Clock);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Start(class UNoesisGuiDependencyObject* Target, const class UNoesisGuiDependencyProperty* Dp, class UNoesisGuiITimeManager* TimeManager, ENoesisGuiHandoffBehavior Handoff);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

