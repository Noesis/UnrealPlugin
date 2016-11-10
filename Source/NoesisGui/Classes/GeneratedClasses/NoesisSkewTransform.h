////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTransform.h"
#include "NoesisSkewTransform.generated.h"

UCLASS()
class NOESISGUI_API UNoesisSkewTransform : public UNoesisTransform
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property AngleX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetAngleX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAngleX(float InAngleX);

	// Property AngleY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetAngleY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAngleY(float InAngleY);

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

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

