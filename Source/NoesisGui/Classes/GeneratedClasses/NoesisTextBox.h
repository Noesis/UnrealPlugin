////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseTextBox.h"
#include "NoesisTextBox.generated.h"

UCLASS()
class NOESISGUI_API UNoesisTextBox : public UNoesisBaseTextBox
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property MaxLength
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetMaxLength();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaxLength(int32 InMaxLength);

	// Property MaxLines
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetMaxLines();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaxLines(int32 InMaxLines);

	// Property MinLines
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetMinLines();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMinLines(int32 InMinLines);

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

	// Property Text
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetText();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetText(FString InText);

	// Property TextAlignment
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisTextAlignment GetTextAlignment();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTextAlignment(ENoesisTextAlignment InTextAlignment);

	// Property TextWrapping
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisTextWrapping GetTextWrapping();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTextWrapping(ENoesisTextWrapping InTextWrapping);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 GetCaretIndex();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SelectAll();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

