////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiContentControl.h"
#include "NoesisGuiListBoxItem.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiListBoxItem : public UNoesisGuiContentControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler Selected;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler Unselected;

	void Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Selected_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Unselected_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

