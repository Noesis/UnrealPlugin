////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisSelector.h"
#include "NoesisTabControl.generated.h"

UCLASS()
class NOESISGUI_API UNoesisTabControl : public UNoesisSelector
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ContentTemplate
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplate* GetContentTemplate();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetContentTemplate(class UNoesisDataTemplate* InContentTemplate);

	// Property ContentTemplateSelector
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplateSelector* GetContentTemplateSelector();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetContentTemplateSelector(class UNoesisDataTemplateSelector* InContentTemplateSelector);

	// Property SelectedContent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetSelectedContent();

	// Property SelectedContentTemplate
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplate* GetSelectedContentTemplate();

	// Property SelectedContentTemplateSelector
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplateSelector* GetSelectedContentTemplateSelector();

	// Property TabStripPlacement
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisDock GetTabStripPlacement();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTabStripPlacement(ENoesisDock InTabStripPlacement);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

