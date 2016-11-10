////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseButton.h"
#include "NoesisRepeatButton.generated.h"

UCLASS()
class NOESISGUI_API UNoesisRepeatButton : public UNoesisBaseButton
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

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

