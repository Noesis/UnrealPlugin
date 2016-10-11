////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiFreezable.h"
#include "NoesisGuiKeySpline.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiKeySpline : public UNoesisGuiFreezable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ControlPoint1
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDrawingPoint GetControlPoint1();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetControlPoint1(FNoesisGuiDrawingPoint InControlPoint1);

	// Property ControlPoint2
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDrawingPoint GetControlPoint2();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetControlPoint2(FNoesisGuiDrawingPoint InControlPoint2);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
float GetSplineProgress(float LinearProgress);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

