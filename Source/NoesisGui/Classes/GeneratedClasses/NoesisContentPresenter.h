////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisContentPresenter.generated.h"

UCLASS()
class NOESISGUI_API UNoesisContentPresenter : public UNoesisFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Content
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetContent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetContent(class UNoesisBaseComponent* InContent);

	// Property ContentSource
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetContentSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetContentSource(FString InContentSource);

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

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

