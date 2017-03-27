////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFreezable.h"
#include "NoesisInputBinding.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisInputBinding : public UNoesisFreezable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Command
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisICommand* GetCommand();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommand(class UNoesisICommand* InCommand);

	// Property CommandParameter
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetCommandParameter();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommandParameter(class UNoesisBaseComponent* InCommandParameter);

	// Property CommandTarget
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisUIElement* GetCommandTarget();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommandTarget(class UNoesisUIElement* InCommandTarget);

	// Property Gesture
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisInputGesture* GetGesture();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGesture(class UNoesisInputGesture* InGesture);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

