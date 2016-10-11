////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiDependencyObject.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiDependencyObject : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ClearAnimation(const class UNoesisGuiDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ClearAnimation_(const class UNoesisGuiDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ClearLocalValue(const class UNoesisGuiDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void CoerceValue(const class UNoesisGuiDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void CoerceValue_(const class UNoesisGuiDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* GetLocalValue(const class UNoesisGuiDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* GetValueObject(const class UNoesisGuiDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 GetValueProvider(const class UNoesisGuiDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool HasAnimatedProperties();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void InvalidateProperty(const class UNoesisGuiDependencyProperty* Dp, int32 Priority);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetCurrentValueObject(const class UNoesisGuiDependencyProperty* Dp, const class UNoesisGuiBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetExpression(const class UNoesisGuiDependencyProperty* Dp, class UNoesisGuiIExpression* Expression);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetValueObject(const class UNoesisGuiDependencyProperty* Dp, const class UNoesisGuiBaseComponent* Value);

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler DependencyPropertyChanged;

	void DependencyPropertyChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> DependencyPropertyChanged_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

