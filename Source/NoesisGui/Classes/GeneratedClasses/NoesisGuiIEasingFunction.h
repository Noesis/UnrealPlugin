////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIEasingFunction.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIEasingFunction : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
float Ease(float NormalizedTime);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

