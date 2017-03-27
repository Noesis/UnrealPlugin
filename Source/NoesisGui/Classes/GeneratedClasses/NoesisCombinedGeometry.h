////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisGeometry.h"
#include "NoesisCombinedGeometry.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisCombinedGeometry : public UNoesisGeometry
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Geometry1
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGeometry* GetGeometry1();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGeometry1(class UNoesisGeometry* InGeometry1);

	// Property Geometry2
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGeometry* GetGeometry2();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGeometry2(class UNoesisGeometry* InGeometry2);

	// Property GeometryCombineMode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisGeometryCombineMode GetGeometryCombineMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGeometryCombineMode(ENoesisGeometryCombineMode InGeometryCombineMode);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

