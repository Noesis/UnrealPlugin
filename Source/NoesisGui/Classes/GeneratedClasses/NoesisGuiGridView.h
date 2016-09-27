////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseView.h"
#include "NoesisGuiGridView.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiGridView : public UNoesisGuiBaseView
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Columns
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiGridViewColumnCollection* GetColumns();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

