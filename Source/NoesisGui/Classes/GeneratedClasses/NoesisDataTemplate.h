////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkTemplate.h"
#include "NoesisDataTemplate.generated.h"

UCLASS()
class NOESISGUI_API UNoesisDataTemplate : public UNoesisFrameworkTemplate
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property DataType
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisResourceKeyType* GetDataType();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDataType(class UNoesisResourceKeyType* InDataType);

	// Property Triggers
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTriggerCollection* GetTriggers();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

