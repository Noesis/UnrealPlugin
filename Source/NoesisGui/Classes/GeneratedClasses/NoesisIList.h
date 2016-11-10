////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisIList.generated.h"

UCLASS()
class NOESISGUI_API UNoesisIList : public UNoesisInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 Add(class UNoesisBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Clear();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Contains(class UNoesisBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 Count();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisBaseComponent* Get(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 IndexOf(class UNoesisBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Insert(int32 Index, class UNoesisBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Remove(class UNoesisBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void RemoveAt(int32 Index);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

