////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisShape.generated.h"

UCLASS()
class NOESISGUI_API UNoesisShape : public UNoesisFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Fill
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetFill();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFill(class UNoesisBrush* InFill);

	// Property Stretch
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisStretch GetStretch();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStretch(ENoesisStretch InStretch);

	// Property Stroke
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetStroke();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStroke(class UNoesisBrush* InStroke);

	// Property StrokeDashArray
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetStrokeDashArray();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStrokeDashArray(FString InStrokeDashArray);

	// Property StrokeDashCap
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPenLineCap GetStrokeDashCap();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStrokeDashCap(ENoesisPenLineCap InStrokeDashCap);

	// Property StrokeDashOffset
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetStrokeDashOffset();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStrokeDashOffset(float InStrokeDashOffset);

	// Property StrokeEndLineCap
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPenLineCap GetStrokeEndLineCap();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStrokeEndLineCap(ENoesisPenLineCap InStrokeEndLineCap);

	// Property StrokeLineJoin
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPenLineJoin GetStrokeLineJoin();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStrokeLineJoin(ENoesisPenLineJoin InStrokeLineJoin);

	// Property StrokeMiterLimit
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetStrokeMiterLimit();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStrokeMiterLimit(float InStrokeMiterLimit);

	// Property StrokeStartLineCap
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPenLineCap GetStrokeStartLineCap();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStrokeStartLineCap(ENoesisPenLineCap InStrokeStartLineCap);

	// Property StrokeThickness
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetStrokeThickness();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStrokeThickness(float InStrokeThickness);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

