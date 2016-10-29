////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiVirtualizationCacheLength.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiVirtualizationCacheLength : public UNoesisGuiBaseComponent
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

