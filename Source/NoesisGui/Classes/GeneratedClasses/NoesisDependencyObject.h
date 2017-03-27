////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisDependencyObject.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisDependencyObject : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ClearAnimation(const class UNoesisDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ClearAnimation_(const class UNoesisDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ClearLocalValue(const class UNoesisDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void CoerceValue(const class UNoesisDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void CoerceValue_(const class UNoesisDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetLocalValue(const class UNoesisDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetValueObject(const class UNoesisDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetValueProvider(const class UNoesisDependencyProperty* Dp);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool HasAnimatedProperties();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void InvalidateProperty(const class UNoesisDependencyProperty* Dp, int32 Priority);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCurrentValueObject(const class UNoesisDependencyProperty* Dp, const class UNoesisBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetExpression(const class UNoesisDependencyProperty* Dp, class UNoesisIExpression* Expression);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetValueObject(const class UNoesisDependencyProperty* Dp, const class UNoesisBaseComponent* Value);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

