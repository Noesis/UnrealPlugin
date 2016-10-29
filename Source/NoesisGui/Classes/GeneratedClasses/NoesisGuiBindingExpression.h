////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseBindingExpression.h"
#include "NoesisGuiBindingExpression.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBindingExpression : public UNoesisGuiBaseBindingExpression
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ParentBinding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBinding* GetParentBinding();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* Evaluate();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiIExpression* Reapply(class UNoesisGuiDependencyObject* TargetObject, const class UNoesisGuiDependencyProperty* TargetProperty);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

