////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisInstance.h"

// Core includes
#include "Stats/Stats.h"
#include "Stats/Stats2.h"

// Engine includes
#include "SceneUtils.h"

// RenderCore includes
#include "RenderingThread.h"

// UtilityShaders includes
#include "ClearQuad.h"

// ApplicationCore includes
#include "HAL/PlatformApplicationMisc.h"
#include "GenericPlatform/ITextInputMethodSystem.h"

// Slate includes
#include "Widgets/SWindow.h"
#include "Framework/Application/SlateApplication.h"

// NoesisRuntime includes
#include "NoesisRuntimeModule.h"
#include "NoesisBlueprintGeneratedClass.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisTypeClass.h"
#include "NoesisXaml.h"
#include "NoesisSupport.h"

DECLARE_CYCLE_STAT(TEXT("NoesisInstance::Update"), STAT_NoesisInstance_Update, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::DrawOffscreen_RenderThread"), STAT_NoesisInstance_DrawOffscreen, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::Draw_RenderThread"), STAT_NoesisInstance_Draw, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnKeyChar"), STAT_NoesisInstance_OnKeyChar, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnKeyDown"), STAT_NoesisInstance_OnKeyDown, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnKeyUp"), STAT_NoesisInstance_OnKeyUp, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnMouseButtonDown"), STAT_NoesisInstance_OnMouseButtonDown, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnMouseButtonUp"), STAT_NoesisInstance_OnMouseButtonUp, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnMouseMove"), STAT_NoesisInstance_OnMouseMove, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnMouseWheel"), STAT_NoesisInstance_OnMouseWheel, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnTouchStarted"), STAT_NoesisInstance_OnTouchStarted, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnTouchMoved"), STAT_NoesisInstance_OnTouchMoved, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnTouchEnded"), STAT_NoesisInstance_OnTouchEnded, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnMouseButtonDoubleClick"), STAT_NoesisInstance_OnMouseButtonDoubleClick, STATGROUP_Noesis);

class FNoesisSlateElement : public ICustomSlateElement
{
public:
	FNoesisSlateElement(class UNoesisInstance* InNoesisInstance);

	// ICustomSlateElement interface
	virtual void DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer) override;
	// End of ICustomSlateElement interface

	class UNoesisInstance* NoesisInstance;

	float Left;
	float Top;
	float Right;
	float Bottom;
};

FNoesisSlateElement::FNoesisSlateElement(class UNoesisInstance* InNoesisInstance)
	: NoesisInstance(InNoesisInstance)
{
}

void FNoesisSlateElement::DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer)
{
	if (NoesisInstance)
	{
		RHICmdList.SetViewport(Left, Top, 0.0f, Right, Bottom, 1.0f);
		DrawClearQuad(RHICmdList, false, FLinearColor::Black, false, 0.0f, true, 0);
		NoesisInstance->Draw_RenderThread(RHICmdList, 0, 0);
	}
}

class NoesisTextBoxTextInputMethodContext : public ITextInputMethodContext
{
public:
	NoesisTextBoxTextInputMethodContext(Noesis::TextBox* InTextBox, TWeakPtr<SWindow> InWindow, UNoesisInstance* InNoesisInstance)
		: TextBox(InTextBox), Window(InWindow), NoesisInstance(InNoesisInstance)
	{
		check(TextBox);
	}

	virtual bool IsComposing() override
	{
		return TextBox->GetNumCompositionUnderlines() != 0;
	}

	virtual bool IsReadOnly() override
	{
		return TextBox->GetIsReadOnly();
	}

	virtual uint32 GetTextLength() override
	{
		return NsStringToFString(TextBox->GetText()).Len();
	}

	virtual void GetSelectionRange(uint32& OutBeginIndex, uint32& OutLength, ITextInputMethodContext::ECaretPosition& OutCaretPosition) override
	{
		int32 CaretIndex = TextBox->GetCaretIndex();
		OutBeginIndex = TextBox->GetSelectionStart();
		OutLength = TextBox->GetSelectionLength();
		OutCaretPosition = (CaretIndex < (int32)OutBeginIndex) ? ITextInputMethodContext::ECaretPosition::Beginning : ITextInputMethodContext::ECaretPosition::Ending;
	}

	virtual void SetSelectionRange(const uint32 InBeginIndex, const uint32 InLength, const ITextInputMethodContext::ECaretPosition InCaretPosition) override
	{
		TextBox->SetCaretIndex((InCaretPosition == ITextInputMethodContext::ECaretPosition::Beginning) ? InBeginIndex : InBeginIndex + InLength);
		TextBox->SetSelectionStart(InBeginIndex);
		TextBox->SetSelectionLength(InLength);
	}

	virtual void GetTextInRange(const uint32 InBeginIndex, const uint32 InLength, FString& OutString) override
	{
		OutString = NsStringToFString(TextBox->GetText()).RightChop(InBeginIndex).Left(InLength);
	}

