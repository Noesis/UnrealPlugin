////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisGeometry.h"
#include "NoesisStreamGeometry.generated.h"

UCLASS()
class NOESISGUI_API UNoesisStreamGeometry : public UNoesisGeometry
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property FillRule
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisFillRule GetFillRule();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFillRule(ENoesisFillRule InFillRule);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetData(FString Data);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

