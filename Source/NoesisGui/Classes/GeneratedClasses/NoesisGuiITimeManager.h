////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiITimeManager.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiITimeManager : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool GoToState(class UNoesisGuiFrameworkElement* Target, FName StateName);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool HasPendingAnimations();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Tick(float TimeInSeconds);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void TickPending();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void TransferTo(class UNoesisGuiITimeManager* Other);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

