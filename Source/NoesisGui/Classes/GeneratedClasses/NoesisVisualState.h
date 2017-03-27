////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisVisualState.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisVisualState : public UNoesisDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Name
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FName GetName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetName(FName InName);

	// Property Storyboard
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisStoryboard* GetStoryboard();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStoryboard(class UNoesisStoryboard* InStoryboard);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

