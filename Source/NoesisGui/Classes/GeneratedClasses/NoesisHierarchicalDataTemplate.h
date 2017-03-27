////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDataTemplate.h"
#include "NoesisHierarchicalDataTemplate.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisHierarchicalDataTemplate : public UNoesisDataTemplate
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

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

	// Property ItemsSource
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseBinding* GetItemsSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetItemsSource(class UNoesisBaseBinding* InItemsSource);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

