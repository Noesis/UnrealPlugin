////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiRelativeSource.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiRelativeSource : public UNoesisGuiBaseComponent
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
	class UNoesisGuiResourceKeyType* GetAncestorType();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAncestorType(class UNoesisGuiResourceKeyType* InAncestorType);

	// Property Mode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisGuiRelativeSourceMode GetMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMode(ENoesisGuiRelativeSourceMode InMode);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

