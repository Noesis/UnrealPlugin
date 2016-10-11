////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiICommandSource.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiICommandSource : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiICommand* GetCommand();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* GetCommandParameter();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiUIElement* GetCommandTarget();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

