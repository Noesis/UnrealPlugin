////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBrush.h"
#include "NoesisGradientBrush.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGradientBrush : public UNoesisBrush
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ColorInterpolationMode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisColorInterpolationMode GetColorInterpolationMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColorInterpolationMode(ENoesisColorInterpolationMode InColorInterpolationMode);

	// Property GradientStops
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGradientStopCollection* GetGradientStops();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGradientStops(class UNoesisGradientStopCollection* InGradientStops);

	// Property MappingMode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisBrushMappingMode GetMappingMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMappingMode(ENoesisBrushMappingMode InMappingMode);

	// Property SpreadMethod
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisGradientSpreadMethod GetSpreadMethod();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSpreadMethod(ENoesisGradientSpreadMethod InSpreadMethod);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

