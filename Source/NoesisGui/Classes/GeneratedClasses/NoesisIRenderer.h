////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisInterface.h"
#include "NoesisIRenderer.generated.h"

UCLASS()
class NOESISGUI_API UNoesisIRenderer : public UNoesisInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool NeedsOffscreen();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Render();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void RenderOffscreen();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetRenderRegion(float X, float Y, float Width, float Height);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Shutdown();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool UpdateRenderTree();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

