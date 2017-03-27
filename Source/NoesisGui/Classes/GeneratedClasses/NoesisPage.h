////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisUserControl.h"
#include "NoesisPage.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisPage : public UNoesisUserControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Title
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetTitle();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTitle(FString InTitle);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

