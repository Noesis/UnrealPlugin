////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiContentControl.h"
#include "NoesisGuiScrollViewer.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiScrollViewer : public UNoesisGuiContentControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void InvalidateScrollInfo();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void LineDown();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void LineLeft();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void LineRight();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void LineUp();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PageDown();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PageLeft();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PageRight();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PageUp();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollToBottom();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollToEnd();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollToHome();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollToHorizontalOffset(float Offset);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollToLeftEnd();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollToRightEnd();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollToTop();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ScrollToVerticalOffset(float Offset);

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiScrollChangedEventHandler ScrollChanged;

	void ScrollChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ScrollChangedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ScrollChangedEventArgs& InArgs)> ScrollChanged_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

