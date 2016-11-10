////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisControl.h"
#include "NoesisItemsControl.generated.h"

UCLASS()
class NOESISGUI_API UNoesisItemsControl : public UNoesisControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property DisplayMemberPath
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetDisplayMemberPath();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDisplayMemberPath(FString InDisplayMemberPath);

	// Property HasItems
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetHasItems();

	// Property ItemContainerStyle
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisStyle* GetItemContainerStyle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemContainerStyle(class UNoesisStyle* InItemContainerStyle);

	// Property ItemTemplate
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplate* GetItemTemplate();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemTemplate(class UNoesisDataTemplate* InItemTemplate);

	// Property ItemTemplateSelector
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplateSelector* GetItemTemplateSelector();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemTemplateSelector(class UNoesisDataTemplateSelector* InItemTemplateSelector);

	// Property Items
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisItemCollection* GetItems();

	// Property ItemsPanel
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisItemsPanelTemplate* GetItemsPanel();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemsPanel(class UNoesisItemsPanelTemplate* InItemsPanel);

	// Property ItemsSource
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetItemsSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemsSource(class UNoesisBaseComponent* InItemsSource);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisDependencyObject* ContainerFromElement(class UNoesisDependencyObject* Element);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisPanel* GetDefaultItemsPanel();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisItemContainerGenerator* GetItemContainerGenerator();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsItemItsOwnContainer(class UNoesisBaseComponent* Item);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

