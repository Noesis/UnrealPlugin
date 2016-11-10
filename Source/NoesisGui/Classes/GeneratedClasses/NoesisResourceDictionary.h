////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseDictionary.h"
#include "NoesisResourceDictionary.generated.h"

UCLASS()
class NOESISGUI_API UNoesisResourceDictionary : public UNoesisBaseDictionary
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Source
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSource(FString InSource);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Add(class UNoesisIResourceKey* Key, class UNoesisBaseComponent* Value);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Clear();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Contains(class UNoesisIResourceKey* Key);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 Count();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Find(class UNoesisIResourceKey* Key, class UNoesisBaseComponent* Resource);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisBaseComponent* Get(class UNoesisIResourceKey* Key);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisResourceDictionaryCollection* GetMergedDictionaries();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool HasResourcesDefined();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Remove(class UNoesisIResourceKey* Key);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

