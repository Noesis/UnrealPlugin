////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiTemplateBinding.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTemplateBinding : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Property
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiDependencyProperty* GetProperty();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetProperty(class UNoesisGuiDependencyProperty* InProperty);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

