////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisContentControl.h"
#include "NoesisHeaderedContentControl.generated.h"

UCLASS()
class NOESISGUI_API UNoesisHeaderedContentControl : public UNoesisContentControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property HasHeader
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetHasHeader();

	// Property Header
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetHeader();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHeader(class UNoesisBaseComponent* InHeader);

	// Property HeaderTemplate
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplate* GetHeaderTemplate();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHeaderTemplate(class UNoesisDataTemplate* InHeaderTemplate);

	// Property HeaderTemplateSelector
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplateSelector* GetHeaderTemplateSelector();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHeaderTemplateSelector(class UNoesisDataTemplateSelector* InHeaderTemplateSelector);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

