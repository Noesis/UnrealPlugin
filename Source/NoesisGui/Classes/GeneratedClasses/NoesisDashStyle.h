////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisAnimatable.h"
#include "NoesisDashStyle.generated.h"

UCLASS()
class NOESISGUI_API UNoesisDashStyle : public UNoesisAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Dashes
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetDashes();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDashes(FString InDashes);

	// Property Offset
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetOffset();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOffset(float InOffset);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

