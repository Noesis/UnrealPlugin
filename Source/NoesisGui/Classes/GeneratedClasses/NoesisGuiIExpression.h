////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIExpression.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIExpression : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* Evaluate();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
ENoesisGuiEvaluateBehavior GetEvaluateBehavior();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiIExpression* Reapply(class UNoesisGuiDependencyObject* TargetObject, const class UNoesisGuiDependencyProperty* TargetProperty);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