	virtual void SetTextInRange(const uint32 InBeginIndex, const uint32 InLength, const FString& InString) override
	{
		FString CurrentText = NsStringToFString(TextBox->GetText());
		FString NewText = CurrentText.Left(InBeginIndex) + InString + CurrentText.RightChop(InBeginIndex + InLength);
		TextBox->SetText(TCHARToNsString(*NewText).c_str());
		UpdateCompositionRange(InBeginIndex, InString.Len());
	}

	virtual int32 GetCharacterIndexFromPoint(const FVector2D& InPoint) override
	{
		return INDEX_NONE;
	}

	virtual bool GetTextBounds(const uint32 InBeginIndex, const uint32 InLength, FVector2D& OutPosition, FVector2D& OutSize) override
	{
		Noesis::Rect TextRangeBounds = TextBox->GetRangeBounds(InBeginIndex, InBeginIndex + InLength);
		Noesis::Visual* ContentHost = TextBox->GetContentHost();

		if (Noesis::ScrollViewer* ScrollViewer = NsDynamicCast<Noesis::ScrollViewer*>(ContentHost))
		{
			ContentHost = ScrollViewer;
		}
		else if (Noesis::Decorator* Decorator = NsDynamicCast<Noesis::Decorator*>(ContentHost))
		{
			ContentHost = Decorator;
		}
		Noesis::Point TopLeft = ContentHost->PointToScreen(TextRangeBounds.GetTopLeft());
		Noesis::Point BottomRight = ContentHost->PointToScreen(TextRangeBounds.GetBottomRight());
		OutPosition.X = TopLeft.x + NoesisInstance->Left;
		OutPosition.Y = TopLeft.y + NoesisInstance->Top;
		OutSize.X = BottomRight.x - TopLeft.x;
		OutSize.Y = BottomRight.y - TopLeft.y;

		return false;
	}

	virtual void GetScreenBounds(FVector2D& OutPosition, FVector2D& OutSize) override
	{
		OutPosition.X = NoesisInstance->Left;
		OutPosition.Y = NoesisInstance->Top;
		OutSize.X = NoesisInstance->Width;
		OutSize.Y = NoesisInstance->Height;
	}

	virtual TSharedPtr<FGenericWindow> GetWindow() override
	{
		const TSharedPtr<SWindow> SlateWindow = Window.Pin();
		return SlateWindow.IsValid() ? SlateWindow->GetNativeWindow() : nullptr;
	}

	virtual void BeginComposition() override
	{
		check(TextBox->GetNumCompositionUnderlines() == 0);

		Noesis::CompositionUnderline CompositionUnderline;
		CompositionUnderline.start = TextBox->GetCaretIndex();
		CompositionUnderline.end = TextBox->GetCaretIndex();
		CompositionUnderline.style = Noesis::CompositionLineStyle_Solid;
		CompositionUnderline.bold = false;
		TextBox->AddCompositionUnderline(CompositionUnderline);
	}

	virtual void UpdateCompositionRange(const int32 InBeginIndex, const uint32 InLength) override
	{
		check(TextBox->GetNumCompositionUnderlines() == 1);

		TextBox->ClearCompositionUnderlines();

		Noesis::CompositionUnderline CompositionUnderline;
		CompositionUnderline.start = InBeginIndex;
		CompositionUnderline.end = InBeginIndex + InLength;
		CompositionUnderline.style = Noesis::CompositionLineStyle_Solid;
		CompositionUnderline.bold = false;
		TextBox->AddCompositionUnderline(CompositionUnderline);
	}

	virtual void EndComposition() override
	{
		check(TextBox->GetNumCompositionUnderlines() == 1);

		TextBox->ClearCompositionUnderlines();
	}

private:
	Noesis::TextBox* TextBox;
	TWeakPtr<SWindow> Window;
	UNoesisInstance* NoesisInstance;
};

UNoesisInstance::UNoesisInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Visibility = ESlateVisibility::Visible;
}

void UNoesisInstance::InitInstance()
{
	ULocalPlayer* Player = 0;
	int32 ZOrder = 0;

	if (!BaseXaml)
	{
		UNoesisBlueprintGeneratedClass* NoesisBlueprintGeneratedClass = CastChecked<UNoesisBlueprintGeneratedClass>(GetClass());
		check(NoesisBlueprintGeneratedClass);
		BaseXaml = NoesisBlueprintGeneratedClass->BaseXaml;
		EnablePPAA = NoesisBlueprintGeneratedClass->EnablePPAA;
		TessellationQuality = NoesisBlueprintGeneratedClass->TessellationQuality;

		if (!BaseXaml)
			return;
	}

	Noesis::Ptr<Noesis::BaseComponent> DataContext = Noesis::Ptr<Noesis::BaseComponent>(NoesisCreateComponentForUObject(this));

	Xaml.Reset(NsDynamicCast<Noesis::FrameworkElement*>(BaseXaml->LoadXaml().GetPtr()));

	if (Xaml)
	{
		Xaml->SetDataContext(DataContext.GetPtr());

		XamlView = Noesis::GUI::CreateView(Xaml.GetPtr());

		if (XamlView)
		{
			Noesis::IRenderer* Renderer = XamlView->GetRenderer();
			Renderer->Init(FNoesisRenderDevice::Get());

			StartTime = GetTimeSeconds();

			EventInitInstance();
		}

		Xaml->PreviewGotKeyboardFocus() += Noesis::MakeDelegate(this, &UNoesisInstance::OnPreviewGotKeyboardFocus);
		Xaml->PreviewLostKeyboardFocus() += Noesis::MakeDelegate(this, &UNoesisInstance::OnPreviewLostKeyboardFocus);

		NoesisSlateElement = MakeShared<FNoesisSlateElement, ESPMode::ThreadSafe>(this);
	}
}

