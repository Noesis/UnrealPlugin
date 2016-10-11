////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiItemsControl.h"
#include "NoesisGuiTreeView.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTreeView : public UNoesisGuiItemsControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ItemClicked(class UNoesisGuiTreeViewItem* Tvi);

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiBaseComponentPropertyChangedEventHandler SelectedItemChanged;

	void SelectedItemChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedPropertyChangedEventArgs<Noesis::Ptr<Noesis::BaseComponent> >& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedPropertyChangedEventArgs<Noesis::Ptr<Noesis::BaseComponent> >& InArgs)> SelectedItemChanged_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

