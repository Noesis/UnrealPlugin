////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisHeaderedItemsControl.h"
#include "NoesisTreeViewItem.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisTreeViewItem : public UNoesisHeaderedItemsControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property IsExpanded
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsExpanded();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsExpanded(bool InIsExpanded);

	// Property IsSelected
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsSelected();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsSelected(bool InIsSelected);

	// Property IsSelectionActive
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsSelectionActive();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsSelectionActive(bool InIsSelectionActive);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Collapsed;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Expanded;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Selected;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Unselected;

	void Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Collapsed_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Expanded_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Selected_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Unselected_Delegate;

};

