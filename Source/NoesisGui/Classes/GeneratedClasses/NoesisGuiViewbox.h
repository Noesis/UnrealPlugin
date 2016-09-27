////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiFrameworkElement.h"
#include "NoesisGuiViewbox.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiViewbox : public UNoesisGuiFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Child
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiUIElement* GetChild();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetChild(class UNoesisGuiUIElement* InChild);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

