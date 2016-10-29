////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiAnimatable.h"
#include "NoesisGuiGeometry.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiGeometry : public UNoesisGuiAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Bounds
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDrawingRect GetBounds();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool FillContains(FNoesisGuiDrawingPoint Point);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisGuiDrawingRect GetRenderBounds(class UNoesisGuiPen* Pen);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsEmpty();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool StrokeContains(class UNoesisGuiPen* Pen, FNoesisGuiDrawingPoint Point);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

