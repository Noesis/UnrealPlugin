////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisEasingFunctionBase.h"
#include "NoesisElasticEase.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisElasticEase : public UNoesisEasingFunctionBase
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Oscillations
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetOscillations();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOscillations(int32 InOscillations);

	// Property Springiness
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetSpringiness();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSpringiness(float InSpringiness);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

