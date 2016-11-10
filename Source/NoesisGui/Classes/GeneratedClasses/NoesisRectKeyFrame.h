////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFreezable.h"
#include "NoesisRectKeyFrame.generated.h"

UCLASS()
class NOESISGUI_API UNoesisRectKeyFrame : public UNoesisFreezable
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property KeyTime
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisKeyTime GetKeyTime();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetKeyTime(FNoesisKeyTime InKeyTime);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

