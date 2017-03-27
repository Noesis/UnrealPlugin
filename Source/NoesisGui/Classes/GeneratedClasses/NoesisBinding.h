////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseBinding.h"
#include "NoesisBinding.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBinding : public UNoesisBaseBinding
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Converter
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisIValueConverter* GetConverter();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetConverter(class UNoesisIValueConverter* InConverter);

	// Property ConverterParameter
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetConverterParameter();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetConverterParameter(class UNoesisBaseComponent* InConverterParameter);

	// Property ElementName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetElementName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetElementName(FString InElementName);

	// Property Mode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisBindingMode GetMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMode(ENoesisBindingMode InMode);

	// Property Path
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisPropertyPath* GetPath();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPath(class UNoesisPropertyPath* InPath);

	// Property RelativeSource
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisRelativeSource* GetRelativeSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRelativeSource(class UNoesisRelativeSource* InRelativeSource);

	// Property Source
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSource(class UNoesisBaseComponent* InSource);

	// Property UpdateSourceTrigger
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisUpdateSourceTrigger GetUpdateSourceTrigger();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetUpdateSourceTrigger(ENoesisUpdateSourceTrigger InUpdateSourceTrigger);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisObjectWithNameScope GetSourceObject(class UNoesisBaseComponent* Target, const class UNoesisDependencyProperty* TargetProperty);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

