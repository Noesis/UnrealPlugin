////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseMenu.h"
#include "NoesisMenu.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisMenu : public UNoesisBaseMenu
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property IsMainMenu
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsMainMenu();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsMainMenu(bool InIsMainMenu);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetActivated();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

