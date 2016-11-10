////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFreezable.h"
#include "NoesisKeySpline.generated.h"

UCLASS()
class NOESISGUI_API UNoesisKeySpline : public UNoesisFreezable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ControlPoint1
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingPoint GetControlPoint1();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetControlPoint1(FNoesisDrawingPoint InControlPoint1);

	// Property ControlPoint2
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingPoint GetControlPoint2();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetControlPoint2(FNoesisDrawingPoint InControlPoint2);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
float GetSplineProgress(float LinearProgress);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

