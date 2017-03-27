////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisInline.h"
#include "NoesisRun.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisRun : public UNoesisInline
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Text
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetText();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetText(FString InText);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

