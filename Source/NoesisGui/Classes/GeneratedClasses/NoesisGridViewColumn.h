////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisGridViewColumn.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisGridViewColumn : public UNoesisDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ActualWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetActualWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetActualWidth(float InActualWidth);

	// Property CellTemplate
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplate* GetCellTemplate();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCellTemplate(class UNoesisDataTemplate* InCellTemplate);

	// Property CellTemplateSelector
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplateSelector* GetCellTemplateSelector();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCellTemplateSelector(class UNoesisDataTemplateSelector* InCellTemplateSelector);

	// Property DisplayMemberBinding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseBindingExpression* GetDisplayMemberBinding();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDisplayMemberBinding(class UNoesisBaseBindingExpression* InDisplayMemberBinding);

	// Property Header
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetHeader();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHeader(class UNoesisBaseComponent* InHeader);

	// Property HeaderContainerStyle
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisStyle* GetHeaderContainerStyle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHeaderContainerStyle(class UNoesisStyle* InHeaderContainerStyle);

	// Property HeaderStringFormat
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetHeaderStringFormat();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHeaderStringFormat(FString InHeaderStringFormat);

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

	// Property Width
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetWidth(float InWidth);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