void UNoesisInstance::SetDataContext(UObject* InDataContext)
{
	if (Xaml)
	{
		Noesis::Ptr<Noesis::BaseComponent> DataContext = Noesis::Ptr<Noesis::BaseComponent>(NoesisCreateComponentForUObject(InDataContext));

		Xaml->SetDataContext(DataContext.GetPtr());
	}
}

UObject* UNoesisInstance::FindName(FString Name)
{
	Noesis::BaseComponent* Component = Xaml->FindName(TCHARToNsString(*Name).c_str());
	return NoesisCreateUObjectForComponent(Component);
}

UObject* UNoesisInstance::FindResource(FString Name)
{
	Noesis::Ptr<Noesis::ResourceKeyString> Key = Noesis::ResourceKeyString::Create(TCHARToNsString(*Name).c_str());
	Noesis::BaseComponent* Resource = Xaml->FindResource(Key.GetPtr());
	return NoesisCreateUObjectForComponent(Resource);
}

float UNoesisInstance::GetTimeSeconds() const
{
	APlayerController* OwningPlayer = GetOwningPlayer();
	if (OwningPlayer)
	{
		UWorld* World = OwningPlayer->GetWorld();
		if (World)
		{
			return World->GetTimeSeconds();
		}
	}

	if (GWorld)
	{
		return GWorld->GetTimeSeconds();
	}

	return -1.f;
}

void UNoesisInstance::ExecuteConsoleCommand(FString Command, class APlayerController* SpecificPlayer)
{
	APlayerController* TargetPC = SpecificPlayer;
	if (!TargetPC)
	{
		APlayerController* OwningPlayer = GetOwningPlayer();
		if (OwningPlayer)
		{
			UWorld* World = OwningPlayer->GetWorld();
			if (World)
			{
				TargetPC = World->GetFirstPlayerController();
			}
		}
	}

	if (TargetPC)
	{
		TargetPC->ConsoleCommand(*Command);
	}
}

void UNoesisInstance::Update(float InLeft, float InTop, float InWidth, float InHeight)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_Update);
	Left = InLeft;
	Top = InTop;
	Width = InWidth;
	Height = InHeight;
	if (Xaml && XamlView)
	{
		XamlView->SetSize(Width, Height);
		XamlView->SetIsPPAAEnabled(EnablePPAA);
		XamlView->SetTessellationQuality((Noesis::TessellationQuality)TessellationQuality);
		XamlView->SetFlags((uint32)RenderFlags);
		XamlView->Update(GetTimeSeconds() - StartTime);
	}
}

void UNoesisInstance::DrawOffscreen_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_DrawOffscreen);
	if (XamlView)
	{
		SCOPED_DRAW_EVENT(RHICmdList, NoesisDrawOffscreen);
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(&RHICmdList);
		Noesis::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->UpdateRenderTree();
		if (Renderer->NeedsOffscreen())
		{
			Renderer->RenderOffscreen();
		}
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(nullptr);
	}
}

void UNoesisInstance::Draw_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_Draw);
	if (XamlView)
	{
		SCOPED_DRAW_EVENT(RHICmdList, NoesisDraw);
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(&RHICmdList);
		Noesis::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->Render(FlipYAxis);
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(nullptr);
	}
}

FVector2D UNoesisInstance::GetSize() const
{
	if (Xaml)
	{
		return FVector2D(Xaml->GetActualWidth(), Xaml->GetActualHeight());
	}
	return FVector2D();
}

