////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiCollection.h"
#include "NoesisGuiVisualCollection.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiVisualCollection : public UNoesisGuiCollection
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property VisualParent
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiVisual* GetVisualParent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVisualParent(class UNoesisGuiVisual* InVisualParent);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

