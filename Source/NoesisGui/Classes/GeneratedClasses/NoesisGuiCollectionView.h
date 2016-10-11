////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiCollectionView.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiCollectionView : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 Count();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* GetItemAt(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiIList* GetSourceCollection();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 IndexOf(class UNoesisGuiBaseComponent* Item);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

