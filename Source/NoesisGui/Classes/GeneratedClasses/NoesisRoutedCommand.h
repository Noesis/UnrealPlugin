////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisRoutedCommand.generated.h"

UCLASS()
class NOESISGUI_API UNoesisRoutedCommand : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property InputGestures
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisInputGestureCollection* GetInputGestures();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CanExecute(class UNoesisBaseComponent* Param, class UNoesisUIElement* Target);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Execute(class UNoesisBaseComponent* Param, class UNoesisUIElement* Target);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