void UNoesisInstance::OnPreviewGotKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args)
{
	const Noesis::TypeClass* NewFocusClass = Args.newFocus->GetClassType();
	const Noesis::TypeClass* TextBoxClass = Noesis::TextBox::StaticGetClassType();
	if (!FPlatformApplicationMisc::RequiresVirtualKeyboard())
	{
		if (NewFocusClass == TextBoxClass || NewFocusClass->IsDescendantOf(TextBoxClass))
		{
			ITextInputMethodSystem* const TextInputMethodSystem = FSlateApplication::IsInitialized() ? FSlateApplication::Get().GetTextInputMethodSystem() : nullptr;
			if (TextInputMethodSystem)
			{
				TSharedPtr<NoesisTextBoxTextInputMethodContext> TextInputMethodContext = nullptr;
				TSharedPtr<NoesisTextBoxTextInputMethodContext>* TextInputMethodContextPtr = TextInputMethodContexts.Find((Noesis::TextBox*)Args.newFocus);
				if (TextInputMethodContextPtr)
				{
					TextInputMethodContext = *TextInputMethodContextPtr;
				}
				else
				{
					TSharedPtr<SWidget> PinnedWidget(MyWidget.Pin());
					if (PinnedWidget.IsValid())
					{
						TWeakPtr<SWindow> Window = FSlateApplication::Get().FindWidgetWindow(PinnedWidget.ToSharedRef());
						TextInputMethodContext = MakeShareable(new NoesisTextBoxTextInputMethodContext((Noesis::TextBox*)Args.newFocus, Window, this));
						TextInputMethodContexts.Add((Noesis::TextBox*)Args.newFocus, TextInputMethodContext);
						TextInputMethodSystem->RegisterContext(TextInputMethodContext.ToSharedRef());
					}
				}

				if (TextInputMethodContext.IsValid())
				{
					TextInputMethodSystem->ActivateContext(TextInputMethodContext.ToSharedRef());
				}
			}
		}
	}
}

void UNoesisInstance::OnPreviewLostKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args)
{
	const Noesis::TypeClass* OldFocusClass = Args.oldFocus->GetClassType();
	const Noesis::TypeClass* TextBoxClass = Noesis::TextBox::StaticGetClassType();
	if (!FPlatformApplicationMisc::RequiresVirtualKeyboard())
	{
		if (OldFocusClass == TextBoxClass || OldFocusClass->IsDescendantOf(TextBoxClass))
		{
			ITextInputMethodSystem* const TextInputMethodSystem = FSlateApplication::IsInitialized() ? FSlateApplication::Get().GetTextInputMethodSystem() : nullptr;
			if (TextInputMethodSystem)
			{
				TSharedPtr<NoesisTextBoxTextInputMethodContext> TextInputMethodContext = nullptr;
				TSharedPtr<NoesisTextBoxTextInputMethodContext>* TextInputMethodContextPtr = TextInputMethodContexts.Find((Noesis::TextBox*)Args.oldFocus);
				if (TextInputMethodContextPtr)
				{
					TextInputMethodContext = *TextInputMethodContextPtr;
					TextInputMethodSystem->DeactivateContext(TextInputMethodContext.ToSharedRef());
				}
			}
		}
	}
}

struct NoesisHitTestVisibleTester
{
	NoesisHitTestVisibleTester()
		: Hit(nullptr)
	{
	}

	void OnElementHit(Noesis::Visual* Visual)
	{
		if (!Hit)
		{
			Noesis::UIElement* Element = NsDynamicCast<Noesis::UIElement*>(Visual);
			if (Element && Element->GetIsEnabled())
			{
				Hit = Element;
			}
		}
	}

	Noesis::UIElement* Hit;
};

bool UNoesisInstance::HitTest(FVector2D Position)
{
	NoesisHitTestVisibleTester HitTester;
	Noesis::VisualTreeHelper::HitTest(Xaml.GetPtr(), Noesis::Point(Position.X, Position.Y), MakeDelegate(&HitTester, &NoesisHitTestVisibleTester::OnElementHit));

	return HitTester.Hit != nullptr;
}

void UNoesisInstance::TermInstance()
{
	if (XamlView)
	{
		Noesis::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->Shutdown();
		XamlView.Reset();
		Xaml.Reset();

		// Pass the slate element to the render thread so that it's deleted after it's shown for the last time
		ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER
		(
			SafeDeleteNoesisSlateElement,
			FNoesisSlateElementPtr, NoesisSlateElement, NoesisSlateElement,
			{
				NoesisSlateElement.Reset();
			}
		);
	}

	ITextInputMethodSystem* const TextInputMethodSystem = FSlateApplication::IsInitialized() ? FSlateApplication::Get().GetTextInputMethodSystem() : nullptr;
	if (TextInputMethodSystem)
	{
		for (auto TextInputMethodContextPair : TextInputMethodContexts)
		{
			TextInputMethodSystem->UnregisterContext(TextInputMethodContextPair.Value.ToSharedRef());
		}
	}
}

class UWorld* UNoesisInstance::GetWorld() const
{
	UObject* Outer = GetOuter();

	while (Outer)
	{
		UWorld* World = Outer->GetWorld();
		if (World)
		{
			return World;
		}

		Outer = Outer->GetOuter();
	}

	return 0;
}

void UNoesisInstance::BeginDestroy()
{
	Super::BeginDestroy();

	TermInstance();
}

