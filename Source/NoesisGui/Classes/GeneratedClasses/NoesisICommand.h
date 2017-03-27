////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisICommand.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisICommand : public UNoesisInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FName GetName();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool CanExecute(class UNoesisBaseComponent* Param);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void Execute(class UNoesisBaseComponent* Param);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

