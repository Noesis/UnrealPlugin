////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIRenderer.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIRenderer : public UNoesisGuiInterface
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

