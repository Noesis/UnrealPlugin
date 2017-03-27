////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTimeline.h"
#include "NoesisTimelineGroup.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisTimelineGroup : public UNoesisTimeline
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Children
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTimelineCollection* GetChildren();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetChildren(class UNoesisTimelineCollection* InChildren);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

