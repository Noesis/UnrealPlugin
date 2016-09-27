////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiPanel.h"
#include "NoesisGuiGrid.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiGrid : public UNoesisGuiPanel
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ColumnDefinitions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiColumnDefinitionCollection* GetColumnDefinitions();

	// Property RowDefinitions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiRowDefinitionCollection* GetRowDefinitions();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

