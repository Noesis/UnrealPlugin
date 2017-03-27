////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisClock.h"
#include "NoesisClockGroup.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisClockGroup : public UNoesisClock
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void Add(class UNoesisClock* Clock);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisClock* GetChild(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetChildrenCount();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

