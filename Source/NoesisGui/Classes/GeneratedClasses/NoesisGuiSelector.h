////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiItemsControl.h"
#include "NoesisGuiSelector.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiSelector : public UNoesisGuiItemsControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiSelectionChangedEventHandler SelectionChanged;

	void SelectionChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::SelectionChangedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::SelectionChangedEventArgs& InArgs)> SelectionChanged_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

