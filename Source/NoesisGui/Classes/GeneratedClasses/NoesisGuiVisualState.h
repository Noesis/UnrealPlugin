////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"
#include "NoesisGuiVisualState.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiVisualState : public UNoesisGuiDependencyObject
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
	class UNoesisGuiStoryboard* GetStoryboard();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStoryboard(class UNoesisGuiStoryboard* InStoryboard);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

