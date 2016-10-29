////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiItemCollection.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiItemCollection : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsReadOnly();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetItemsControlOwner(class UNoesisGuiItemsControl* ItemsControl);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetView(class UNoesisGuiCollectionView* View);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

