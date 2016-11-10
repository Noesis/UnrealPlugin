////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTileBrush.h"
#include "NoesisImageBrush.generated.h"

UCLASS()
class NOESISGUI_API UNoesisImageBrush : public UNoesisTileBrush
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ImageSource
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisImageSource* GetImageSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetImageSource(class UNoesisImageSource* InImageSource);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

