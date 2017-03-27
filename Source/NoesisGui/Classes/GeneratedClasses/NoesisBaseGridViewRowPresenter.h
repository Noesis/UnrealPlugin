////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisBaseGridViewRowPresenter.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBaseGridViewRowPresenter : public UNoesisFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Columns
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGridViewColumnCollection* GetColumns();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColumns(class UNoesisGridViewColumnCollection* InColumns);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

