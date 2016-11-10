////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisBaseView.generated.h"

UCLASS()
class NOESISGUI_API UNoesisBaseView : public UNoesisDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ClearItem(class UNoesisListViewItem* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PrepareItem(class UNoesisListViewItem* Item);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

