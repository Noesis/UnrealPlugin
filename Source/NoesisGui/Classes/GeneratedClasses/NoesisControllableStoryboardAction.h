////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTriggerAction.h"
#include "NoesisControllableStoryboardAction.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisControllableStoryboardAction : public UNoesisTriggerAction
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property BeginStoryboardName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetBeginStoryboardName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBeginStoryboardName(FString InBeginStoryboardName);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

