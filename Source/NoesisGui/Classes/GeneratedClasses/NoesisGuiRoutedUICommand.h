////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiRoutedCommand.h"
#include "NoesisGuiRoutedUICommand.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiRoutedUICommand : public UNoesisGuiRoutedCommand
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Text
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetText();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetText(FString InText);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

