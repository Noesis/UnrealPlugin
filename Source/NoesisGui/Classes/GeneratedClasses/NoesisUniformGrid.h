////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisPanel.h"
#include "NoesisUniformGrid.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisUniformGrid : public UNoesisPanel
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Columns
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetColumns();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColumns(int32 InColumns);

	// Property FirstColumn
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetFirstColumn();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFirstColumn(int32 InFirstColumn);

	// Property Rows
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetRows();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRows(int32 InRows);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

