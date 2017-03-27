////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisPanel.h"
#include "NoesisDockPanel.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisDockPanel : public UNoesisPanel
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property LastChildFill
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetLastChildFill();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetLastChildFill(bool InLastChildFill);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

