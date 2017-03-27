////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisSelector.h"
#include "NoesisComboBox.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisComboBox : public UNoesisSelector
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property IsDropDownOpen
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsDropDownOpen();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsDropDownOpen(bool InIsDropDownOpen);

	// Property IsEditable
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsEditable();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsEditable(bool InIsEditable);

	// Property IsReadOnly
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsReadOnly();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsReadOnly(bool InIsReadOnly);

	// Property MaxDropDownHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMaxDropDownHeight();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaxDropDownHeight(float InMaxDropDownHeight);

	// Property SelectionBoxItem
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetSelectionBoxItem();

	// Property SelectionBoxItemTemplate
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplate* GetSelectionBoxItemTemplate();

	// Property StaysOpenOnEdit
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetStaysOpenOnEdit();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStaysOpenOnEdit(bool InStaysOpenOnEdit);

	// Property Text
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetText();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetText(FString InText);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

