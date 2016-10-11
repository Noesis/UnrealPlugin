////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIItemContainerGenerator.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIItemContainerGenerator : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiDependencyObject* GenerateNext();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiDependencyObject* GenerateNext_(bool& IsNewlyRealized);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisGuiGeneratorPosition GeneratorPositionFromIndex(int32 ItemIndex);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiItemContainerGenerator* GetItemContainerGeneratorForPanel(class UNoesisGuiPanel* Panel);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
int32 IndexFromGeneratorPosition(FNoesisGuiGeneratorPosition Position);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void PrepareItemContainer(class UNoesisGuiDependencyObject* Container);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Remove(FNoesisGuiGeneratorPosition Position, int32 Count);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void RemoveAll();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Stop();

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

