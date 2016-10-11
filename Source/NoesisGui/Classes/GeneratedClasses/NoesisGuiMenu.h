////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseMenu.h"
#include "NoesisGuiMenu.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiMenu : public UNoesisGuiBaseMenu
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool GetActivated();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

