////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisEasingFunctionBase.h"
#include "NoesisBounceEase.generated.h"

UCLASS()
class NOESISGUI_API UNoesisBounceEase : public UNoesisEasingFunctionBase
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Bounces
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetBounces();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBounces(int32 InBounces);

	// Property Bounciness
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetBounciness();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBounciness(float InBounciness);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

