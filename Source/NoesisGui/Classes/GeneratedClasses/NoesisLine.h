////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisShape.h"
#include "NoesisLine.generated.h"

UCLASS()
class NOESISGUI_API UNoesisLine : public UNoesisShape
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property X1
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetX1();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetX1(float InX1);

	// Property X2
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetX2();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetX2(float InX2);

	// Property Y1
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetY1();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetY1(float InY1);

	// Property Y2
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetY2();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetY2(float InY2);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

