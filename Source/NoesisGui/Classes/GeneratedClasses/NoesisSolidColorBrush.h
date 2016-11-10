////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBrush.h"
#include "NoesisSolidColorBrush.generated.h"

UCLASS()
class NOESISGUI_API UNoesisSolidColorBrush : public UNoesisBrush
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Color
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingColor GetColor();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetColor(FNoesisDrawingColor InColor);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

