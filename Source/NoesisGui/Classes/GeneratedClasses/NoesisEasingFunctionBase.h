////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFreezable.h"
#include "NoesisEasingFunctionBase.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisEasingFunctionBase : public UNoesisFreezable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property EasingMode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisEasingMode GetEasingMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetEasingMode(ENoesisEasingMode InEasingMode);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

