////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiFrameworkElement.h"
#include "NoesisGuiTextBlock.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTextBlock : public UNoesisGuiFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Inlines
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiInlineCollection* GetInlines();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

