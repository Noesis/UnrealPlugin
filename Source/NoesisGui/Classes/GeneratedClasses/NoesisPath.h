////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisShape.h"
#include "NoesisPath.generated.h"

UCLASS()
class NOESISGUI_API UNoesisPath : public UNoesisShape
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Data
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGeometry* GetData();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetData(class UNoesisGeometry* InData);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

