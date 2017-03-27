////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisIScrollInfo.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisIScrollInfo : public UNoesisInterface
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
	FNoesisDrawingRect MakeVisible(class UNoesisVisual* Visual, FNoesisDrawingRect Rectangle);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void MouseWheelDown(float Delta);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void MouseWheelLeft(float Delta);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void MouseWheelRight(float Delta);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void MouseWheelUp(float Delta);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void PageDown();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void PageLeft();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void PageRight();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void PageUp();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

