////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiILayerManager.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiILayerManager : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void AddLayer(class UNoesisGuiVisual* LayerRoot);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void RemoveLayer(class UNoesisGuiVisual* LayerRoot);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

