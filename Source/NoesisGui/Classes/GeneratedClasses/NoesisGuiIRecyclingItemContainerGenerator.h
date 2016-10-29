////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIRecyclingItemContainerGenerator.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIRecyclingItemContainerGenerator : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Recycle(FNoesisGuiGeneratorPosition Position, int32 Count);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

