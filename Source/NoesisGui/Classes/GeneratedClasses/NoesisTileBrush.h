////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBrush.h"
#include "NoesisTileBrush.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisTileBrush : public UNoesisBrush
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property AlignmentX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisAlignmentX GetAlignmentX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAlignmentX(ENoesisAlignmentX InAlignmentX);

	// Property AlignmentY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisAlignmentY GetAlignmentY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAlignmentY(ENoesisAlignmentY InAlignmentY);

	// Property Stretch
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisStretch GetStretch();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStretch(ENoesisStretch InStretch);

	// Property TileMode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisTileMode GetTileMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTileMode(ENoesisTileMode InTileMode);

	// Property Viewbox
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingRect GetViewbox();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetViewbox(FNoesisDrawingRect InViewbox);

	// Property ViewboxUnits
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisBrushMappingMode GetViewboxUnits();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetViewboxUnits(ENoesisBrushMappingMode InViewboxUnits);

	// Property Viewport
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingRect GetViewport();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetViewport(FNoesisDrawingRect InViewport);

	// Property ViewportUnits
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisBrushMappingMode GetViewportUnits();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetViewportUnits(ENoesisBrushMappingMode InViewportUnits);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

