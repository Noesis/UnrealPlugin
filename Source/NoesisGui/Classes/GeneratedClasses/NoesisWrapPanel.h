////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisPanel.h"
#include "NoesisWrapPanel.generated.h"

UCLASS()
class NOESISGUI_API UNoesisWrapPanel : public UNoesisPanel
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ItemHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetItemHeight();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemHeight(float InItemHeight);

	// Property ItemWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetItemWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemWidth(float InItemWidth);

	// Property Orientation
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisOrientation GetOrientation();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOrientation(ENoesisOrientation InOrientation);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

