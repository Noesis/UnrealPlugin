////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDecorator.h"
#include "NoesisBorder.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBorder : public UNoesisDecorator
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Background
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetBackground();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBackground(class UNoesisBrush* InBackground);

	// Property BorderBrush
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetBorderBrush();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBorderBrush(class UNoesisBrush* InBorderBrush);

	// Property BorderThickness
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingThickness GetBorderThickness();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBorderThickness(FNoesisDrawingThickness InBorderThickness);

	// Property CornerRadius
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingCornerRadius GetCornerRadius();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCornerRadius(FNoesisDrawingCornerRadius InCornerRadius);

	// Property Padding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingThickness GetPadding();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPadding(FNoesisDrawingThickness InPadding);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

