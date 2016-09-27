////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseDictionary.h"
#include "NoesisGuiResourceDictionary.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiResourceDictionary : public UNoesisGuiBaseDictionary
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Source
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSource(FString InSource);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

