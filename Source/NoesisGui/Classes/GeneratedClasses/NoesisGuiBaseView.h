////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"
#include "NoesisGuiBaseView.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBaseView : public UNoesisGuiDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ClearItem(class UNoesisGuiListViewItem* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PrepareItem(class UNoesisGuiListViewItem* Item);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

