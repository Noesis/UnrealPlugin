////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiICollectionView.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiICollectionView : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CanFilter();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CanGroup();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CanSort();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Contains(class UNoesisGuiBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* CurrentItem();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 CurrentPosition();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsCurrentAfterLast();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsCurrentBeforeFirst();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsEmpty();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool MoveCurrentTo(class UNoesisGuiBaseComponent* Item);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

