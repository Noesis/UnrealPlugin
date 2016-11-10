////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisVirtualizationCacheLength.generated.h"

UCLASS()
class NOESISGUI_API UNoesisVirtualizationCacheLength : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CacheAfterViewport
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetCacheAfterViewport();

	// Property CacheBeforeViewport
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetCacheBeforeViewport();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