#if WITH_EDITOR
void UNoesisInstance::SetDesignerFlags(EWidgetDesignFlags::Type NewFlags)
{
	// Enable native events in editor
	Super::SetDesignerFlags((EWidgetDesignFlags::Type)(NewFlags & ~EWidgetDesignFlags::Designing));
}
#endif // WITH_EDITOR

void UNoesisInstance::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	FlipYAxis = IsInViewport() && RHINeedsToSwitchVerticalAxis(GShaderPlatformForFeatureLevel[GMaxRHIFeatureLevel]);

	FVector2D AbsolutePosition = MyGeometry.GetAbsolutePosition();
	FVector2D AbsoluteSize = MyGeometry.GetAbsoluteSize();
	Update(AbsolutePosition.X, AbsolutePosition.Y, AbsoluteSize.X, AbsoluteSize.Y);
}

int32 UNoesisInstance::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	int32 MaxLayer = Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	if (XamlView)
	{
		ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(FNoesisInstance_DrawOffscreen,
			UNoesisInstance*, NoesisInstance, (UNoesisInstance*)this,
			{
				NoesisInstance->DrawOffscreen_RenderThread(RHICmdList, 0, 0);
			});

		const FSlateRect& MyClippingRect = MyCullingRect;

		NoesisSlateElement->Left = MyClippingRect.Left;
		NoesisSlateElement->Top = MyClippingRect.Top;
		NoesisSlateElement->Right = MyClippingRect.Right;
		NoesisSlateElement->Bottom = MyClippingRect.Bottom;
		// Push an unaligned clip zone to force Slate to create a stencil buffer
		FVector2D TopLeft(MyClippingRect.Left - 1, MyClippingRect.Top - 1);
		FVector2D TopRight(MyClippingRect.Right, MyClippingRect.Top);
		FVector2D BottomLeft(MyClippingRect.Left, MyClippingRect.Bottom);
		FVector2D BottomRight(MyClippingRect.Right + 1, MyClippingRect.Bottom + 1);
		FSlateClippingZone Clip(TopLeft, TopRight, BottomLeft, BottomRight);
		OutDrawElements.PushClip(Clip);
		FSlateDrawElement::MakeCustom(OutDrawElements, LayerId, NoesisSlateElement);
		OutDrawElements.PopClip();

		MaxLayer = FMath::Max(MaxLayer, LayerId);
	}

	return MaxLayer;
}

FReply UNoesisInstance::NativeOnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& CharacterEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnKeyChar);
	if (XamlView)
	{
		TCHAR Character = CharacterEvent.GetCharacter();

		XamlView->Char(CharCast<char>(Character));
	}

	return Super::NativeOnKeyChar(MyGeometry, CharacterEvent);
}

