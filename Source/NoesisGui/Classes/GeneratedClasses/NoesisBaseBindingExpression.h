////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisExpression.h"
#include "NoesisBaseBindingExpression.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBaseBindingExpression : public UNoesisExpression
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ParentBindingBase
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseBinding* GetParentBindingBase();

	// Property Target
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDependencyObject* GetTarget();

	// Property TargetProperty
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDependencyProperty* GetTargetProperty();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void UpdateSource();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void UpdateTarget();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

