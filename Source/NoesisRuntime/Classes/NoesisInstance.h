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

// Engine includes
#include "Components/InputComponent.h"

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
	Noesis::Ptr<Noesis::BaseComponent> DataContext;
	float Left;
	float Top;
	float Width;
	float Height;
	float CurrentTime;
	FSceneInterface* Scene;
	FGameTime WorldTime;
	bool IsGamepadSimulatedClick = false;
	bool Is3DWidget = false;
	mutable bool SupportsKeyboardFocus = true;

	typedef TSharedPtr<class FNoesisSlateElement, ESPMode::ThreadSafe> FNoesisSlateElementPtr;
	FNoesisSlateElementPtr NoesisSlateElement;

	UPROPERTY()
	class UWidgetComponent* WidgetComponent;

	UPROPERTY()
	class UNoesisXaml* BaseXaml;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	bool EnablePPAA;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	ENoesisTessellationQuality TessellationQuality;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	NoesisInstanceRenderFlags RenderFlags;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	bool EnableKeyboard;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	bool EnableMouse;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	bool EmulateTouch;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	bool EnableTouch;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	bool EnableActions;

	UPROPERTY(BlueprintReadWrite, Category = "NoesisGUI")
	float PixelDepthBias;

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

	void Update();

	FVector2D GetSize() const;
	void Init3DWidget(UWorld* World);
	void Term3DWidget(UWorld* World);
	void Tick3DWidget(UWorld* World, ELevelTick TickType, float DeltaTime);
	void ViewportResized();
	void ViewportResized3DWidget();
	static void Add3DElement(UWorld* World, Noesis::FrameworkElement* Element);
	static void Remove3DElement(UWorld* World, Noesis::FrameworkElement* Element);

	TMap<Noesis::TextBox*, TSharedPtr<class NoesisTextBoxTextInputMethodContext> > TextInputMethodContexts;

	void OnPreviewGotKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args);
	void OnPreviewLostKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args);

	bool HitTest(FVector2D Position) const;

	void TermInstance();

	// UObject interface
	virtual void BeginDestroy() override;
	virtual void Serialize(FArchive& Ar);
	virtual void PostLoad();
	// End of UObject interface

	// UWidget interface
	virtual void OnWidgetRebuilt() override;
#if WITH_EDITOR
	virtual void SetDesignerFlags(EWidgetDesignFlags NewFlags) override;
#endif // WITH_EDITOR
	// End of UWidget interface

	void UpdateWorldTime();

	UInputComponent* GetInputComponent();

	void RegisterInputAction(FInputActionBinding Binding);
	void UnregisterInputAction(FInputActionBinding Binding);

#if WITH_ENHANCED_INPUT
	void OnEnhancedInputActionTriggered(Noesis::Key);
	void OnEnhancedInputActionCompleted(Noesis::Key);
	void OnEnhancedInputActionHorizontalScroll(const struct FInputActionValue&);
	void OnEnhancedInputActionVerticalScroll(const struct FInputActionValue&);
#endif

	// UUserWidget interface
	virtual bool Initialize() override;
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
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	// End of UUserWidget interface
};

FDelegateHandle NoesisRegisterOverlayRender();
void NoesisUnregisterOverlayRender(FDelegateHandle InOverlayRenderDelegateHandle);

TSharedPtr<class ISceneViewExtension> NoesisRegisterSceneViewExtension();
void NoesisUnregisterSceneViewExtension(TSharedPtr<class ISceneViewExtension>);

TSharedPtr<class IInputProcessor> NoesisRegisterInputPreProcessor();
void NoesisUnregisterInputPreProcessor(TSharedPtr<class IInputProcessor>);
