////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiRoutedEvent.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiRoutedEvent : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FName GetName();

	// Property RoutingStrategy
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisGuiRoutingStrategy GetRoutingStrategy();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRoutingStrategy(ENoesisGuiRoutingStrategy InRoutingStrategy);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

