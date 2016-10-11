////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiItemContainerGenerator.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiItemContainerGenerator : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Status
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisGuiGeneratorStatus GetStatus();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiDependencyObject* ContainerFromIndex(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiDependencyObject* ContainerFromItem(class UNoesisGuiBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiDependencyObject* GenerateNext();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiDependencyObject* GenerateNext_(bool& IsNewlyRealized);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisGuiGeneratorPosition GeneratorPositionFromIndex(int32 ItemIndex);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiItemContainerGenerator* GetItemContainerGeneratorForPanel(class UNoesisGuiPanel* Panel);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 IndexFromContainer(class UNoesisGuiDependencyObject* Container);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 IndexFromGeneratorPosition(FNoesisGuiGeneratorPosition Position);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* ItemFromContainer(class UNoesisGuiDependencyObject* Container);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PrepareItemContainer(class UNoesisGuiDependencyObject* Container);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Remove(FNoesisGuiGeneratorPosition Position, int32 Count);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void RemoveAll();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Stop();

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiItemsChangedEventHandler ItemsChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiEventHandler StatusChanged;

	void ItemsChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ItemsChangedEventArgs& InArgs);

	void StatusChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ItemsChangedEventArgs& InArgs)> ItemsChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)> StatusChanged_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

