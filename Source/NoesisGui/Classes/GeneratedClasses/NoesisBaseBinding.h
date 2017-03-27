////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisBaseBinding.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBaseBinding : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property FallbackValue
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetFallbackValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFallbackValue(class UNoesisBaseComponent* InFallbackValue);

	// Property StringFormat
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetStringFormat();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStringFormat(FString InStringFormat);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

