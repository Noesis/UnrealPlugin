////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisContentPresenter.h"
#include "NoesisScrollContentPresenter.generated.h"

UCLASS()
class NOESISGUI_API UNoesisScrollContentPresenter : public UNoesisContentPresenter
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CanContentScroll
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetCanContentScroll();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCanContentScroll(bool InCanContentScroll);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

