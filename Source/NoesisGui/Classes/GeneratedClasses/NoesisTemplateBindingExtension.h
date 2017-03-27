////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisTemplateBindingExtension.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisTemplateBindingExtension : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Property
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDependencyProperty* GetProperty();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetProperty(class UNoesisDependencyProperty* InProperty);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

