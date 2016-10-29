////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiSelector.h"
#include "NoesisGuiListBox.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiListBox : public UNoesisGuiSelector
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiPanel* GetDefaultItemsPanel();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollIntoView(class UNoesisGuiBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SelectAll();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void UnselectAll();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

