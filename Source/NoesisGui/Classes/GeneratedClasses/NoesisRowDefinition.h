////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseDefinition.h"
#include "NoesisRowDefinition.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisRowDefinition : public UNoesisBaseDefinition
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Height
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGridLength GetGridLengthHeight();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGridLengthHeight(FNoesisGridLength InHeight);

	// Property MaxHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMaxHeight();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaxHeight(float InMaxHeight);

	// Property MinHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMinHeight();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMinHeight(float InMinHeight);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

