////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Kismet includes
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

struct FPreviewTabSummoner : public FWorkflowTabFactory
{
public:
	static const FName TabID;

public:
	FPreviewTabSummoner(TSharedPtr<class FNoesisBlueprintEditor> InBlueprintEditor);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<class FNoesisBlueprintEditor> BlueprintEditor;
};
