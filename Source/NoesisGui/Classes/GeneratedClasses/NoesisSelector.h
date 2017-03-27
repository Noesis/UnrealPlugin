////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisItemsControl.h"
#include "NoesisSelector.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisSelector : public UNoesisItemsControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property SelectedIndex
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetSelectedIndex();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectedIndex(int32 InSelectedIndex);

	// Property SelectedItem
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetSelectedItem();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectedItem(class UNoesisBaseComponent* InSelectedItem);

	// Property SelectedValue
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetSelectedValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectedValue(class UNoesisBaseComponent* InSelectedValue);

	// Property SelectedValuePath
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSelectedValuePath();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectedValuePath(FString InSelectedValuePath);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisSelectionChangedEventHandler SelectionChanged;

	void SelectionChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::SelectionChangedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::SelectionChangedEventArgs& InArgs)> SelectionChanged_Delegate;

};

