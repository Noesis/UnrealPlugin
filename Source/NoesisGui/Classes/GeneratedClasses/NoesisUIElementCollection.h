////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisVisualCollection.h"
#include "NoesisUIElementCollection.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisUIElementCollection : public UNoesisVisualCollection
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property LogicalParent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisFrameworkElement* GetLogicalParent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetLogicalParent(class UNoesisFrameworkElement* InLogicalParent);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

