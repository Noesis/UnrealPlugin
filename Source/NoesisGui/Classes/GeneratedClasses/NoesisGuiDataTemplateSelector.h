////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiDataTemplateSelector.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiDataTemplateSelector : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiDataTemplate* SelectTemplate(class UNoesisGuiBaseComponent* Item, class UNoesisGuiDependencyObject* Container);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

