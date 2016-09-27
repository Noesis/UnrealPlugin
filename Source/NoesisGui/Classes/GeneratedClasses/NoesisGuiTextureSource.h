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

	// Property DpiX
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetDpiX();

	// Property DpiY
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetDpiY();

	// Property PixelHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetPixelHeight();

	// Property PixelWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetPixelWidth();

	// Property Source
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSource(FString InSource);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

