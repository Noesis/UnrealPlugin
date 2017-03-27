////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisEasingFunctionBase.h"
#include "NoesisBackEase.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBackEase : public UNoesisEasingFunctionBase
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Amplitude
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetAmplitude();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAmplitude(float InAmplitude);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

