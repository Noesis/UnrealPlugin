////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiDependencyProperty.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiDependencyProperty : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FName GetName();

	// Property Size
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetSize();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CheckType(const class UNoesisGuiBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ClearAnimation(class UNoesisGuiDependencyObject* Obj);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* GetBaseValueObject(const class UNoesisGuiDependencyObject* Obj);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* GetValueObject(const class UNoesisGuiDependencyObject* Obj);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsReadOnly();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsSameValue(const class UNoesisGuiDependencyObject* Obj, const class UNoesisGuiBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsSameValue_(const class UNoesisGuiBaseComponent* Left, const class UNoesisGuiBaseComponent* Right);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsValidValue(const class UNoesisGuiBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetAnimationObject(class UNoesisGuiDependencyObject* Obj, const class UNoesisGuiBaseComponent* Value);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

