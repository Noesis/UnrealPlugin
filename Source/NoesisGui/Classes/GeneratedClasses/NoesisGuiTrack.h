////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiFrameworkElement.h"
#include "NoesisGuiTrack.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTrack : public UNoesisGuiFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property DecreaseRepeatButton
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiRepeatButton* GetDecreaseRepeatButton();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDecreaseRepeatButton(class UNoesisGuiRepeatButton* InDecreaseRepeatButton);

	// Property IncreaseRepeatButton
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiRepeatButton* GetIncreaseRepeatButton();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIncreaseRepeatButton(class UNoesisGuiRepeatButton* InIncreaseRepeatButton);

	// Property Thumb
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiThumb* GetThumb();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetThumb(class UNoesisGuiThumb* InThumb);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
float ValueFromDistance(float Horizontal, float Vertical);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
float ValueFromPoint(FNoesisGuiDrawingPoint Point);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

