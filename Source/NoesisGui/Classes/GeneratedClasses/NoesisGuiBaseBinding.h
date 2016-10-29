////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiBaseBinding.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBaseBinding : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property FallbackValue
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* GetFallbackValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFallbackValue(class UNoesisGuiBaseComponent* InFallbackValue);

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

