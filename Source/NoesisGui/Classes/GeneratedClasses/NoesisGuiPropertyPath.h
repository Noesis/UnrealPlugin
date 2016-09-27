////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiPropertyPath.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiPropertyPath : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Path
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetPath();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPath(FString InPath);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

