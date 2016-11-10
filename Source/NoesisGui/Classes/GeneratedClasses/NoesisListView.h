////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisListBox.h"
#include "NoesisListView.generated.h"

UCLASS()
class NOESISGUI_API UNoesisListView : public UNoesisListBox
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property View
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseView* GetView();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetView(class UNoesisBaseView* InView);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

