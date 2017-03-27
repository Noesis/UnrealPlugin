////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkTemplate.h"
#include "NoesisControlTemplate.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisControlTemplate : public UNoesisFrameworkTemplate
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property TargetType
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisResourceKeyType* GetTargetType();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTargetType(class UNoesisResourceKeyType* InTargetType);

	// Property Triggers
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTriggerCollection* GetTriggers();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

