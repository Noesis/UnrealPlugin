////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseDictionary.h"
#include "NoesisGuiResourceDictionary.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiResourceDictionary : public UNoesisGuiBaseDictionary
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
class UNoesisGuiResourceDictionaryCollection* GetMergedDictionaries();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool HasResourcesDefined();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Remove(class UNoesisGuiIResourceKey* Key);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

