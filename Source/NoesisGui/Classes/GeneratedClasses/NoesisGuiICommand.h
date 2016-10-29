////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiICommand.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiICommand : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FName GetName();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CanExecute(class UNoesisGuiBaseComponent* Param);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Execute(class UNoesisGuiBaseComponent* Param);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

