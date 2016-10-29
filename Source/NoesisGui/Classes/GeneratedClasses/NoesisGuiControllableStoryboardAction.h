////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiTriggerAction.h"
#include "NoesisGuiControllableStoryboardAction.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiControllableStoryboardAction : public UNoesisGuiTriggerAction
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property BeginStoryboardName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetBeginStoryboardName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBeginStoryboardName(FString InBeginStoryboardName);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

