////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseTextBox.h"
#include "NoesisGuiTextBox.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTextBox : public UNoesisGuiBaseTextBox
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property SelectedText
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSelectedText();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectedText(FString InSelectedText);

	// Property SelectionLength
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetSelectionLength();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectionLength(int32 InSelectionLength);

	// Property SelectionStart
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetSelectionStart();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectionStart(int32 InSelectionStart);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 GetCaretIndex();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SelectAll();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

