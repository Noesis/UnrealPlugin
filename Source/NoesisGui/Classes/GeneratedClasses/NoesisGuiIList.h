////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIList.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIList : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 Add(class UNoesisGuiBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Clear();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Contains(class UNoesisGuiBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 Count();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* Get(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 IndexOf(class UNoesisGuiBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Insert(int32 Index, class UNoesisGuiBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Remove(class UNoesisGuiBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void RemoveAt(int32 Index);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

