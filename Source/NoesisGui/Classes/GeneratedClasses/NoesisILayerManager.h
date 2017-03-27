////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisILayerManager.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisILayerManager : public UNoesisInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void AddLayer(class UNoesisVisual* LayerRoot);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void RemoveLayer(class UNoesisVisual* LayerRoot);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