Noesis::Key KeyToNoesisKey(FKey Key)
{
	Noesis::Key NoesisKey = Noesis::Key_None;
	if (Key == EKeys::BackSpace)
	{
		NoesisKey = Noesis::Key_Back;
	}
	else if (Key == EKeys::Tab)
	{
		NoesisKey = Noesis::Key_Tab;
	}
	else if (Key == EKeys::Enter)
	{
		NoesisKey = Noesis::Key_Enter;
	}
	else if (Key == EKeys::Pause)
	{
		NoesisKey = Noesis::Key_Pause;
	}
	else if (Key == EKeys::CapsLock)
	{
		NoesisKey = Noesis::Key_CapsLock;
	}
	else if (Key == EKeys::Escape)
	{
		NoesisKey = Noesis::Key_Escape;
	}
	else if (Key == EKeys::SpaceBar)
	{
		NoesisKey = Noesis::Key_Space;
	}
	else if (Key == EKeys::PageUp)
	{
		NoesisKey = Noesis::Key_PageUp;
	}
	else if (Key == EKeys::PageDown)
	{
		NoesisKey = Noesis::Key_PageDown;
	}
	else if (Key == EKeys::End)
	{
		NoesisKey = Noesis::Key_End;
	}
	else if (Key == EKeys::Home)
	{
		NoesisKey = Noesis::Key_Home;
	}
	else if (Key == EKeys::Left)
	{
		NoesisKey = Noesis::Key_Left;
	}
	else if (Key == EKeys::Up)
	{
		NoesisKey = Noesis::Key_Up;
	}
	else if (Key == EKeys::Right)
	{
		NoesisKey = Noesis::Key_Right;
	}
	else if (Key == EKeys::Down)
	{
		NoesisKey = Noesis::Key_Down;
	}
	else if (Key == EKeys::Insert)
	{
		NoesisKey = Noesis::Key_Insert;
	}
	else if (Key == EKeys::Delete)
	{
		NoesisKey = Noesis::Key_Delete;
	}
	else if (Key == EKeys::Zero)
	{
		NoesisKey = Noesis::Key_D0;
	}
	else if (Key == EKeys::One)
	{
		NoesisKey = Noesis::Key_D1;
	}
	else if (Key == EKeys::Two)
	{
		NoesisKey = Noesis::Key_D2;
	}
	else if (Key == EKeys::Three)
	{
		NoesisKey = Noesis::Key_D3;
	}
	else if (Key == EKeys::Four)
	{
		NoesisKey = Noesis::Key_D4;
	}
	else if (Key == EKeys::Five)
	{
		NoesisKey = Noesis::Key_D5;
	}
	else if (Key == EKeys::Six)
	{
		NoesisKey = Noesis::Key_D6;
	}
	else if (Key == EKeys::Seven)
	{
		NoesisKey = Noesis::Key_D7;
	}
	else if (Key == EKeys::Eight)
	{
		NoesisKey = Noesis::Key_D8;
	}
	else if (Key == EKeys::Nine)
	{
		NoesisKey = Noesis::Key_D9;
	}
	else if (Key == EKeys::A)
	{
		NoesisKey = Noesis::Key_A;
	}
	else if (Key == EKeys::B)
	{
		NoesisKey = Noesis::Key_B;
	}
	else if (Key == EKeys::C)
	{
		NoesisKey = Noesis::Key_C;
	}
	else if (Key == EKeys::D)
	{
		NoesisKey = Noesis::Key_D;
	}
	else if (Key == EKeys::E)
	{
		NoesisKey = Noesis::Key_E;
	}
	else if (Key == EKeys::F)
	{
		NoesisKey = Noesis::Key_F;
	}
	else if (Key == EKeys::G)
	{
		NoesisKey = Noesis::Key_G;
	}
	else if (Key == EKeys::H)
	{
		NoesisKey = Noesis::Key_H;
	}
	else if (Key == EKeys::I)
	{
		NoesisKey = Noesis::Key_I;
	}
	else if (Key == EKeys::J)
	{
		NoesisKey = Noesis::Key_J;
	}
	else if (Key == EKeys::K)
	{
		NoesisKey = Noesis::Key_K;
	}
	else if (Key == EKeys::L)
	{
		NoesisKey = Noesis::Key_L;
	}
	else if (Key == EKeys::M)
	{
		NoesisKey = Noesis::Key_M;
	}
	else if (Key == EKeys::N)
	{
		NoesisKey = Noesis::Key_N;
	}
	else if (Key == EKeys::O)
	{
		NoesisKey = Noesis::Key_O;
	}
	else if (Key == EKeys::P)
	{
		NoesisKey = Noesis::Key_P;
	}
	else if (Key == EKeys::Q)
	{
		NoesisKey = Noesis::Key_Q;
	}
	else if (Key == EKeys::R)
	{
		NoesisKey = Noesis::Key_R;
	}
	else if (Key == EKeys::S)
	{
		NoesisKey = Noesis::Key_S;
	}
	else if (Key == EKeys::T)
	{
		NoesisKey = Noesis::Key_T;
	}
	else if (Key == EKeys::U)
	{
		NoesisKey = Noesis::Key_U;
	}
	else if (Key == EKeys::V)
	{
		NoesisKey = Noesis::Key_V;
	}
	else if (Key == EKeys::W)
	{
		NoesisKey = Noesis::Key_W;
	}
	else if (Key == EKeys::X)
	{
		NoesisKey = Noesis::Key_X;
	}
	else if (Key == EKeys::Y)
	{
		NoesisKey = Noesis::Key_Y;
	}
	else if (Key == EKeys::Z)
	{
		NoesisKey = Noesis::Key_Z;
	}
	else if (Key == EKeys::NumPadZero)
	{
		NoesisKey = Noesis::Key_NumPad0;
	}
	else if (Key == EKeys::NumPadOne)
	{
		NoesisKey = Noesis::Key_NumPad1;
	}
	else if (Key == EKeys::NumPadTwo)
	{
		NoesisKey = Noesis::Key_NumPad2;
	}
	else if (Key == EKeys::NumPadThree)
	{
		NoesisKey = Noesis::Key_NumPad3;
	}
	else if (Key == EKeys::NumPadFour)
	{
		NoesisKey = Noesis::Key_NumPad4;
	}
	else if (Key == EKeys::NumPadFive)
	{
		NoesisKey = Noesis::Key_NumPad5;
	}
	else if (Key == EKeys::NumPadSix)
	{
		NoesisKey = Noesis::Key_NumPad6;
	}
	else if (Key == EKeys::NumPadSeven)
	{
		NoesisKey = Noesis::Key_NumPad7;
	}
	else if (Key == EKeys::NumPadEight)
	{
		NoesisKey = Noesis::Key_NumPad8;
	}
	else if (Key == EKeys::NumPadNine)
	{
		NoesisKey = Noesis::Key_NumPad9;
	}
	else if (Key == EKeys::Multiply)
	{
		NoesisKey = Noesis::Key_Multiply;
	}
	else if (Key == EKeys::Add)
	{
		NoesisKey = Noesis::Key_Add;
	}
	else if (Key == EKeys::Subtract)
	{
		NoesisKey = Noesis::Key_Subtract;
	}
	else if (Key == EKeys::Decimal)
	{
		NoesisKey = Noesis::Key_Decimal;
	}
	else if (Key == EKeys::Divide)
	{
		NoesisKey = Noesis::Key_Divide;
	}
	else if (Key == EKeys::F1)
	{
		NoesisKey = Noesis::Key_F1;
	}
	else if (Key == EKeys::F2)
	{
		NoesisKey = Noesis::Key_F2;
	}
	else if (Key == EKeys::F3)
	{
		NoesisKey = Noesis::Key_F3;
	}
	else if (Key == EKeys::F4)
	{
		NoesisKey = Noesis::Key_F4;
	}
	else if (Key == EKeys::F5)
	{
		NoesisKey = Noesis::Key_F5;
	}
	else if (Key == EKeys::F6)
	{
		NoesisKey = Noesis::Key_F6;
	}
	else if (Key == EKeys::F7)
	{
		NoesisKey = Noesis::Key_F7;
	}
	else if (Key == EKeys::F8)
	{
		NoesisKey = Noesis::Key_F8;
	}
	else if (Key == EKeys::F9)
	{
		NoesisKey = Noesis::Key_F9;
	}
	else if (Key == EKeys::F10)
	{
		NoesisKey = Noesis::Key_F10;
	}
	else if (Key == EKeys::F11)
	{
		NoesisKey = Noesis::Key_F11;
	}
	else if (Key == EKeys::F12)
	{
		NoesisKey = Noesis::Key_F12;
	}
	else if (Key == EKeys::NumLock)
	{
		NoesisKey = Noesis::Key_NumLock;
	}
	else if (Key == EKeys::ScrollLock)
	{
		NoesisKey = Noesis::Key_Scroll;
	}
	else if (Key == EKeys::LeftShift)
	{
		NoesisKey = Noesis::Key_LeftShift;
	}
	else if (Key == EKeys::RightShift)
	{
		NoesisKey = Noesis::Key_RightShift;
	}
	else if (Key == EKeys::LeftControl)
	{
		NoesisKey = Noesis::Key_LeftCtrl;
	}
	else if (Key == EKeys::RightControl)
	{
		NoesisKey = Noesis::Key_RightCtrl;
	}
	else if (Key == EKeys::LeftAlt)
	{
		NoesisKey = Noesis::Key_LeftAlt;
	}
	else if (Key == EKeys::RightAlt)
	{
		NoesisKey = Noesis::Key_RightAlt;
	}
	else if (Key == EKeys::LeftCommand)
	{
		NoesisKey = Noesis::Key_LWin;
	}
	else if (Key == EKeys::RightCommand)
	{
		NoesisKey = Noesis::Key_RWin;
	}
	else if (Key == EKeys::Semicolon)
	{
		NoesisKey = Noesis::Key_OemSemicolon;
	}
	else if (Key == EKeys::Comma)
	{
		NoesisKey = Noesis::Key_OemComma;
	}
	else if (Key == EKeys::Period)
	{
		NoesisKey = Noesis::Key_OemPeriod;
	}
	else if (Key == EKeys::Tilde)
	{
		NoesisKey = Noesis::Key_OemTilde;
	}
	else if (Key == EKeys::LeftBracket)
	{
		NoesisKey = Noesis::Key_OemOpenBrackets;
	}
	else if (Key == EKeys::Backslash)
	{
		NoesisKey = Noesis::Key_OemBackslash;
	}
	else if (Key == EKeys::RightBracket)
	{
		NoesisKey = Noesis::Key_OemCloseBrackets;
	}
	else if (Key == EKeys::Gamepad_DPad_Up)
	{
		NoesisKey = Noesis::Key_GamepadUp;
	}
	else if (Key == EKeys::Gamepad_DPad_Down)
	{
		NoesisKey = Noesis::Key_GamepadDown;
	}
	else if (Key == EKeys::Gamepad_DPad_Left)
	{
		NoesisKey = Noesis::Key_GamepadLeft;
	}
	else if (Key == EKeys::Gamepad_DPad_Right)
	{
		NoesisKey = Noesis::Key_GamepadRight;
	}
	else if (Key == EKeys::Gamepad_FaceButton_Bottom)
	{
		NoesisKey = Noesis::Key_GamepadAccept;
	}
	else if (Key == EKeys::Gamepad_FaceButton_Right)
	{
		NoesisKey = Noesis::Key_GamepadCancel;
	}
	else if (Key == EKeys::Gamepad_LeftShoulder)
	{
		NoesisKey = Noesis::Key_GamepadPageLeft;
	}
	else if (Key == EKeys::Gamepad_RightShoulder)
	{
		NoesisKey = Noesis::Key_GamepadPageRight;
	}
	else if (Key == EKeys::Gamepad_LeftTrigger)
	{
		NoesisKey = Noesis::Key_GamepadPageUp;
	}
	else if (Key == EKeys::Gamepad_RightTrigger)
	{
		NoesisKey = Noesis::Key_GamepadPageDown;
	}
	else if (Key == EKeys::Gamepad_Special_Left)
	{
		NoesisKey = Noesis::Key_GamepadView;
	}
	else if (Key == EKeys::Gamepad_Special_Right)
	{
		NoesisKey = Noesis::Key_GamepadMenu;
	}

	return NoesisKey;
}

