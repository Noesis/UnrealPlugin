////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiControl.h"
#include "NoesisGuiItemsControl.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiItemsControl : public UNoesisGuiControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Items
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiItemCollection* GetItems();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

