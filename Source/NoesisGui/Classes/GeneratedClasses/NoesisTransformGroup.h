////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisTransform.h"
#include "NoesisTransformGroup.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisTransformGroup : public UNoesisTransform
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Children
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTransformCollection* GetChildren();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetChildren(class UNoesisTransformCollection* InChildren);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTransform* GetChild(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetNumChildren();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

