////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisAnimatable.h"
#include "NoesisPen.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisPen : public UNoesisAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Brush
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetBrush();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBrush(class UNoesisBrush* InBrush);

	// Property DashCap
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPenLineCap GetDashCap();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDashCap(ENoesisPenLineCap InDashCap);

	// Property DashStyle
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDashStyle* GetDashStyle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDashStyle(class UNoesisDashStyle* InDashStyle);

	// Property EndLineCap
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPenLineCap GetEndLineCap();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetEndLineCap(ENoesisPenLineCap InEndLineCap);

	// Property LineJoin
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPenLineJoin GetLineJoin();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetLineJoin(ENoesisPenLineJoin InLineJoin);

	// Property MiterLimit
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetMiterLimit();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMiterLimit(float InMiterLimit);

	// Property StartLineCap
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPenLineCap GetStartLineCap();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStartLineCap(ENoesisPenLineCap InStartLineCap);

	// Property Thickness
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetThickness();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetThickness(float InThickness);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsRenderable();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

