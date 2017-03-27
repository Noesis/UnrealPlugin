////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisICollectionView.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisICollectionView : public UNoesisInterface
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
	bool Contains(class UNoesisBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* CurrentItem();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 CurrentPosition();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsCurrentAfterLast();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsCurrentBeforeFirst();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool IsEmpty();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool MoveCurrentTo(class UNoesisBaseComponent* Item);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

