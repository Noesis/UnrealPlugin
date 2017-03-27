////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisHeaderedItemsControl.h"
#include "NoesisToolBar.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisToolBar : public UNoesisHeaderedItemsControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Band
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetBand();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBand(int32 InBand);

	// Property BandIndex
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetBandIndex();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBandIndex(int32 InBandIndex);

	// Property HasOverflowItems
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetHasOverflowItems();

	// Property IsOverflowOpen
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsOverflowOpen();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsOverflowOpen(bool InIsOverflowOpen);

	// Property Orientation
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisOrientation GetOrientation();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

