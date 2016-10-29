////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIResourceKey.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIResourceKey : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Equals(const class UNoesisGuiIResourceKey* ResourceKey);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FString GetStr();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

