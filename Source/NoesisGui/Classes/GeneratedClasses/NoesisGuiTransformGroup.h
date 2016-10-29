////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiTransform.h"
#include "NoesisGuiTransformGroup.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTransformGroup : public UNoesisGuiTransform
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiTransform* GetChild(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 GetNumChildren();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

