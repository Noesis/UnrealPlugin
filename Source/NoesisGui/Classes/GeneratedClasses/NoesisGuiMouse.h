////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiMouse.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiMouse : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Captured
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiUIElement* GetCaptured();

	// Property Position
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDrawingPoint GetPosition();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ResetState();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

