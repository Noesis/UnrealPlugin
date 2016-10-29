////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiImageSource.h"
#include "NoesisGuiTextureSource.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiTextureSource : public UNoesisGuiImageSource
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property PixelHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetPixelHeight();

	// Property PixelWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetPixelWidth();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

