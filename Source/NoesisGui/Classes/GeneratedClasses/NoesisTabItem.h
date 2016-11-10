////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisHeaderedContentControl.h"
#include "NoesisTabItem.generated.h"

UCLASS()
class NOESISGUI_API UNoesisTabItem : public UNoesisHeaderedContentControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property IsSelected
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsSelected();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsSelected(bool InIsSelected);

	// Property TabStripPlacement
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisDock GetTabStripPlacement();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

