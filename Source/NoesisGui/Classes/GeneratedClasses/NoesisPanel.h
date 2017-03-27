////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisPanel.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisPanel : public UNoesisFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Background
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetBackground();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBackground(class UNoesisBrush* InBackground);

	// Property Children
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisUIElementCollection* GetChildren();

	// Property IsItemsHost
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsItemsHost();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsItemsHost(bool InIsItemsHost);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void InvalidateZOrder();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

