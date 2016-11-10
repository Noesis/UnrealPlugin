////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseView.h"
#include "NoesisGridView.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGridView : public UNoesisBaseView
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property AllowsColumnReorder
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetAllowsColumnReorder();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAllowsColumnReorder(bool InAllowsColumnReorder);

	// Property ColumnHeaderContainerStyle
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisStyle* GetColumnHeaderContainerStyle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColumnHeaderContainerStyle(class UNoesisStyle* InColumnHeaderContainerStyle);

	// Property ColumnHeaderContextMenu
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisContextMenu* GetColumnHeaderContextMenu();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColumnHeaderContextMenu(class UNoesisContextMenu* InColumnHeaderContextMenu);

	// Property ColumnHeaderStringFormat
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetColumnHeaderStringFormat();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColumnHeaderStringFormat(FString InColumnHeaderStringFormat);

	// Property ColumnHeaderTemplate
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplate* GetColumnHeaderTemplate();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColumnHeaderTemplate(class UNoesisDataTemplate* InColumnHeaderTemplate);

	// Property ColumnHeaderTemplateSelector
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDataTemplateSelector* GetColumnHeaderTemplateSelector();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColumnHeaderTemplateSelector(class UNoesisDataTemplateSelector* InColumnHeaderTemplateSelector);

	// Property ColumnHeaderToolTip
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetColumnHeaderToolTip();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColumnHeaderToolTip(class UNoesisBaseComponent* InColumnHeaderToolTip);

	// Property Columns
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGridViewColumnCollection* GetColumns();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

