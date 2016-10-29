////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiPanel.h"
#include "NoesisGuiVirtualizingPanel.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiVirtualizingPanel : public UNoesisGuiPanel
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void BringIndexIntoView(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiIItemContainerGenerator* GetItemContainerGenerator();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

