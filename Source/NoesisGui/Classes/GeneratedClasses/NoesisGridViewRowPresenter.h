////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBaseGridViewRowPresenter.h"
#include "NoesisGridViewRowPresenter.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisGridViewRowPresenter : public UNoesisBaseGridViewRowPresenter
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Content
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetContent();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetContent(class UNoesisBaseComponent* InContent);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

