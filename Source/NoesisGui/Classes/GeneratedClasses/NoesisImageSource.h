////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisAnimatable.h"
#include "NoesisImageSource.generated.h"

UCLASS()
class NOESISGUI_API UNoesisImageSource : public UNoesisAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Height
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetHeight();

	// Property Width
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetWidth();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

