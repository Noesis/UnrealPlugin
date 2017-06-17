////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseDefinition.h"
#include "NoesisColumnDefinition.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisColumnDefinition : public UNoesisBaseDefinition
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property MaxWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMaxWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaxWidth(float InMaxWidth);

	// Property MinWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMinWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMinWidth(float InMinWidth);

	// Property Width
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGridLength GetGridLengthWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGridLengthWidth(FNoesisGridLength InWidth);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

