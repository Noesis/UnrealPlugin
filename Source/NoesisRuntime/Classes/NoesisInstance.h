////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// CoreUObject includes
#include "Blueprint/UserWidget.h"

// Generated header include
#include "NoesisInstance.generated.h"

UENUM()
enum class NoesisInstanceRenderFlags : uint8
{
	Normal = 0,
	Wireframe = 1,
	ColorBatches = 2,
	Overdraw = 4
};

UCLASS(Blueprintable)
class NOESISRUNTIME_API UNoesisInstance : public UUserWidget
{
	GENERATED_UCLASS_BODY()

	Noesis::Ptr<Noesis::FrameworkElement> Xaml;
	Noesis::Ptr<Noesis::IView> XamlView;
	float Left;
	float Top;
	float Width;
	float Height;
	float StartTime;

	UPROPERTY()
	class UNoesisXaml* BaseXaml;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	bool EnablePPAA;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	ENoesisTessellationQuality TessellationQuality;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	NoesisInstanceRenderFlags RenderFlags;

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI")
	void InitInstance();

	UFUNCTION(BlueprintImplementableEvent, Category = "NoesisGUI")
	void EventInitInstance();

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI")
	void SetDataContext(UObject* DataContext);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI")
	class UObject* FindName(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI")
	class UObject* FindResource(FString Name);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI")
	float GetTimeSeconds() const;

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI")
	void ExecuteConsoleCommand(FString Command, class APlayerController* SpecificPlayer);

	void Update(float InLeft, float InTop, float InWidth, float InHeight);
	void DrawOffscreen_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget);
	void Draw_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget);

	void MouseButtonDown(FVector2D Position, FKey Button);
	void MouseButtonUp(FVector2D Position, FKey Button);
	void MouseDoubleClick(FVector2D Position, FKey Button);
	void MouseMove(FVector2D Position);
	void MouseWheel(FVector2D Position, float WheelDelta);

	void KeyDown(uint32 Key);
	void KeyUp(uint32 Key);
	void Char(TCHAR Character);

	FVector2D GetSize() const;

	TMap<Noesis::TextBox*, TSharedPtr<class NoesisTextBoxTextInputMethodContext> > TextInputMethodContexts;

	void OnPreviewGotKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args);
	void OnPreviewLostKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args);

	// UObject interface
	virtual class UWorld* GetWorld() const override;
	virtual void BeginDestroy() override;
	// End of UObject interface

	// UUserWidget interface
	virtual void InitializeNativeClassData() override;
	virtual TSharedRef<SWidget> RebuildWidget() override;
	// End of UUserWidget interface
};
