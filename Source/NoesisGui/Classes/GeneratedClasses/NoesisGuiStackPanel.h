////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiPanel.h"
#include "NoesisGuiStackPanel.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiStackPanel : public UNoesisGuiPanel
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CanHorizontallyScroll
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetCanHorizontallyScroll();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCanHorizontallyScroll(bool InCanHorizontallyScroll);

	// Property CanVerticallyScroll
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetCanVerticallyScroll();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCanVerticallyScroll(bool InCanVerticallyScroll);

	// Property ExtentHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetExtentHeight();

	// Property ExtentWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetExtentWidth();

	// Property HorizontalOffset
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetHorizontalOffset();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHorizontalOffset(float InHorizontalOffset);

	// Property ScrollOwner
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiScrollViewer* GetScrollOwner();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetScrollOwner(class UNoesisGuiScrollViewer* InScrollOwner);

	// Property VerticalOffset
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetVerticalOffset();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVerticalOffset(float InVerticalOffset);

	// Property ViewportHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetViewportHeight();

	// Property ViewportWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetViewportWidth();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

