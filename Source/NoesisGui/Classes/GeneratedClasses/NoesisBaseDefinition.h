////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisBaseDefinition.generated.h"

UCLASS()
class NOESISGUI_API UNoesisBaseDefinition : public UNoesisFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property SharedSizeGroup
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSharedSizeGroup();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSharedSizeGroup(FString InSharedSizeGroup);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

