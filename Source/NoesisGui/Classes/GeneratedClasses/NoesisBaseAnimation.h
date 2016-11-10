////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisAnimationTimeline.h"
#include "NoesisBaseAnimation.generated.h"

UCLASS()
class NOESISGUI_API UNoesisBaseAnimation : public UNoesisAnimationTimeline
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property EasingFunction
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisEasingFunctionBase* GetEasingFunction();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetEasingFunction(class UNoesisEasingFunctionBase* InEasingFunction);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

