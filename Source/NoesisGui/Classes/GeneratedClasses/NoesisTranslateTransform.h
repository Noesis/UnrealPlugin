////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTransform.h"
#include "NoesisTranslateTransform.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisTranslateTransform : public UNoesisTransform
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property X
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetX(float InX);

	// Property Y
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetY(float InY);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

