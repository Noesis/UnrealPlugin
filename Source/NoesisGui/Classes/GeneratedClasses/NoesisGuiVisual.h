////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"
#include "NoesisGuiVisual.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiVisual : public UNoesisGuiDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property View
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	UNoesisGuiIView* GetView();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ConnectToView(class UNoesisGuiIView* View);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void DisableDebugFlags();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiVisual* FindCommonVisualAncestor(const class UNoesisGuiVisual* Visual);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 GetRenderTreeId();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsAncestorOf(const class UNoesisGuiVisual* Visual);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsConnectedToView();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsDescendantOf(const class UNoesisGuiVisual* Visual);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsInRenderTree();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsInvalidated();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisGuiDrawingPoint PointFromScreen(FNoesisGuiDrawingPoint Point);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisGuiDrawingPoint PointToScreen(FNoesisGuiDrawingPoint Point);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetVisualBrushFlag();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

