////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiRangeBase.h"
#include "NoesisGuiScrollBar.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiScrollBar : public UNoesisGuiRangeBase
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Track
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiTrack* GetTrack();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

