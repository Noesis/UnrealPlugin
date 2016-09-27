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

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler Loaded;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler Unloaded;

	void Loaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Unloaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

