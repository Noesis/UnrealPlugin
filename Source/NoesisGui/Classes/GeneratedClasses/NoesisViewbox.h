////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisViewbox.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisViewbox : public UNoesisFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Child
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisUIElement* GetChild();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetChild(class UNoesisUIElement* InChild);

	// Property Stretch
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisStretch GetStretch();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStretch(ENoesisStretch InStretch);

	// Property StretchDirection
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisStretchDirection GetStretchDirection();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetStretchDirection(ENoesisStretchDirection InStretchDirection);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

