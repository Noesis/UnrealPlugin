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

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

