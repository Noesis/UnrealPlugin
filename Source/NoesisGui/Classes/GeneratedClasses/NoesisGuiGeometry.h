////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiAnimatable.h"
#include "NoesisGuiGeometry.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiGeometry : public UNoesisGuiAnimatable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Bounds
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDrawingRect GetBounds();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

