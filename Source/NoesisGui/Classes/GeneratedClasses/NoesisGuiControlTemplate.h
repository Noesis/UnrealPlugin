////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiFrameworkTemplate.h"
#include "NoesisGuiControlTemplate.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiControlTemplate : public UNoesisGuiFrameworkTemplate
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property TargetType
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiResourceKeyType* GetTargetType();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTargetType(class UNoesisGuiResourceKeyType* InTargetType);

	// Property Triggers
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiTriggerCollection* GetTriggers();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

