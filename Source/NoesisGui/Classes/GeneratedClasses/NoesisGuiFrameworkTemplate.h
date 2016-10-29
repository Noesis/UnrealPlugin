////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiFrameworkTemplate.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiFrameworkTemplate : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Resources
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiResourceDictionary* GetResources();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetResources(class UNoesisGuiResourceDictionary* InResources);

	// Property VisualTree
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiVisual* GetVisualTree();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVisualTree(class UNoesisGuiVisual* InVisualTree);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFrameworkElement* Apply(class UNoesisGuiFrameworkElement* TemplatedParent, class UNoesisGuiBaseComponent* DataContext);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiBaseComponent* FindName(FString Name, class UNoesisGuiFrameworkElement* TemplatedParent);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiTriggerCollection* GetAvailableTriggers();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

