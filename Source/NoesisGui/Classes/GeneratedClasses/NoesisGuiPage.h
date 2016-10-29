////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiUserControl.h"
#include "NoesisGuiPage.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiPage : public UNoesisGuiUserControl
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

