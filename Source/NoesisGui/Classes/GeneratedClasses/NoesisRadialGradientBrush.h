////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisGradientBrush.h"
#include "NoesisRadialGradientBrush.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisRadialGradientBrush : public UNoesisGradientBrush
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Center
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingPoint GetCenter();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCenter(FNoesisDrawingPoint InCenter);

	// Property GradientOrigin
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingPoint GetGradientOrigin();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGradientOrigin(FNoesisDrawingPoint InGradientOrigin);

	// Property RadiusX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetRadiusX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRadiusX(float InRadiusX);

	// Property RadiusY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetRadiusY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRadiusY(float InRadiusY);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

