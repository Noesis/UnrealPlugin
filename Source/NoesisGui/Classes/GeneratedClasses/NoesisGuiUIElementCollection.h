////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiVisualCollection.h"
#include "NoesisGuiUIElementCollection.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiUIElementCollection : public UNoesisGuiVisualCollection
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property LogicalParent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiFrameworkElement* GetLogicalParent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetLogicalParent(class UNoesisGuiFrameworkElement* InLogicalParent);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

