////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTileBrush.h"
#include "NoesisVisualBrush.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisVisualBrush : public UNoesisTileBrush
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Visual
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisVisual* GetVisual();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVisual(class UNoesisVisual* InVisual);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

