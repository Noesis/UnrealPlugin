////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisControl.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisControl : public UNoesisFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Background
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetBackground();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBackground(class UNoesisBrush* InBackground);

	// Property BorderBrush
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetBorderBrush();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBorderBrush(class UNoesisBrush* InBorderBrush);

	// Property BorderThickness
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingThickness GetBorderThickness();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBorderThickness(FNoesisDrawingThickness InBorderThickness);

	// Property FontFamily
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFontFamily* GetFontFamily();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFontFamily(class UNoesisFontFamily* InFontFamily);

	// Property FontSize
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetFontSize();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFontSize(float InFontSize);

	// Property FontStretch
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisFontStretch GetFontStretch();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFontStretch(ENoesisFontStretch InFontStretch);

	// Property FontStyle
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisFontStyle GetFontStyle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFontStyle(ENoesisFontStyle InFontStyle);

	// Property FontWeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisFontWeight GetFontWeight();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFontWeight(ENoesisFontWeight InFontWeight);

	// Property Foreground
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetForeground();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetForeground(class UNoesisBrush* InForeground);

	// Property HorizontalContentAlignment
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisHorizontalAlignment GetHorizontalContentAlignment();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHorizontalContentAlignment(ENoesisHorizontalAlignment InHorizontalContentAlignment);

	// Property IsTabStop
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsTabStop();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsTabStop(bool InIsTabStop);

	// Property Padding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingThickness GetPadding();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPadding(FNoesisDrawingThickness InPadding);

	// Property TabIndex
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetTabIndex();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTabIndex(int32 InTabIndex);

	// Property Template
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisControlTemplate* GetTemplate();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTemplate(class UNoesisControlTemplate* InTemplate);

	// Property VerticalContentAlignment
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisVerticalAlignment GetVerticalContentAlignment();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVerticalContentAlignment(ENoesisVerticalAlignment InVerticalContentAlignment);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler MouseDoubleClick;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler PreviewMouseDoubleClick;

	void MouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> MouseDoubleClick_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> PreviewMouseDoubleClick_Delegate;

};

