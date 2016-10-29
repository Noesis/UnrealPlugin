////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"
#include "NoesisGuiTriggerAction.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTriggerAction : public UNoesisGuiDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Invoke(class UNoesisGuiFrameworkElement* Target, class UNoesisGuiFrameworkElement* NameScope);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

