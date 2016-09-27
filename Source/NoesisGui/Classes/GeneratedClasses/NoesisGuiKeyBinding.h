////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiInputBinding.h"
#include "NoesisGuiKeyBinding.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiKeyBinding : public UNoesisGuiInputBinding
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Key
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetKey();

	// Property Modifiers
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetModifiers();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

