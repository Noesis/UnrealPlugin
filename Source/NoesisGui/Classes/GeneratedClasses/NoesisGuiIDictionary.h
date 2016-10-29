////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIDictionary.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIDictionary : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Add(class UNoesisGuiIResourceKey* Key, class UNoesisGuiBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Clear();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Contains(class UNoesisGuiIResourceKey* Key);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 Count();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Find(class UNoesisGuiIResourceKey* Key, class UNoesisGuiBaseComponent* Resource);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* Get(class UNoesisGuiIResourceKey* Key);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Remove(class UNoesisGuiIResourceKey* Key);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

