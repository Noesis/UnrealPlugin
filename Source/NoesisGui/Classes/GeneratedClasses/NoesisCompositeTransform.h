////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTransform.h"
#include "NoesisCompositeTransform.generated.h"

UCLASS()
class NOESISGUI_API UNoesisCompositeTransform : public UNoesisTransform
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

	// Property Rotation
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetRotation();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRotation(float InRotation);

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

	// Property SkewX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetSkewX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSkewX(float InSkewX);

	// Property SkewY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetSkewY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSkewY(float InSkewY);

	// Property TranslateX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetTranslateX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTranslateX(float InTranslateX);

	// Property TranslateY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetTranslateY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTranslateY(float InTranslateY);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

