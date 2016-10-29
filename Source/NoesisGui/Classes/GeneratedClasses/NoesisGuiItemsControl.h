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

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiDependencyObject* ContainerFromElement(class UNoesisGuiDependencyObject* Element);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiPanel* GetDefaultItemsPanel();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiItemContainerGenerator* GetItemContainerGenerator();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsItemItsOwnContainer(class UNoesisGuiBaseComponent* Item);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

