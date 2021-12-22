////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// BlueprintGraph includes
#include "K2Node_Variable.h"

// Generated header include
#include "K2Node_NoesisAssignAndNotify.generated.h"

UCLASS(MinimalAPI)
class UK2Node_NoesisAssignAndNotify : public UK2Node_Variable
{
	GENERATED_UCLASS_BODY()

	// UEdGraphNode interface
	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	// End of UEdGraphNode interface

	// UK2Node interface
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual bool IsActionFilteredOut(const FBlueprintActionFilter& Filter) override;
	virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	virtual bool DrawNodeAsVariable() const override { return false; }
	virtual FText GetMenuCategory() const override { return FText::FromString(TEXT("NoesisGUI")); }
	// End of UK2Node interface

	FName GetVariableOutputPinName() const;
	void CreateOutputPinTooltip();
};
