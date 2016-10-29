////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"
#include "NoesisGuiFreezable.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiFreezable : public UNoesisGuiDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CanFreeze();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFreezable* Clone();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFreezable* CloneCurrentValue();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Freeze();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFreezable* GetAsFrozen();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFreezable* GetCurrentValueAsFrozen();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsFrozen();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

