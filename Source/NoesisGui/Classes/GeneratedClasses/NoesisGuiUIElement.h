////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiVisual.h"
#include "NoesisGuiUIElement.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiUIElement : public UNoesisGuiVisual
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CommandBindings
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiCommandBindingCollection* GetCommandBindings();

	// Property DesiredSize
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDrawingSize GetDesiredSize();

	// Property InputBindings
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiInputBindingCollection* GetInputBindings();

	// Property RenderSize
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDrawingSize GetRenderSize();

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler GotFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler LostFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseLeftButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseLeftButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseRightButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseRightButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseLeftButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseLeftButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseRightButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseRightButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseUp;

	void GotFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void LostFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void MouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

