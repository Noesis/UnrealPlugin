////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisUIElement.h"
#include "NoesisFrameworkElement.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisFrameworkElement : public UNoesisUIElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ActualHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetActualHeight();

	// Property ActualWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetActualWidth();

	// Property ContextMenu
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisContextMenu* GetContextMenu();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetContextMenu(class UNoesisContextMenu* InContextMenu);

	// Property DataContext
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetDataContext();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDataContext(class UNoesisBaseComponent* InDataContext);

	// Property DefaultStyleKey
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisResourceKeyType* GetDefaultStyleKey();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDefaultStyleKey(class UNoesisResourceKeyType* InDefaultStyleKey);

	// Property FocusVisualStyle
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisStyle* GetFocusVisualStyle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFocusVisualStyle(class UNoesisStyle* InFocusVisualStyle);

	// Property Height
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetHeight();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHeight(float InHeight);

	// Property HorizontalAlignment
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisHorizontalAlignment GetHorizontalAlignment();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHorizontalAlignment(ENoesisHorizontalAlignment InHorizontalAlignment);

	// Property LayoutTransform
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTransform* GetLayoutTransform();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetLayoutTransform(class UNoesisTransform* InLayoutTransform);

	// Property Margin
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingThickness GetMargin();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMargin(FNoesisDrawingThickness InMargin);

	// Property MaxHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMaxHeight();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaxHeight(float InMaxHeight);

	// Property MaxWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMaxWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaxWidth(float InMaxWidth);

	// Property MinHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMinHeight();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMinHeight(float InMinHeight);

	// Property MinWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMinWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMinWidth(float InMinWidth);

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetName(FString InName);

	// Property OverridesDefaultStyle
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetOverridesDefaultStyle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOverridesDefaultStyle(bool InOverridesDefaultStyle);

	// Property Parent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFrameworkElement* GetParent();

	// Property Resources
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisResourceDictionary* GetResources();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetResources(class UNoesisResourceDictionary* InResources);

	// Property Style
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisStyle* GetStyle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStyle(class UNoesisStyle* InStyle);

	// Property Tag
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetTag();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTag(class UNoesisBaseComponent* InTag);

	// Property TemplatedParent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFrameworkElement* GetTemplatedParent();

	// Property ToolTip
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetToolTip();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetToolTip(class UNoesisBaseComponent* InToolTip);

	// Property Triggers
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTriggerCollection* GetTriggers();

	// Property UseLayoutRounding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetUseLayoutRounding();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetUseLayoutRounding(bool InUseLayoutRounding);

	// Property VerticalAlignment
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisVerticalAlignment GetVerticalAlignment();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVerticalAlignment(ENoesisVerticalAlignment InVerticalAlignment);

	// Property Width
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetWidth(float InWidth);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ApplyFrameworkTemplate(class UNoesisFrameworkTemplate* FrameworkTemplate, class UNoesisBaseComponent* DataContext);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void BringIntoView();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void BringIntoView_(FNoesisDrawingRect TargetRectangle);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFrameworkElement* Clone(class UNoesisFrameworkElement* Parent, class UNoesisFrameworkElement* TemplatedParent, class UNoesisFrameworkTemplate* Template_);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void Connect(class UNoesisBaseComponent* Source, FString EventName, FString HandlerName);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* FindName(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* FindResource(class UNoesisIResourceKey* Key);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFrameworkTemplate* GetFrameworkTemplate();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFrameworkElement* GetParentOrTemplatedParent();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFrameworkElement* GetStateGroupsRoot();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetTemplateChild(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFrameworkElement* GetTemplateRoot();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisITimeManager* GetTimeManager();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsLoaded();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisContextMenuEventHandler ContextMenuClosing;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisContextMenuEventHandler ContextMenuOpening;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler DataContextChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisEventHandler Initialized;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Loaded;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRequestBringIntoViewEventHandler RequestBringIntoView;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisSizeChangedEventHandler SizeChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisToolTipEventHandler ToolTipClosing;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisToolTipEventHandler ToolTipOpening;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Unloaded;

	void ContextMenuClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs);

	void ContextMenuOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs);

	void DataContextChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void Initialized_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs);

	void Loaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void RequestBringIntoView_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RequestBringIntoViewEventArgs& InArgs);

	void SizeChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::SizeChangedEventArgs& InArgs);

	void ToolTipClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs);

	void ToolTipOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs);

	void Unloaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)> ContextMenuClosing_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)> ContextMenuOpening_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> DataContextChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)> Initialized_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Loaded_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RequestBringIntoViewEventArgs& InArgs)> RequestBringIntoView_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::SizeChangedEventArgs& InArgs)> SizeChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)> ToolTipClosing_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)> ToolTipOpening_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Unloaded_Delegate;

};

