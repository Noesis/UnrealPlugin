////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDataTemplate.h"
#include "NoesisGuiHierarchicalDataTemplate.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiHierarchicalDataTemplate : public UNoesisGuiDataTemplate
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ItemContainerStyle
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiStyle* GetItemContainerStyle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemContainerStyle(class UNoesisGuiStyle* InItemContainerStyle);

	// Property ItemTemplate
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiDataTemplate* GetItemTemplate();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemTemplate(class UNoesisGuiDataTemplate* InItemTemplate);

	// Property ItemTemplateSelector
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiDataTemplateSelector* GetItemTemplateSelector();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemTemplateSelector(class UNoesisGuiDataTemplateSelector* InItemTemplateSelector);

	// Property ItemsSource
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseBinding* GetItemsSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemsSource(class UNoesisGuiBaseBinding* InItemsSource);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

