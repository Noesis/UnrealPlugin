////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisListBoxItem.h"
#include "NoesisComboBoxItem.generated.h"

UCLASS()
class NOESISGUI_API UNoesisComboBoxItem : public UNoesisListBoxItem
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property IsHighlighted
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsHighlighted();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetHighlighted(bool Value);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

