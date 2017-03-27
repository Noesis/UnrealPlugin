////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisINameScope.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisINameScope : public UNoesisInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* FindName(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void RegisterName(FString Name, class UNoesisBaseComponent* Object);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void UnregisterName(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void UpdateName(FString Name, class UNoesisBaseComponent* Object);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

