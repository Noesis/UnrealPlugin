////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiINameScope.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiINameScope : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* FindName(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void RegisterName(FString Name, class UNoesisGuiBaseComponent* Object);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void UnregisterName(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void UpdateName(FString Name, class UNoesisGuiBaseComponent* Object);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

