////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisAnimatable.h"
#include "NoesisBrush.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBrush : public UNoesisAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Opacity
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetOpacity();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOpacity(float InOpacity);

	// Property RelativeTransform
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTransform* GetRelativeTransform();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRelativeTransform(class UNoesisTransform* InRelativeTransform);

	// Property Transform
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTransform* GetTransform();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTransform(class UNoesisTransform* InTransform);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsTransparent();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

