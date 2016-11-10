////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisControl.h"
#include "NoesisContentControl.generated.h"

UCLASS()
class NOESISGUI_API UNoesisContentControl : public UNoesisControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Content
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetContent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetContent(class UNoesisBaseComponent* InContent);

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

	// Property HasContent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetHasContent();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

