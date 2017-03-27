////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisCondition.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisCondition : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Binding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseBinding* GetBinding();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBinding(class UNoesisBaseBinding* InBinding);

	// Property Property
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisDependencyProperty* GetProperty();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetProperty(class UNoesisDependencyProperty* InProperty);

	// Property SourceName
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSourceName();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSourceName(FString InSourceName);

	// Property Value
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetValue();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetValue(class UNoesisBaseComponent* InValue);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

