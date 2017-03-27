////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisIExpression.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisIExpression : public UNoesisInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* Evaluate();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisIExpression* Reapply(class UNoesisDependencyObject* TargetObject, const class UNoesisDependencyProperty* TargetProperty);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

