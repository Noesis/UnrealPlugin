////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiFrameworkElement.h"
#include "NoesisGuiPanel.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiPanel : public UNoesisGuiFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Children
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiUIElementCollection* GetChildren();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void InvalidateZOrder();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

