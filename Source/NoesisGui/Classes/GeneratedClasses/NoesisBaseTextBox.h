////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisControl.h"
#include "NoesisBaseTextBox.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBaseTextBox : public UNoesisControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property AcceptsReturn
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetAcceptsReturn();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAcceptsReturn(bool InAcceptsReturn);

	// Property AcceptsTab
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetAcceptsTab();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAcceptsTab(bool InAcceptsTab);

	// Property CaretBrush
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetCaretBrush();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCaretBrush(class UNoesisBrush* InCaretBrush);

	// Property HorizontalScrollBarVisibility
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisScrollBarVisibility GetHorizontalScrollBarVisibility();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHorizontalScrollBarVisibility(ENoesisScrollBarVisibility InHorizontalScrollBarVisibility);

	// Property IsReadOnly
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsReadOnly();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsReadOnly(bool InIsReadOnly);

	// Property IsSelectionActive
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsSelectionActive();

	// Property SelectionBrush
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetSelectionBrush();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectionBrush(class UNoesisBrush* InSelectionBrush);

	// Property SelectionOpacity
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetSelectionOpacity();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectionOpacity(float InSelectionOpacity);

	// Property VerticalScrollBarVisibility
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisScrollBarVisibility GetVerticalScrollBarVisibility();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVerticalScrollBarVisibility(ENoesisScrollBarVisibility InVerticalScrollBarVisibility);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler SelectionChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler TextChanged;

	void SelectionChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void TextChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> SelectionChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> TextChanged_Delegate;

};

