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
DECLARE_CYCLE_STAT(TEXT("NoesisInstance::NativeOnAnalogValueChanged"), STAT_NoesisInstance_OnAnalogValueChanged, STATGROUP_Noesis);
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
	FNoesisSlateElement(Noesis::Ptr<Noesis::IRenderer> InRenderer);

	// ICustomSlateElement interface
	virtual void DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer) override;
	// End of ICustomSlateElement interface

	Noesis::Ptr<Noesis::IRenderer> Renderer;
	FTexture2DRHIRef DepthStencilTarget;

	float Left;
	float Top;
	float Right;
	float Bottom;
	bool FlipYAxis;
};

FNoesisSlateElement::FNoesisSlateElement(Noesis::Ptr<Noesis::IRenderer> InRenderer)
	: Renderer(InRenderer)
{
}

void FNoesisSlateElement::DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer)
{
	if (Renderer)
	{
		FTexture2DRHIRef ColorTarget = *(FTexture2DRHIRef*)InWindowBackBuffer;

		if (!DepthStencilTarget.IsValid() || DepthStencilTarget->GetSizeX() != ColorTarget->GetSizeX() || DepthStencilTarget->GetSizeY() != ColorTarget->GetSizeY() || DepthStencilTarget->GetNumSamples() != ColorTarget->GetNumSamples())
		{
			DepthStencilTarget.SafeRelease();
			uint32 SizeX = ColorTarget->GetSizeX();
			uint32 SizeY = ColorTarget->GetSizeY();
			uint8 Format = (uint8)PF_DepthStencil;
			uint32 NumMips = 1;
			uint32 NumSamples = ColorTarget->GetNumSamples();
			uint32 TargetableTextureFlags = (uint32)TexCreate_DepthStencilTargetable;
			FRHIResourceCreateInfo CreateInfo;
			CreateInfo.ClearValueBinding = FClearValueBinding(0.f, 0);
			DepthStencilTarget = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, TargetableTextureFlags, CreateInfo);
		}
		// Clear the stencil buffer
		FRHIRenderPassInfo RPInfo(ColorTarget, ERenderTargetActions::Load_Store, DepthStencilTarget,
			MakeDepthStencilTargetActions(ERenderTargetActions::DontLoad_DontStore, ERenderTargetActions::Clear_DontStore), FExclusiveDepthStencil::DepthNop_StencilWrite);

		check(RHICmdList.IsOutsideRenderPass());
		RHICmdList.BeginRenderPass(RPInfo, TEXT("NoesisOnScreen"));
		RHICmdList.SetViewport((int32)Left, (int32)Top, 0.0f, (int32)Right, (int32)Bottom, 1.0f);
		SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_Draw);
		SCOPED_DRAW_EVENT(RHICmdList, NoesisDraw);
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(&RHICmdList);
		Renderer->Render(FlipYAxis);
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(nullptr);

		RHICmdList.EndRenderPass();
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
		TextBox->SetText(TCHARToNsString(*NewText).Str());
		UpdateCompositionRange(InBeginIndex, InString.Len());
	}

	virtual int32 GetCharacterIndexFromPoint(const FVector2D& InPoint) override
	{
		return INDEX_NONE;
	}

	virtual bool GetTextBounds(const uint32 InBeginIndex, const uint32 InLength, FVector2D& OutPosition, FVector2D& OutSize) override
	{
		Noesis::Rect TextRangeBounds = TextBox->GetRangeBounds(InBeginIndex, InBeginIndex + InLength);
		Noesis::Visual* ContentHost = TextBox->GetTextView();

		if (Noesis::ScrollViewer* ScrollViewer = Noesis::DynamicCast<Noesis::ScrollViewer*>(ContentHost))
		{
			ContentHost = ScrollViewer;
		}
		else if (Noesis::Decorator* Decorator = Noesis::DynamicCast<Noesis::Decorator*>(ContentHost))
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

	Xaml.Reset(Noesis::DynamicCast<Noesis::FrameworkElement*>(BaseXaml->LoadXaml().GetPtr()));

	if (Xaml)
	{
		Xaml->SetDataContext(DataContext.GetPtr());

		XamlLoaded();

		XamlView = Noesis::GUI::CreateView(Xaml.GetPtr());

		if (XamlView)
		{
			Noesis::Ptr<Noesis::IRenderer> Renderer(XamlView->GetRenderer());

			ENQUEUE_RENDER_COMMAND(FNoesisInstance_InitRenderer)
			(
				[Renderer](FRHICommandListImmediate& RHICmdList)
				{
					Renderer->Init(FNoesisRenderDevice::Get());
				}
			);

			NoesisSlateElement = MakeShared<FNoesisSlateElement, ESPMode::ThreadSafe>(Renderer);

			CurrentTime = 0.0f;
			Update(0.0f, 0.0f, 256.0f, 256.0f);
		}

		Xaml->PreviewGotKeyboardFocus() += Noesis::MakeDelegate(this, &UNoesisInstance::OnPreviewGotKeyboardFocus);
		Xaml->PreviewLostKeyboardFocus() += Noesis::MakeDelegate(this, &UNoesisInstance::OnPreviewLostKeyboardFocus);
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
	Noesis::BaseComponent* Component = Xaml->FindName(TCHARToNsString(*Name).Str());
	return NoesisCreateUObjectForComponent(Component);
}

UObject* UNoesisInstance::FindResource(FString Name)
{
	Noesis::BaseComponent* Resource = Xaml->FindResource(TCHARToNsString(*Name).Str());
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
		Noesis::TessellationMaxPixelError mpe = Noesis::TessellationMaxPixelError::MediumQuality();
		switch (TessellationQuality)
		{
		case ENoesisTessellationQuality::Low:
			mpe = Noesis::TessellationMaxPixelError::LowQuality();
			break;
		case ENoesisTessellationQuality::Medium:
			mpe = Noesis::TessellationMaxPixelError::MediumQuality();
			break;
		case ENoesisTessellationQuality::High:
			mpe = Noesis::TessellationMaxPixelError::HighQuality();
			break;
		}
		XamlView->SetTessellationMaxPixelError(mpe);
		XamlView->SetFlags((uint32)RenderFlags | (EnablePPAA ? Noesis::RenderFlags_PPAA : 0));
		XamlView->Update(CurrentTime);
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
	const Noesis::TypeClass* TextBoxClass = Noesis::TextBox::StaticGetClassType(nullptr);
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
	const Noesis::TypeClass* TextBoxClass = Noesis::TextBox::StaticGetClassType(nullptr);
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

	Noesis::HitTestFilterBehavior Filter(Noesis::Visual*)
	{
		return Noesis::HitTestFilterBehavior_Continue;
	}

	Noesis::HitTestResultBehavior Result(const Noesis::HitTestResult& Result)
	{
		Noesis::UIElement* Element = Noesis::DynamicCast<Noesis::UIElement*>(Result.visualHit);
		if (Element && Element->GetIsEnabled())
		{
			Hit = Element;
			return Noesis::HitTestResultBehavior_Stop;
		}

		return Noesis::HitTestResultBehavior_Continue;
	}

	Noesis::UIElement* Hit;
};

bool UNoesisInstance::HitTest(FVector2D Position)
{
	NoesisHitTestVisibleTester HitTester;
	Noesis::VisualTreeHelper::HitTest(Noesis::VisualTreeHelper::GetRoot(Xaml.GetPtr()), Noesis::Point(Position.X, Position.Y), MakeDelegate(&HitTester, &NoesisHitTestVisibleTester::Filter), MakeDelegate(&HitTester, &NoesisHitTestVisibleTester::Result));

	return HitTester.Hit != nullptr;
}

void UNoesisInstance::TermInstance()
{
	if (XamlView)
	{
		Noesis::Ptr<Noesis::IRenderer> Renderer(XamlView->GetRenderer());
		XamlView.Reset();
		Xaml.Reset();

		// Pass the slate element to the render thread so that it's deleted after it's shown for the last time
		ENQUEUE_RENDER_COMMAND(SafeDeleteNoesisSlateElement)
		(
			[Renderer, NoesisSlateElement = NoesisSlateElement](FRHICommandListImmediate& RHICmdList) mutable
			{
				Renderer->Shutdown();
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
void UNoesisInstance::SetDesignerFlags(EWidgetDesignFlags NewFlags)
{
	// Enable native events in editor
	if (UWorld* LocalWorld = GetWorld())
	{
		UGameInstance* GameInstance = LocalWorld->GetGameInstance();
		if (GameInstance)
		{
			Super::SetDesignerFlags((EWidgetDesignFlags)(NewFlags & ~EWidgetDesignFlags::Designing));
		}
	}

	Super::SetDesignerFlags(NewFlags);
}

void UNoesisInstance::DrawThumbnail(FIntRect ViewportRect, const FTexture2DRHIRef& BackBuffer)
{
	Update(ViewportRect.Min.X, ViewportRect.Min.Y, ViewportRect.Max.X - ViewportRect.Min.X, ViewportRect.Max.Y - ViewportRect.Min.Y);

	Noesis::Ptr<Noesis::IRenderer> Renderer(XamlView->GetRenderer());

	if (BackBuffer != nullptr)
	{
		ENQUEUE_RENDER_COMMAND(FNoesisXamlThumbnailRendererDrawCommand)
		(
			[Renderer, FlipYAxis = FlipYAxis, BackBuffer](FRHICommandListImmediate& RHICmdList)
			{
				FNoesisRenderDevice::ThreadLocal_SetRHICmdList(&RHICmdList);
				Renderer->UpdateRenderTree();
				Renderer->RenderOffscreen();

				uint32 SizeX = BackBuffer->GetSizeX();
				uint32 SizeY = BackBuffer->GetSizeY();
				uint8 Format = (uint8)PF_DepthStencil;
				uint32 NumMips = BackBuffer->GetNumMips();
				uint32 NumSamples = BackBuffer->GetNumSamples();
				uint32 TargetableTextureFlags = (uint32)TexCreate_DepthStencilTargetable;
				FRHIResourceCreateInfo CreateInfo;
				CreateInfo.ClearValueBinding = FClearValueBinding(0.f, 0);
				FTexture2DRHIRef ColorTarget = BackBuffer;
				FTexture2DRHIRef DepthStencilTarget = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, TargetableTextureFlags, CreateInfo);
				FRHIRenderPassInfo RPInfo(ColorTarget, ERenderTargetActions::Load_Store, DepthStencilTarget,
					MakeDepthStencilTargetActions(ERenderTargetActions::DontLoad_DontStore, ERenderTargetActions::Clear_DontStore), FExclusiveDepthStencil::DepthNop_StencilWrite);

				check(RHICmdList.IsOutsideRenderPass());
				RHICmdList.BeginRenderPass(RPInfo, TEXT("NoesisThumbnail"));

				Renderer->Render(FlipYAxis);
				FNoesisRenderDevice::ThreadLocal_SetRHICmdList(nullptr);

				RHICmdList.EndRenderPass();
			}
		);
	}
}
#endif // WITH_EDITOR

void UNoesisInstance::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	FlipYAxis = IsInViewport() && RHINeedsToSwitchVerticalAxis(GShaderPlatformForFeatureLevel[GMaxRHIFeatureLevel]);

	FVector2D AbsolutePosition = MyGeometry.GetAbsolutePosition();
	FVector2D AbsoluteSize = MyGeometry.GetAbsoluteSize();
	CurrentTime += InDeltaTime;
	Update(AbsolutePosition.X, AbsolutePosition.Y, AbsoluteSize.X, AbsoluteSize.Y);
}

int32 UNoesisInstance::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	int32 MaxLayer = Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	if (XamlView)
	{
		Noesis::Ptr<Noesis::IRenderer> Renderer(XamlView->GetRenderer());

		ENQUEUE_RENDER_COMMAND(FNoesisInstance_DrawOffscreen)
		(
			[Renderer](FRHICommandListImmediate& RHICmdList)
			{
				SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_DrawOffscreen);
				SCOPED_DRAW_EVENT(RHICmdList, NoesisDrawOffscreen);
				FNoesisRenderDevice::ThreadLocal_SetRHICmdList(&RHICmdList);
				Renderer->UpdateRenderTree();
				Renderer->RenderOffscreen();
				FNoesisRenderDevice::ThreadLocal_SetRHICmdList(nullptr);
			}
		);

		const FSlateRect& MyClippingRect = MyCullingRect;

		NoesisSlateElement->Left = MyClippingRect.Left;
		NoesisSlateElement->Top = MyClippingRect.Top;
		NoesisSlateElement->Right = MyClippingRect.Right;
		NoesisSlateElement->Bottom = MyClippingRect.Bottom;
		NoesisSlateElement->FlipYAxis = FlipYAxis;
		FSlateDrawElement::MakeCustom(OutDrawElements, LayerId, NoesisSlateElement);

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

static TMap<FKey, Noesis::Key> InitKeyMap()
{
	TMap<FKey, Noesis::Key> KeyMap;
	KeyMap.Add(EKeys::BackSpace, Noesis::Key_Back);
	KeyMap.Add(EKeys::Tab, Noesis::Key_Tab);
	KeyMap.Add(EKeys::Enter, Noesis::Key_Enter);
	KeyMap.Add(EKeys::Pause, Noesis::Key_Pause);
	KeyMap.Add(EKeys::CapsLock, Noesis::Key_CapsLock);
	KeyMap.Add(EKeys::Escape, Noesis::Key_Escape);
	KeyMap.Add(EKeys::SpaceBar, Noesis::Key_Space);
	KeyMap.Add(EKeys::PageUp, Noesis::Key_PageUp);
	KeyMap.Add(EKeys::PageDown, Noesis::Key_PageDown);
	KeyMap.Add(EKeys::End, Noesis::Key_End);
	KeyMap.Add(EKeys::Home, Noesis::Key_Home);
	KeyMap.Add(EKeys::Left, Noesis::Key_Left);
	KeyMap.Add(EKeys::Up, Noesis::Key_Up);
	KeyMap.Add(EKeys::Right, Noesis::Key_Right);
	KeyMap.Add(EKeys::Down, Noesis::Key_Down);
	KeyMap.Add(EKeys::Insert, Noesis::Key_Insert);
	KeyMap.Add(EKeys::Delete, Noesis::Key_Delete);
	KeyMap.Add(EKeys::Zero, Noesis::Key_D0);
	KeyMap.Add(EKeys::One, Noesis::Key_D1);
	KeyMap.Add(EKeys::Two, Noesis::Key_D2);
	KeyMap.Add(EKeys::Three, Noesis::Key_D3);
	KeyMap.Add(EKeys::Four, Noesis::Key_D4);
	KeyMap.Add(EKeys::Five, Noesis::Key_D5);
	KeyMap.Add(EKeys::Six, Noesis::Key_D6);
	KeyMap.Add(EKeys::Seven, Noesis::Key_D7);
	KeyMap.Add(EKeys::Eight, Noesis::Key_D8);
	KeyMap.Add(EKeys::Nine, Noesis::Key_D9);
	KeyMap.Add(EKeys::A, Noesis::Key_A);
	KeyMap.Add(EKeys::B, Noesis::Key_B);
	KeyMap.Add(EKeys::C, Noesis::Key_C);
	KeyMap.Add(EKeys::D, Noesis::Key_D);
	KeyMap.Add(EKeys::E, Noesis::Key_E);
	KeyMap.Add(EKeys::F, Noesis::Key_F);
	KeyMap.Add(EKeys::G, Noesis::Key_G);
	KeyMap.Add(EKeys::H, Noesis::Key_H);
	KeyMap.Add(EKeys::I, Noesis::Key_I);
	KeyMap.Add(EKeys::J, Noesis::Key_J);
	KeyMap.Add(EKeys::K, Noesis::Key_K);
	KeyMap.Add(EKeys::L, Noesis::Key_L);
	KeyMap.Add(EKeys::M, Noesis::Key_M);
	KeyMap.Add(EKeys::N, Noesis::Key_N);
	KeyMap.Add(EKeys::O, Noesis::Key_O);
	KeyMap.Add(EKeys::P, Noesis::Key_P);
	KeyMap.Add(EKeys::Q, Noesis::Key_Q);
	KeyMap.Add(EKeys::R, Noesis::Key_R);
	KeyMap.Add(EKeys::S, Noesis::Key_S);
	KeyMap.Add(EKeys::T, Noesis::Key_T);
	KeyMap.Add(EKeys::U, Noesis::Key_U);
	KeyMap.Add(EKeys::V, Noesis::Key_V);
	KeyMap.Add(EKeys::W, Noesis::Key_W);
	KeyMap.Add(EKeys::X, Noesis::Key_X);
	KeyMap.Add(EKeys::Y, Noesis::Key_Y);
	KeyMap.Add(EKeys::Z, Noesis::Key_Z);
	KeyMap.Add(EKeys::NumPadZero, Noesis::Key_NumPad0);
	KeyMap.Add(EKeys::NumPadOne, Noesis::Key_NumPad1);
	KeyMap.Add(EKeys::NumPadTwo, Noesis::Key_NumPad2);
	KeyMap.Add(EKeys::NumPadThree, Noesis::Key_NumPad3);
	KeyMap.Add(EKeys::NumPadFour, Noesis::Key_NumPad4);
	KeyMap.Add(EKeys::NumPadFive, Noesis::Key_NumPad5);
	KeyMap.Add(EKeys::NumPadSix, Noesis::Key_NumPad6);
	KeyMap.Add(EKeys::NumPadSeven, Noesis::Key_NumPad7);
	KeyMap.Add(EKeys::NumPadEight, Noesis::Key_NumPad8);
	KeyMap.Add(EKeys::NumPadNine, Noesis::Key_NumPad9);
	KeyMap.Add(EKeys::Multiply, Noesis::Key_Multiply);
	KeyMap.Add(EKeys::Add, Noesis::Key_Add);
	KeyMap.Add(EKeys::Subtract, Noesis::Key_Subtract);
	KeyMap.Add(EKeys::Decimal, Noesis::Key_Decimal);
	KeyMap.Add(EKeys::Divide, Noesis::Key_Divide);
	KeyMap.Add(EKeys::F1, Noesis::Key_F1);
	KeyMap.Add(EKeys::F2, Noesis::Key_F2);
	KeyMap.Add(EKeys::F3, Noesis::Key_F3);
	KeyMap.Add(EKeys::F4, Noesis::Key_F4);
	KeyMap.Add(EKeys::F5, Noesis::Key_F5);
	KeyMap.Add(EKeys::F6, Noesis::Key_F6);
	KeyMap.Add(EKeys::F7, Noesis::Key_F7);
	KeyMap.Add(EKeys::F8, Noesis::Key_F8);
	KeyMap.Add(EKeys::F9, Noesis::Key_F9);
	KeyMap.Add(EKeys::F10, Noesis::Key_F10);
	KeyMap.Add(EKeys::F11, Noesis::Key_F11);
	KeyMap.Add(EKeys::F12, Noesis::Key_F12);
	KeyMap.Add(EKeys::NumLock, Noesis::Key_NumLock);
	KeyMap.Add(EKeys::ScrollLock, Noesis::Key_Scroll);
	KeyMap.Add(EKeys::LeftShift, Noesis::Key_LeftShift);
	KeyMap.Add(EKeys::RightShift, Noesis::Key_RightShift);
	KeyMap.Add(EKeys::LeftControl, Noesis::Key_LeftCtrl);
	KeyMap.Add(EKeys::RightControl, Noesis::Key_RightCtrl);
	KeyMap.Add(EKeys::LeftAlt, Noesis::Key_LeftAlt);
	KeyMap.Add(EKeys::RightAlt, Noesis::Key_RightAlt);
	KeyMap.Add(EKeys::LeftCommand, Noesis::Key_LWin);
	KeyMap.Add(EKeys::RightCommand, Noesis::Key_RWin);
	KeyMap.Add(EKeys::Semicolon, Noesis::Key_OemSemicolon);
	KeyMap.Add(EKeys::Comma, Noesis::Key_OemComma);
	KeyMap.Add(EKeys::Period, Noesis::Key_OemPeriod);
	KeyMap.Add(EKeys::Tilde, Noesis::Key_OemTilde);
	KeyMap.Add(EKeys::LeftBracket, Noesis::Key_OemOpenBrackets);
	KeyMap.Add(EKeys::Backslash, Noesis::Key_OemBackslash);
	KeyMap.Add(EKeys::RightBracket, Noesis::Key_OemCloseBrackets);
	KeyMap.Add(EKeys::Gamepad_DPad_Up, Noesis::Key_GamepadUp);
	KeyMap.Add(EKeys::Gamepad_LeftStick_Up, Noesis::Key_GamepadUp);
	KeyMap.Add(EKeys::Gamepad_DPad_Down, Noesis::Key_GamepadDown);
	KeyMap.Add(EKeys::Gamepad_LeftStick_Down, Noesis::Key_GamepadDown);
	KeyMap.Add(EKeys::Gamepad_DPad_Left, Noesis::Key_GamepadLeft);
	KeyMap.Add(EKeys::Gamepad_LeftStick_Left, Noesis::Key_GamepadLeft);
	KeyMap.Add(EKeys::Gamepad_DPad_Right, Noesis::Key_GamepadRight);
	KeyMap.Add(EKeys::Gamepad_LeftStick_Right, Noesis::Key_GamepadRight);
	KeyMap.Add(EKeys::Gamepad_FaceButton_Bottom, Noesis::Key_GamepadAccept);
	KeyMap.Add(EKeys::Gamepad_FaceButton_Right, Noesis::Key_GamepadCancel);
	KeyMap.Add(EKeys::Gamepad_LeftShoulder, Noesis::Key_GamepadPageLeft);
	KeyMap.Add(EKeys::Gamepad_RightShoulder, Noesis::Key_GamepadPageRight);
	KeyMap.Add(EKeys::Gamepad_LeftTrigger, Noesis::Key_GamepadPageUp);
	KeyMap.Add(EKeys::Gamepad_RightTrigger, Noesis::Key_GamepadPageDown);
	KeyMap.Add(EKeys::Gamepad_Special_Left, Noesis::Key_GamepadView);
	KeyMap.Add(EKeys::Gamepad_Special_Right, Noesis::Key_GamepadMenu);
	return KeyMap;
}

Noesis::Key* KeyToNoesisKey(FKey Key)
{
	static TMap<FKey, Noesis::Key> KeyMap = InitKeyMap();
	Noesis::Key* NoesisKey = nullptr;
	NoesisKey = KeyMap.Find(Key);
	return NoesisKey;
}

FReply UNoesisInstance::NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnKeyDown);
	if (XamlView)
	{
		FKey Key = KeyEvent.GetKey();
		Noesis::Key* NoesisKey = KeyToNoesisKey(Key);
		if (NoesisKey != nullptr)
		{
			XamlView->KeyDown(*NoesisKey);
		}
	}

	return Super::NativeOnKeyDown(MyGeometry, KeyEvent);
}

FReply UNoesisInstance::NativeOnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnKeyUp);
	if (XamlView)
	{
		FKey Key = KeyEvent.GetKey();
		Noesis::Key* NoesisKey = KeyToNoesisKey(Key);
		if (NoesisKey != nullptr)
		{
			XamlView->KeyUp(*NoesisKey);
		}
	}

	return Super::NativeOnKeyUp(MyGeometry, KeyEvent);
}

FReply UNoesisInstance::NativeOnAnalogValueChanged(const FGeometry& MyGeometry, const FAnalogInputEvent& InAnalogEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnAnalogValueChanged);
	if (XamlView)
	{
		if (FMath::Abs(InAnalogEvent.GetAnalogValue()) > 0.25f)
		{
			if (InAnalogEvent.GetKey() == EKeys::Gamepad_RightX)
			{
				XamlView->HScroll(InAnalogEvent.GetAnalogValue());
			}
			else if (InAnalogEvent.GetKey() == EKeys::Gamepad_RightY)
			{
				XamlView->Scroll(InAnalogEvent.GetAnalogValue());
			}
		}
	}

	return Super::NativeOnAnalogValueChanged(MyGeometry, InAnalogEvent);
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
