////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisPanel.h"
#include "NoesisGrid.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisGrid : public UNoesisPanel
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ColumnDefinitions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisColumnDefinitionCollection* GetColumnDefinitions();

	// Property RowDefinitions
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisRowDefinitionCollection* GetRowDefinitions();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

