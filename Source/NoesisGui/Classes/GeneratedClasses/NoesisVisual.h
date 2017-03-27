////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisVisual.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisVisual : public UNoesisDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property View
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	UNoesisIView* GetView();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ConnectToView(class UNoesisIView* View);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void DisableDebugFlags();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisVisual* FindCommonVisualAncestor(const class UNoesisVisual* Visual);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetRenderTreeId();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsAncestorOf(const class UNoesisVisual* Visual);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsConnectedToView();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsDescendantOf(const class UNoesisVisual* Visual);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsInRenderTree();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsInvalidated();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingPoint PointFromScreen(FNoesisDrawingPoint Point);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingPoint PointToScreen(FNoesisDrawingPoint Point);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVisualBrushFlag();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

