////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// CoreUObject includes
#include "Blueprint/UserWidget.h"

// UMG includes
#include "Components/Widget.h"

// Noesis includes
#include "NoesisSDK.h"

// NoesisRuntime includes
#include "NoesisBlueprint.h"

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
	float CurrentTime;
	bool FlipYAxis;

	typedef TSharedPtr<class FNoesisSlateElement, ESPMode::ThreadSafe> FNoesisSlateElementPtr;
	FNoesisSlateElementPtr NoesisSlateElement;

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
	void XamlLoaded();

	UFUNCTION(BlueprintImplementableEvent, Category = "NoesisGUI", meta = (DeprecatedFunction, DeprecationMessage = "Use XamlLoaded instead."))
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

	FVector2D GetSize() const;

	TMap<Noesis::TextBox*, TSharedPtr<class NoesisTextBoxTextInputMethodContext> > TextInputMethodContexts;

	void OnPreviewGotKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args);
	void OnPreviewLostKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args);

	bool HitTest(FVector2D Position);

	void TermInstance();

	// UObject interface
	virtual class UWorld* GetWorld() const override;
	virtual void BeginDestroy() override;
	// End of UObject interface

#if WITH_EDITOR
	// UWidget interface
	virtual void SetDesignerFlags(EWidgetDesignFlags NewFlags) override;
	// End of UWidget interface

	void DrawThumbnail(FIntRect ViewportRect, const FTexture2DRHIRef& BackBuffer);
#endif // WITH_EDITOR

	// UUserWidget interface
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	//virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;
	virtual FReply NativeOnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& CharacterEvent) override;
	virtual FReply NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	virtual FReply NativeOnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	virtual FReply NativeOnAnalogValueChanged(const FGeometry& MyGeometry, const FAnalogInputEvent& InAnalogEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply NativeOnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply NativeOnTouchStarted(const FGeometry& MyGeometry, const FPointerEvent& InTouchEvent) override;
	virtual FReply NativeOnTouchMoved(const FGeometry& MyGeometry, const FPointerEvent& InTouchEvent) override;
	virtual FReply NativeOnTouchEnded(const FGeometry& MyGeometry, const FPointerEvent& InTouchEvent) override;
	virtual FCursorReply NativeOnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) override;
	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual bool NativeSupportsKeyboardFocus() const override;
	virtual void InitializeNativeClassData() override;
	// End of UUserWidget interface
};
