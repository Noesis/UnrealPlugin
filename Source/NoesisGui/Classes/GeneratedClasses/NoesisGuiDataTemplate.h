////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiFrameworkTemplate.h"
#include "NoesisGuiDataTemplate.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiDataTemplate : public UNoesisGuiFrameworkTemplate
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property DataType
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiResourceKeyType* GetDataType();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDataType(class UNoesisGuiResourceKeyType* InDataType);

	// Property Triggers
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiTriggerCollection* GetTriggers();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

