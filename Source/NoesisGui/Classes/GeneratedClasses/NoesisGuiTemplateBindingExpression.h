////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiExpression.h"
#include "NoesisGuiTemplateBindingExpression.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTemplateBindingExpression : public UNoesisGuiExpression
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property TemplateBindingExtension
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiTemplateBindingExtension* GetTemplateBindingExtension();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* Evaluate();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiIExpression* Reapply(class UNoesisGuiDependencyObject* TargetObject, const class UNoesisGuiDependencyProperty* TargetProperty);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

