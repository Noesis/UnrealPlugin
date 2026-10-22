////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// UMGEditor includes
#include "WidgetBlueprint.h"

// NoesisRuntime includes
#include "NoesisInstance.h"

// Generated header include
#include "NoesisBlueprint.generated.h"

UCLASS()
class NOESISEDITOR_API UNoesisBlueprint : public UWidgetBlueprint
{
	GENERATED_BODY()

public:
	UNoesisBlueprint();

	// UBlueprint interface
#if WITH_EDITOR
	virtual UClass* GetBlueprintClass() const override;
	virtual bool SupportedByDefaultBlueprintFactory() const override;
#endif // WITH_EDITOR
	// End of UBlueprint interface

	/** Xaml file that defines the user interface. */
	UPROPERTY(EditAnywhere, Category = "Noesis View", meta = (DisplayName = "XAML"))
	TObjectPtr<class UNoesisXaml> BaseXaml;

	/** Per-Primitive Antialiasing extrudes the contours of the geometry and smooths them. Useful when GPU MSAA is not enabled. */
	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnablePPAA;

	/** When enabled, the view is scaled by the DPI Curve specified in the Project settings. */
	UPROPERTY(EditAnywhere, Category = "Noesis View", meta = (DisplayName = "DPI Scale"))
	bool DPIScale;

	/** Specifies tessellation quality. */
	UPROPERTY(EditAnywhere, Category = "Noesis View")
	ENoesisTessellationQuality TessellationQuality;

	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnableKeyboard;

	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnableMouse;

	UPROPERTY(EditAnywhere, Category = "Noesis View", meta = (EditCondition = "EnableMouse"))
	bool EmulateTouch;

	/** Handled mouse events set user focus to the game viewport. */
	UPROPERTY(EditAnywhere, Category = "Noesis View", meta = (EditCondition = "EnableMouse"))
	bool SetUserFocusToViewport;

	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnableTouch;

	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnableActions;

	/** Set to a positive value, this property is added to the values returned by the PixelDepth node in a Material. */
	UPROPERTY(EditAnywhere, Category = "Noesis View", meta = (DisplayName = "Material PixelDepth Bias"))
	float PixelDepthBias;
};
