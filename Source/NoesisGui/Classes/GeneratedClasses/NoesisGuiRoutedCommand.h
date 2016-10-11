////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiRoutedCommand.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiRoutedCommand : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property InputGestures
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiInputGestureCollection* GetInputGestures();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CanExecute(class UNoesisGuiBaseComponent* Param, class UNoesisGuiUIElement* Target);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Execute(class UNoesisGuiBaseComponent* Param, class UNoesisGuiUIElement* Target);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

