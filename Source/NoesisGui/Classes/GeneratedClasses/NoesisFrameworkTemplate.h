////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisFrameworkTemplate.generated.h"

UCLASS()
class NOESISGUI_API UNoesisFrameworkTemplate : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Resources
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisResourceDictionary* GetResources();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetResources(class UNoesisResourceDictionary* InResources);

	// Property VisualTree
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisVisual* GetVisualTree();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVisualTree(class UNoesisVisual* InVisualTree);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisFrameworkElement* Apply(class UNoesisFrameworkElement* TemplatedParent, class UNoesisBaseComponent* DataContext);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisBaseComponent* FindName(FString Name, class UNoesisFrameworkElement* TemplatedParent);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisTriggerCollection* GetAvailableTriggers();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

