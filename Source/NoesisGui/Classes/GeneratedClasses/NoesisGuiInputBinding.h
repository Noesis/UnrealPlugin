////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiFreezable.h"
#include "NoesisGuiInputBinding.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiInputBinding : public UNoesisGuiFreezable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Gesture
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiInputGesture* GetGesture();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGesture(class UNoesisGuiInputGesture* InGesture);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

