////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisITimeManager.generated.h"

UCLASS()
class NOESISGUI_API UNoesisITimeManager : public UNoesisInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool GoToState(class UNoesisFrameworkElement* Target, FName StateName);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool HasPendingAnimations();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Tick(float TimeInSeconds);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void TickPending();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void TransferTo(class UNoesisITimeManager* Other);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

