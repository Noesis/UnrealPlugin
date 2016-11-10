////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisDependencyProperty.generated.h"

UCLASS()
class NOESISGUI_API UNoesisDependencyProperty : public UNoesisBaseComponent
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
bool CheckType(const class UNoesisBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ClearAnimation(class UNoesisDependencyObject* Obj);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisBaseComponent* GetBaseValueObject(const class UNoesisDependencyObject* Obj);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisBaseComponent* GetValueObject(const class UNoesisDependencyObject* Obj);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsReadOnly();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsSameValue(const class UNoesisDependencyObject* Obj, const class UNoesisBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsSameValue_(const class UNoesisBaseComponent* Left, const class UNoesisBaseComponent* Right);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsValidValue(const class UNoesisBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetAnimationObject(class UNoesisDependencyObject* Obj, const class UNoesisBaseComponent* Value);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

