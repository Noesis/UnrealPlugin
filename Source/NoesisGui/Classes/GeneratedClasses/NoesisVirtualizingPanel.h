////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisPanel.h"
#include "NoesisVirtualizingPanel.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisVirtualizingPanel : public UNoesisPanel
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void BringIndexIntoView(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisIItemContainerGenerator* GetItemContainerGenerator();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

