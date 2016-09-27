////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiCondition.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiCondition : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Binding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseBinding* GetBinding();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBinding(class UNoesisGuiBaseBinding* InBinding);

	// Property Property
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiDependencyProperty* GetProperty();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetProperty(class UNoesisGuiDependencyProperty* InProperty);

	// Property SourceName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSourceName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSourceName(FString InSourceName);

	// Property Value
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseComponent* GetValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetValue(class UNoesisGuiBaseComponent* InValue);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

