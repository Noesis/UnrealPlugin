////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisProjection.h"
#include "NoesisPlaneProjection.generated.h"

UCLASS()
class NOESISGUI_API UNoesisPlaneProjection : public UNoesisProjection
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CenterOfRotationX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetCenterOfRotationX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCenterOfRotationX(float InCenterOfRotationX);

	// Property CenterOfRotationY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetCenterOfRotationY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCenterOfRotationY(float InCenterOfRotationY);

	// Property CenterOfRotationZ
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetCenterOfRotationZ();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCenterOfRotationZ(float InCenterOfRotationZ);

	// Property GlobalOffsetX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetGlobalOffsetX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGlobalOffsetX(float InGlobalOffsetX);

	// Property GlobalOffsetY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetGlobalOffsetY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGlobalOffsetY(float InGlobalOffsetY);

	// Property GlobalOffsetZ
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetGlobalOffsetZ();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetGlobalOffsetZ(float InGlobalOffsetZ);

	// Property LocalOffsetX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetLocalOffsetX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetLocalOffsetX(float InLocalOffsetX);

	// Property LocalOffsetY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetLocalOffsetY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetLocalOffsetY(float InLocalOffsetY);

	// Property LocalOffsetZ
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetLocalOffsetZ();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetLocalOffsetZ(float InLocalOffsetZ);

	// Property ProjectionMatrix
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FMatrix GetProjectionMatrix();

	// Property RotationX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetRotationX();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRotationX(float InRotationX);

	// Property RotationY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetRotationY();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRotationY(float InRotationY);

	// Property RotationZ
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetRotationZ();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRotationZ(float InRotationZ);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

