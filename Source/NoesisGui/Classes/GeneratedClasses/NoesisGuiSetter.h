////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBaseSetter.h"
#include "NoesisGuiSetter.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiSetter : public UNoesisGuiBaseSetter
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Property
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiDependencyProperty* GetProperty();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetProperty(class UNoesisGuiDependencyProperty* InProperty);

	// Property TargetName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetTargetName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetTargetName(FString InTargetName);

	// Property Value
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* GetValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetValue(class UNoesisGuiBaseComponent* InValue);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

