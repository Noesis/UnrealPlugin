////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIScrollInfo.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIScrollInfo : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void LineDown();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void LineLeft();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void LineRight();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void LineUp();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisGuiDrawingRect MakeVisible(class UNoesisGuiVisual* Visual, FNoesisGuiDrawingRect Rectangle);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void MouseWheelDown();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void MouseWheelLeft();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void MouseWheelRight();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void MouseWheelUp();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PageDown();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PageLeft();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PageRight();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PageUp();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

