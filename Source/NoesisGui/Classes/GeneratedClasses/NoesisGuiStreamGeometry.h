////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiGeometry.h"
#include "NoesisGuiStreamGeometry.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiStreamGeometry : public UNoesisGuiGeometry
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetData(FString Data);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

