////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiExpression.h"
#include "NoesisGuiBaseBindingExpression.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBaseBindingExpression : public UNoesisGuiExpression
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ParentBindingBase
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseBinding* GetParentBindingBase();

	// Property Target
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiDependencyObject* GetTarget();

	// Property TargetProperty
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiDependencyProperty* GetTargetProperty();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void UpdateSource();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void UpdateTarget();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

