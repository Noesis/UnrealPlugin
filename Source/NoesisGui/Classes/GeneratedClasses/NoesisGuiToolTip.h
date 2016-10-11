////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiContentControl.h"
#include "NoesisGuiToolTip.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiToolTip : public UNoesisGuiContentControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
UNoesisGuiPopup* GetPopup();

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler Closed;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler Opened;

	void Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Closed_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Opened_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

