////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseTrigger.h"
#include "NoesisGuiEventTrigger.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiEventTrigger : public UNoesisGuiBaseTrigger
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Actions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiTriggerActionCollection* GetActions();

	// Property RoutedEvent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiRoutedEvent* GetRoutedEvent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRoutedEvent(class UNoesisGuiRoutedEvent* InRoutedEvent);

	// Property SourceName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSourceName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSourceName(FString InSourceName);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

