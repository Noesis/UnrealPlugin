////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseButton.h"
#include "NoesisButton.generated.h"

UCLASS()
class NOESISGUI_API UNoesisButton : public UNoesisBaseButton
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property IsCancel
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsCancel();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsCancel(bool InIsCancel);

	// Property IsDefault
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsDefault();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsDefault(bool InIsDefault);

	// Property IsDefaulted
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsDefaulted();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

