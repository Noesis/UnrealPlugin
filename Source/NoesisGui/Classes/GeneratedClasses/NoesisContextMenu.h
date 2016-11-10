////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseMenu.h"
#include "NoesisContextMenu.generated.h"

UCLASS()
class NOESISGUI_API UNoesisContextMenu : public UNoesisBaseMenu
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property HasDropShadow
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetHasDropShadow();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHasDropShadow(bool InHasDropShadow);

	// Property HorizontalOffset
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetHorizontalOffset();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHorizontalOffset(float InHorizontalOffset);

	// Property IsOpen
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsOpen();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsOpen(bool InIsOpen);

	// Property Placement
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPlacementMode GetPlacement();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPlacement(ENoesisPlacementMode InPlacement);

	// Property PlacementRectangle
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingRect GetPlacementRectangle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPlacementRectangle(FNoesisDrawingRect InPlacementRectangle);

	// Property PlacementTarget
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisUIElement* GetPlacementTarget();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPlacementTarget(class UNoesisUIElement* InPlacementTarget);

	// Property StaysOpen
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetStaysOpen();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStaysOpen(bool InStaysOpen);

	// Property VerticalOffset
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetVerticalOffset();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVerticalOffset(float InVerticalOffset);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
UNoesisPopup* GetPopup();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Closed;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Opened;

	void Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Closed_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Opened_Delegate;

};

