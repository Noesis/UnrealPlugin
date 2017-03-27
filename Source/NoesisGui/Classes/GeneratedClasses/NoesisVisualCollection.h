////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisCollection.h"
#include "NoesisVisualCollection.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisVisualCollection : public UNoesisCollection
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property VisualParent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisVisual* GetVisualParent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVisualParent(class UNoesisVisual* InVisualParent);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

