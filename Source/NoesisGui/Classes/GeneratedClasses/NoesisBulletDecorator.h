////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDecorator.h"
#include "NoesisBulletDecorator.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBulletDecorator : public UNoesisDecorator
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Background
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetBackground();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBackground(class UNoesisBrush* InBackground);

	// Property Bullet
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisUIElement* GetBullet();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBullet(class UNoesisUIElement* InBullet);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

