////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisSelector.h"
#include "NoesisListBox.generated.h"

UCLASS()
class NOESISGUI_API UNoesisListBox : public UNoesisSelector
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property SelectedItems
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisIList* GetSelectedItems();

	// Property SelectionMode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisSelectionMode GetSelectionMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectionMode(ENoesisSelectionMode InSelectionMode);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisPanel* GetDefaultItemsPanel();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollIntoView(class UNoesisBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SelectAll();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void UnselectAll();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

