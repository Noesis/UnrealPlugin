////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiListBoxItem.h"
#include "NoesisGuiComboBoxItem.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiComboBoxItem : public UNoesisGuiListBoxItem
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetHighlighted(bool Value);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

