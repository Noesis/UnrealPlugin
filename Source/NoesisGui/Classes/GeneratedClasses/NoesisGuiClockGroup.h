////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiClock.h"
#include "NoesisGuiClockGroup.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiClockGroup : public UNoesisGuiClock
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Add(class UNoesisGuiClock* Clock);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiClock* GetChild(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 GetChildrenCount();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

