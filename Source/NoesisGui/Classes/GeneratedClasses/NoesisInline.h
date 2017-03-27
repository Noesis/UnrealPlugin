////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTextElement.h"
#include "NoesisInline.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisInline : public UNoesisTextElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property NextInline
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisInline* GetNextInline();

	// Property PreviousInline
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisInline* GetPreviousInline();

	// Property SiblingInlines
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisInlineCollection* GetSiblingInlines();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

