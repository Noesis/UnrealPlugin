////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisKeyboard.generated.h"

UCLASS()
class NOESISGUI_API UNoesisKeyboard : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisUIElement* Focus(class UNoesisUIElement* Element);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisUIElement* GetFocused();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 GetModifiers();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ResetState();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

