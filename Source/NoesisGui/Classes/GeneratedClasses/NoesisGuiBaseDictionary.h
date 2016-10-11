////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiBaseDictionary.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBaseDictionary : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void RemoveDictionaryChangedListeners();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

