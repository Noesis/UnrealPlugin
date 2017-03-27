////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisGradientBrush.h"
#include "NoesisLinearGradientBrush.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisLinearGradientBrush : public UNoesisGradientBrush
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property EndPoint
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingPoint GetEndPoint();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetEndPoint(FNoesisDrawingPoint InEndPoint);

	// Property StartPoint
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingPoint GetStartPoint();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStartPoint(FNoesisDrawingPoint InStartPoint);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

