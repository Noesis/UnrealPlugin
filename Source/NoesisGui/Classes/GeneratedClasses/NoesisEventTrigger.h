////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseTrigger.h"
#include "NoesisEventTrigger.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisEventTrigger : public UNoesisBaseTrigger
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Actions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTriggerActionCollection* GetActions();

	// Property RoutedEvent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisRoutedEvent* GetRoutedEvent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRoutedEvent(class UNoesisRoutedEvent* InRoutedEvent);

	// Property SourceName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSourceName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSourceName(FString InSourceName);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

