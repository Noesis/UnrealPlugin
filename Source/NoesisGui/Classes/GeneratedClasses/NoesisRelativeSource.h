////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisRelativeSource.generated.h"

UCLASS()
class NOESISGUI_API UNoesisRelativeSource : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property AncestorLevel
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetAncestorLevel();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAncestorLevel(int32 InAncestorLevel);

	// Property AncestorType
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisResourceKeyType* GetAncestorType();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAncestorType(class UNoesisResourceKeyType* InAncestorType);

	// Property Mode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisRelativeSourceMode GetMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMode(ENoesisRelativeSourceMode InMode);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

