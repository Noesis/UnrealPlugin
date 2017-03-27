////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisProjection.h"
#include "NoesisMatrix3DProjection.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisMatrix3DProjection : public UNoesisProjection
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ProjectionMatrix
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FMatrix GetProjectionMatrix();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetProjectionMatrix(FMatrix InProjectionMatrix);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

