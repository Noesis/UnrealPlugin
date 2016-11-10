////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisAnimatable.h"
#include "NoesisGeometry.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGeometry : public UNoesisAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Bounds
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingRect GetBounds();

	// Property Transform
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTransform* GetTransform();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTransform(class UNoesisTransform* InTransform);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool FillContains(FNoesisDrawingPoint Point);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisDrawingRect GetRenderBounds(class UNoesisPen* Pen);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsEmpty();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool StrokeContains(class UNoesisPen* Pen, FNoesisDrawingPoint Point);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

