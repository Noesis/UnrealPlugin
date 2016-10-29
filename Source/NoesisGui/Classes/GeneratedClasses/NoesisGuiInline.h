////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiTextElement.h"
#include "NoesisGuiInline.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiInline : public UNoesisGuiTextElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property NextInline
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiInline* GetNextInline();

	// Property PreviousInline
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiInline* GetPreviousInline();

	// Property SiblingInlines
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiInlineCollection* GetSiblingInlines();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

