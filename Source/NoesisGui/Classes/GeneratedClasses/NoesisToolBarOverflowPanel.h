////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisPanel.h"
#include "NoesisToolBarOverflowPanel.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisToolBarOverflowPanel : public UNoesisPanel
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property WrapWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetWrapWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetWrapWidth(float InWrapWidth);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

