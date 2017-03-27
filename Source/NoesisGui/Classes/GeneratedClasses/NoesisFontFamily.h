////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisFontFamily.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisFontFamily : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property BaseUri
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetBaseUri();

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetName();

	// Property Source
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSource();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

