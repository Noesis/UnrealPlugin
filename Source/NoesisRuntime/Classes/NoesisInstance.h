////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"

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

#if UE_VERSION_OLDER_THAN(5, 0, 0)
struct FGameTime
{
	using FTimeType = float;

	FORCEINLINE_DEBUGGABLE FGameTime()
		: RealTimeSeconds(FTimeType(0))
		, WorldTimeSeconds(FTimeType(0))
		, DeltaRealTimeSeconds(FTimeType(0))
		, DeltaWorldTimeSeconds(FTimeType(0))
	{ }

	FGameTime(const FGameTime&) = default;
	FGameTime& operator = (const FGameTime&) = default;

	// Returns the game time since GStartTime.
	static FGameTime GetTimeSinceAppStart();

	static FORCEINLINE_DEBUGGABLE FGameTime CreateUndilated(FTimeType InRealTimeSeconds, FTimeType InDeltaRealTimeSeconds)
	{
		return FGameTime::CreateDilated(InRealTimeSeconds, InDeltaRealTimeSeconds, InRealTimeSeconds, InDeltaRealTimeSeconds);
	}

	static FORCEINLINE_DEBUGGABLE FGameTime CreateDilated(FTimeType InRealTimeSeconds, FTimeType InDeltaRealTimeSeconds, FTimeType InWorldTimeSeconds, FTimeType InDeltaWorldTimeSeconds)
	{
		return FGameTime(InRealTimeSeconds, InDeltaRealTimeSeconds, InWorldTimeSeconds, InDeltaWorldTimeSeconds);
	}

	/** Returns time in seconds since level began play, but IS NOT paused when the game is paused, and IS NOT dilated/clamped. */
	FORCEINLINE_DEBUGGABLE FTimeType GetRealTimeSeconds() const
	{
		return RealTimeSeconds;
	}

	/** Returns frame delta time in seconds with no adjustment for time dilation and pause. */
	FORCEINLINE_DEBUGGABLE FTimeType GetDeltaRealTimeSeconds() const
	{
		return DeltaRealTimeSeconds;
	}

	/** Returns time in seconds since level began play, but IS paused when the game is paused, and IS dilated/clamped. */
	FORCEINLINE_DEBUGGABLE FTimeType GetWorldTimeSeconds() const
	{
		return WorldTimeSeconds;
	}

	/** Returns frame delta time in seconds adjusted by e.g. time dilation. */
	FORCEINLINE_DEBUGGABLE FTimeType GetDeltaWorldTimeSeconds() const
	{
		return DeltaWorldTimeSeconds;
	}

	/** Returns how much world time is slowed compared to real time. */
	FORCEINLINE_DEBUGGABLE float GetTimeDilation() const
	{
		ensure(DeltaRealTimeSeconds > FTimeType(0));
		return float(DeltaWorldTimeSeconds / DeltaRealTimeSeconds);
	}

	/** Returns whether the world time is paused. */
	FORCEINLINE_DEBUGGABLE bool IsPaused() const
	{
		return DeltaWorldTimeSeconds == FTimeType(0);
	}

private:
	FTimeType RealTimeSeconds;
	FTimeType WorldTimeSeconds;

	FTimeType DeltaRealTimeSeconds;
	FTimeType DeltaWorldTimeSeconds;

	FORCEINLINE_DEBUGGABLE FGameTime(FTimeType InRealTimeSeconds, FTimeType InDeltaRealTimeSeconds, FTimeType InWorldTimeSeconds, FTimeType InDeltaWorldTimeSeconds)
		: RealTimeSeconds(InRealTimeSeconds)
		, WorldTimeSeconds(InWorldTimeSeconds)
		, DeltaRealTimeSeconds(InDeltaRealTimeSeconds)
		, DeltaWorldTimeSeconds(InDeltaWorldTimeSeconds)
	{ }

};
#endif

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
	FSceneInterface* Scene;
	FGameTime WorldTime;
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

	static UNoesisInstance* FromView(Noesis::IView* View);

	void Update(float InLeft, float InTop, float InWidth, float InHeight);

	FVector2D GetSize() const;

	TMap<Noesis::TextBox*, TSharedPtr<class NoesisTextBoxTextInputMethodContext> > TextInputMethodContexts;

	void OnPreviewGotKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args);
	void OnPreviewLostKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args);

	bool HitTest(FVector2D Position);

	void TermInstance();

	// UObject interface
	virtual void BeginDestroy() override;
	virtual void Serialize(FArchive& Ar);
	virtual void PostLoad();
	// End of UObject interface

#if WITH_EDITOR
	// UWidget interface
	virtual void SetDesignerFlags(EWidgetDesignFlags NewFlags) override;
	// End of UWidget interface

	void DrawThumbnail(FIntRect ViewportRect, const FTexture2DRHIRef& BackBuffer);
#endif // WITH_EDITOR

	void UpdateWorldTime();

	void RegisterInputAction(FInputActionBinding Binding);
	void UnregisterInputAction(FInputActionBinding Binding);

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

