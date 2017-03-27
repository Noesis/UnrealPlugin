////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisToggleButton.h"
#include "NoesisRadioButton.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisRadioButton : public UNoesisToggleButton
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property GroupName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetGroupName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGroupName(FString InGroupName);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

