////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTransform.h"
#include "NoesisScaleTransform.generated.h"

UCLASS()
class NOESISGUI_API UNoesisScaleTransform : public UNoesisTransform
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CenterX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetCenterX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCenterX(float InCenterX);

	// Property CenterY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetCenterY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCenterY(float InCenterY);

	// Property ScaleX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetScaleX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetScaleX(float InScaleX);

	// Property ScaleY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetScaleY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetScaleY(float InScaleY);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

