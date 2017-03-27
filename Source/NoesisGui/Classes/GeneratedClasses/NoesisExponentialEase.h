////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisEasingFunctionBase.h"
#include "NoesisExponentialEase.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisExponentialEase : public UNoesisEasingFunctionBase
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Exponent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetExponent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetExponent(float InExponent);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

