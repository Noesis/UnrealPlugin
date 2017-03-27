////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisIDictionary.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisIDictionary : public UNoesisInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

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
	void Remove(class UNoesisIResourceKey* Key);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

