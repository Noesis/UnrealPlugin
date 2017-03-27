////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisFreezable.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisFreezable : public UNoesisDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool CanFreeze();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFreezable* Clone();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFreezable* CloneCurrentValue();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void Freeze();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFreezable* GetAsFrozen();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFreezable* GetCurrentValueAsFrozen();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsFrozen();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

