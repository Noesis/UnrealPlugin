////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseExpression.h"
#include "NoesisGuiBaseBindingExpression.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBaseBindingExpression : public UNoesisGuiBaseExpression
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Binding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseBinding* GetBinding();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

