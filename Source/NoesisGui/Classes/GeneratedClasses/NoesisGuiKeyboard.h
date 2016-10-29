////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiKeyboard.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiKeyboard : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiUIElement* Focus(class UNoesisGuiUIElement* Element);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiUIElement* GetFocused();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 GetModifiers();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ResetState();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

