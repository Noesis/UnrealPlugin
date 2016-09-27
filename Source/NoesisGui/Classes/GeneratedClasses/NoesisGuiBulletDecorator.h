////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDecorator.h"
#include "NoesisGuiBulletDecorator.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBulletDecorator : public UNoesisGuiDecorator
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Bullet
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiUIElement* GetBullet();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetBullet(class UNoesisGuiUIElement* InBullet);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