FReply UNoesisInstance::NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnKeyDown);
	if (XamlView)
	{
		FKey Key = KeyEvent.GetKey();

		XamlView->KeyDown(KeyToNoesisKey(Key));
	}

	return Super::NativeOnKeyDown(MyGeometry, KeyEvent);
}

FReply UNoesisInstance::NativeOnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnKeyUp);
	if (XamlView)
	{
		FKey Key = KeyEvent.GetKey();

		XamlView->KeyUp(KeyToNoesisKey(Key));
	}

	return Super::NativeOnKeyUp(MyGeometry, KeyEvent);
}

FReply UNoesisInstance::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnMouseButtonDown);
	if (XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		FKey Button = MouseEvent.GetEffectingButton();

		Noesis::MouseButton MouseButton;
		if (Button == EKeys::LeftMouseButton)
		{
			MouseButton = Noesis::MouseButton_Left;
		}
		else if (Button == EKeys::RightMouseButton)
		{
			MouseButton = Noesis::MouseButton_Right;
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			MouseButton = Noesis::MouseButton_Middle;
		}
		else if (Button == EKeys::ThumbMouseButton)
		{
			MouseButton = Noesis::MouseButton_XButton1;
		}
		else
		{
			MouseButton = Noesis::MouseButton_XButton2;
		}
		XamlView->MouseButtonDown(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);

		if (HitTest(Position))
		{
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnMouseButtonUp);
	if (XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		FKey Button = MouseEvent.GetEffectingButton();

		Noesis::MouseButton MouseButton;
		if (Button == EKeys::LeftMouseButton)
		{
			MouseButton = Noesis::MouseButton_Left;
		}
		else if (Button == EKeys::RightMouseButton)
		{
			MouseButton = Noesis::MouseButton_Right;
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			MouseButton = Noesis::MouseButton_Middle;
		}
		else if (Button == EKeys::ThumbMouseButton)
		{
			MouseButton = Noesis::MouseButton_XButton1;
		}
		else
		{
			MouseButton = Noesis::MouseButton_XButton2;
		}
		XamlView->MouseButtonUp(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);

		if (HitTest(Position))
		{
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnMouseMove);
	if (XamlView && !MouseEvent.GetCursorDelta().IsZero()) // Ignore synthetic events that are messing with the tooltip code.
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;

		XamlView->MouseMove(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y));

		if (HitTest(Position))
		{
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnMouseWheel);
	if (XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		float WheelDelta = MouseEvent.GetWheelDelta();

		XamlView->MouseWheel(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), FPlatformMath::RoundToInt(WheelDelta * 120.f));

		if (HitTest(Position))
		{
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnTouchStarted(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnTouchStarted);
	if (XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(TouchEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		uint32 PointerIndex = TouchEvent.GetPointerIndex();

		XamlView->TouchDown(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), PointerIndex);

		if (HitTest(Position))
		{
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnTouchMoved(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnTouchMoved);
	if (XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(TouchEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		uint32 PointerIndex = TouchEvent.GetPointerIndex();

		XamlView->TouchMove(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), PointerIndex);

		if (HitTest(Position))
		{
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnTouchEnded(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnTouchEnded);
	if (XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(TouchEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		uint32 PointerIndex = TouchEvent.GetPointerIndex();

		XamlView->TouchUp(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), PointerIndex);

		if (HitTest(Position))
		{
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

FCursorReply UNoesisInstance::NativeOnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent)
{
	return FCursorReply::Cursor(EMouseCursor::Default);
}

FReply UNoesisInstance::NativeOnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnMouseButtonDoubleClick);
	if (XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		FKey Button = MouseEvent.GetEffectingButton();

		Noesis::MouseButton MouseButton;
		if (Button == EKeys::LeftMouseButton)
		{
			MouseButton = Noesis::MouseButton_Left;
		}
		else if (Button == EKeys::RightMouseButton)
		{
			MouseButton = Noesis::MouseButton_Right;
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			MouseButton = Noesis::MouseButton_Middle;
		}
		else if (Button == EKeys::ThumbMouseButton)
		{
			MouseButton = Noesis::MouseButton_XButton1;
		}
		else
		{
			MouseButton = Noesis::MouseButton_XButton2;
		}
		XamlView->MouseDoubleClick(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);

		if (HitTest(Position))
		{
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

bool UNoesisInstance::NativeSupportsKeyboardFocus() const
{
	return true;
}

void UNoesisInstance::InitializeNativeClassData()
{
	Super::InitializeNativeClassData();

	InitInstance();
}
