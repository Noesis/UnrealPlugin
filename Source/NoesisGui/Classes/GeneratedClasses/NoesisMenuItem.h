////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisHeaderedItemsControl.h"
#include "NoesisMenuItem.generated.h"

UCLASS()
class NOESISGUI_API UNoesisMenuItem : public UNoesisHeaderedItemsControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Command
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisICommand* GetCommand();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommand(class UNoesisICommand* InCommand);

	// Property CommandParameter
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetCommandParameter();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommandParameter(class UNoesisBaseComponent* InCommandParameter);

	// Property CommandTarget
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisUIElement* GetCommandTarget();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommandTarget(class UNoesisUIElement* InCommandTarget);

	// Property Icon
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetIcon();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIcon(class UNoesisBaseComponent* InIcon);

	// Property InputGestureText
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetInputGestureText();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetInputGestureText(FString InInputGestureText);

	// Property IsCheckable
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsCheckable();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsCheckable(bool InIsCheckable);

	// Property IsChecked
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsChecked();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsChecked(bool InIsChecked);

	// Property IsHighlighted
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsHighlighted();

	// Property IsPressed
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsPressed();

	// Property IsSubmenuOpen
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsSubmenuOpen();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsSubmenuOpen(bool InIsSubmenuOpen);

	// Property Role
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisMenuItemRole GetRole();

	// Property StaysOpenOnClick
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetStaysOpenOnClick();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStaysOpenOnClick(bool InStaysOpenOnClick);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Checked;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Click;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler SubmenuClosed;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler SubmenuOpened;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Unchecked;

	void Checked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void SubmenuClosed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void SubmenuOpened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Checked_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Click_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> SubmenuClosed_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> SubmenuOpened_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Unchecked_Delegate;

};

