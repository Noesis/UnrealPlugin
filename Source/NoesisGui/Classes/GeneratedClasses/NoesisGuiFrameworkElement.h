////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiUIElement.h"
#include "NoesisGuiFrameworkElement.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiFrameworkElement : public UNoesisGuiUIElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Parent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiFrameworkElement* GetParent();

	// Property Resources
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiResourceDictionary* GetResources();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetResources(class UNoesisGuiResourceDictionary* InResources);

	// Property TemplatedParent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiFrameworkElement* GetTemplatedParent();

	// Property Triggers
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiTriggerCollection* GetTriggers();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ApplyFrameworkTemplate(class UNoesisGuiFrameworkTemplate* FrameworkTemplate, class UNoesisGuiBaseComponent* DataContext);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void BringIntoView();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void BringIntoView_(FNoesisGuiDrawingRect TargetRectangle);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFrameworkElement* Clone(class UNoesisGuiFrameworkElement* Parent, class UNoesisGuiFrameworkElement* TemplatedParent, class UNoesisGuiFrameworkTemplate* Template_);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* FindName(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* FindResource(class UNoesisGuiIResourceKey* Key);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseExpression* GetBindingExpression(const class UNoesisGuiDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFrameworkTemplate* GetFrameworkTemplate();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFrameworkElement* GetParentOrTemplatedParent();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFrameworkElement* GetStateGroupsRoot();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* GetTemplateChild(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFrameworkElement* GetTemplateRoot();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiITimeManager* GetTimeManager();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsLoaded();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseExpression* SetBinding(const class UNoesisGuiDependencyProperty* Dp, class UNoesisGuiBaseBinding* Binding);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseExpression* SetBinding_(const class UNoesisGuiDependencyProperty* Dp, FString Path);

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiContextMenuEventHandler ContextMenuClosing;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiContextMenuEventHandler ContextMenuOpening;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler DataContextChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiEventHandler Initialized;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler Loaded;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiSizeChangedEventHandler SizeChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiToolTipEventHandler ToolTipClosing;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiToolTipEventHandler ToolTipOpening;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler Unloaded;

	void ContextMenuClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs);

	void ContextMenuOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs);

	void DataContextChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void Initialized_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs);

	void Loaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void SizeChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::SizeChangedEventArgs& InArgs);

	void ToolTipClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs);

	void ToolTipOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs);

	void Unloaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)> ContextMenuClosing_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)> ContextMenuOpening_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> DataContextChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)> Initialized_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Loaded_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::SizeChangedEventArgs& InArgs)> SizeChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)> ToolTipClosing_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)> ToolTipOpening_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Unloaded_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

