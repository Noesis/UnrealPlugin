////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisItemContainerGenerator.generated.h"

UCLASS()
class NOESISGUI_API UNoesisItemContainerGenerator : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Status
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisGeneratorStatus GetStatus();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisDependencyObject* ContainerFromIndex(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisDependencyObject* ContainerFromItem(class UNoesisBaseComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisDependencyObject* GenerateNext();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisDependencyObject* GenerateNext_(bool& IsNewlyRealized);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisGeneratorPosition GeneratorPositionFromIndex(int32 ItemIndex);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisItemContainerGenerator* GetItemContainerGeneratorForPanel(class UNoesisPanel* Panel);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 IndexFromContainer(class UNoesisDependencyObject* Container);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 IndexFromGeneratorPosition(FNoesisGeneratorPosition Position);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisBaseComponent* ItemFromContainer(class UNoesisDependencyObject* Container);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PrepareItemContainer(class UNoesisDependencyObject* Container);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Remove(FNoesisGeneratorPosition Position, int32 Count);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void RemoveAll();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Stop();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

