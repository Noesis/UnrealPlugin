////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisAnimatable.h"
#include "NoesisGradientStop.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisGradientStop : public UNoesisAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Color
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingColor GetColor();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColor(FNoesisDrawingColor InColor);

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

