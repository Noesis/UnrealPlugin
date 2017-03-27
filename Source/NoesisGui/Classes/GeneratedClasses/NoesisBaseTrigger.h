////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisBaseTrigger.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBaseTrigger : public UNoesisDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property EnterActions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTriggerActionCollection* GetEnterActions();

	// Property ExitActions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTriggerActionCollection* GetExitActions();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

