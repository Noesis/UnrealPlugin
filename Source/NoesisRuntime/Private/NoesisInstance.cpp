////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisInstance.h"

// Core includes
#include "MathUtil.h"
#include "Stats/Stats.h"
#include "Stats/Stats2.h"

// CoreUObject includes
#include "UObject/UObjectIterator.h"

// Engine includes
#include "EngineModule.h"
#include "SceneUtils.h"
#include "SceneView.h"
#include "Engine/GameViewportClient.h"
#include "GameFramework/WorldSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Slate/SceneViewport.h"
#if UE_VERSION_OLDER_THAN(5, 2, 0)
#include "MaterialShared.h"
#else
#include "Materials/MaterialRenderProxy.h"
#endif

// RHI includes
#if UE_VERSION_OLDER_THAN(5, 2, 0)
#include "RHIDefinitions.h"
#else
#include "DataDrivenShaderPlatformInfo.h"
#endif

// RenderCore includes
#include "RendererInterface.h"
#include "RenderingThread.h"

// Renderer includes
#include "SceneRendering.h"
#include "TranslucentRendering.h"
#include "PostProcess/PostProcessing.h"

// UtilityShaders includes
#include "ClearQuad.h"

// ApplicationCore includes
#include "HAL/PlatformApplicationMisc.h"
#include "GenericPlatform/ITextInputMethodSystem.h"

// Slate includes
#include "Widgets/SViewport.h"
#include "Widgets/SWindow.h"
#include "Framework/Application/IInputProcessor.h"
#include "Framework/Application/SlateApplication.h"

// SlateCore includes
#include "Input/HittestGrid.h"
#include "Types/SlateConstants.h"

// UMG includes
#include "Components/WidgetComponent.h"

// NoesisRuntime includes
#include "NoesisCustomVersion.h"
#include "NoesisRuntimeModule.h"
#include "NoesisBlueprintGeneratedClass.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisTypeClass.h"
#include "NoesisXaml.h"
#include "NoesisSupport.h"
#include "Extensions/BackgroundImage.h"

#if WITH_COMMON_UI
// CommonInput includes
#include "CommonInputSubsystem.h"
#endif

#if WITH_ENHANCED_INPUT
// EnhancedInput includes
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputTriggers.h"
#endif

DECLARE_CYCLE_STAT(TEXT("Update"), STAT_NoesisInstance_Update, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("UpdateRenderTree"), STAT_NoesisInstance_UpdateRenderTree, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("RenderOffscreen"), STAT_NoesisInstance_DrawOffscreen, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("Render"), STAT_NoesisInstance_Draw, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("Char"), STAT_NoesisInstance_OnKeyChar, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("KeyDown"), STAT_NoesisInstance_OnKeyDown, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("KeyUp"), STAT_NoesisInstance_OnKeyUp, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("Scroll"), STAT_NoesisInstance_OnAnalogValueChanged, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("MouseButtonDown"), STAT_NoesisInstance_OnMouseButtonDown, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("MouseButtonUp"), STAT_NoesisInstance_OnMouseButtonUp, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("MouseMove"), STAT_NoesisInstance_OnMouseMove, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("MouseWheel"), STAT_NoesisInstance_OnMouseWheel, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("TouchDown"), STAT_NoesisInstance_OnTouchStarted, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("TouchMove"), STAT_NoesisInstance_OnTouchMoved, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("TouchUp"), STAT_NoesisInstance_OnTouchEnded, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("MouseDoubleClick"), STAT_NoesisInstance_OnMouseButtonDoubleClick, STATGROUP_Noesis);

DECLARE_GPU_STAT_NAMED(NoesisOnscreen, TEXT("NoesisOnscreen"));
DECLARE_GPU_STAT_NAMED(NoesisOffscreen, TEXT("NoesisOffscreen"));

// Only to be modified from the render thread. Enqueue any operation needed to the render thread.
TArray<FNoesisSlateElement*> GNoesis3DSlateElements;

static Noesis::Matrix4 UnrealToNoesisViewProj(const FMatrix& UnrealViewProj, float Width, float Height)
{
	/// ViewProj = BaseChange * UnrealViewProj * Scale * Trans * Invert, where
	/// BaseChange = Matrix4(
	///		 0.f, -1.f,  0.f, 0.f,
	///		 0.f,  0.f, -1.f, 0.f,
	///		-1.f,  0.f,  0.f, 0.f,
	///		 0.f,  0.f,  0.f, 1.f
	///	);
	/// Scale = Matrix4::Scale(HalfWidth, HalfHeight, 1.0f);
	/// Trans = Matrix4::Trans(HalfWidth, HalfHeight, 0.0f);
	/// Invert = Matrix4(
	///		1.f,     0.f, 0.f, 0.f,
	/// 	0.f,    -1.f, 0.f, 0.f,
	/// 	0.f,     0.f, 1.f, 0.f,
	/// 	0.f,  Height, 0.f, 1.f
	/// );
	/// 
	/// BaseChange transforms from Unreal's coordinate system to what we need.
	/// Doing it this way we can skip a lot of multiplies by 0.0f and 1.0f.
	auto HalfWidth = 0.5f * Width;
	auto HalfHeight = 0.5f * Height;
	Noesis::Matrix4 ViewProj(
		-(UnrealViewProj.M[1][0] + UnrealViewProj.M[1][3]) * HalfWidth,  (UnrealViewProj.M[1][1] - UnrealViewProj.M[1][3]) * HalfHeight, -UnrealViewProj.M[1][2], -UnrealViewProj.M[1][3],
		-(UnrealViewProj.M[2][0] + UnrealViewProj.M[2][3]) * HalfWidth,  (UnrealViewProj.M[2][1] - UnrealViewProj.M[2][3]) * HalfHeight, -UnrealViewProj.M[2][2], -UnrealViewProj.M[2][3],
		-(UnrealViewProj.M[0][0] + UnrealViewProj.M[0][3]) * HalfWidth,  (UnrealViewProj.M[0][1] - UnrealViewProj.M[0][3]) * HalfHeight, -UnrealViewProj.M[0][2], -UnrealViewProj.M[0][3],
		 (UnrealViewProj.M[3][0] + UnrealViewProj.M[3][3]) * HalfWidth, -(UnrealViewProj.M[3][1] - UnrealViewProj.M[3][3]) * HalfHeight,  UnrealViewProj.M[3][2],  UnrealViewProj.M[3][3]
	);
	return ViewProj;
}

FIntRect GViewRect;
FMatrix GViewProjectionMatrix;
uint32 GSlateElementCount = 0;
FTexture2DRHIRef GDepthStencilTarget;

class FNoesisSlateElement : public ICustomSlateElement
{
public:
	FNoesisSlateElement(Noesis::Ptr<Noesis::IRenderer> InRenderer);
	~FNoesisSlateElement()
	{
		check(IsInRenderingThread());
		Renderer->Shutdown();
	}

	// ICustomSlateElement interface
	virtual void DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer) override;
	// End of ICustomSlateElement interface

	void UpdateRenderTree() const;
	void RenderOffscreen(FRHICommandList& RHICmdList) const;
	void RenderOnscreen(FRHICommandList& RHICmdList, bool WithViewProj) const;

	void RenderView(FRHICommandList& RHICmdList, const FViewInfo* View);

	Noesis::Ptr<Noesis::IRenderer> Renderer;

	float Left;
	float Top;
	float Right;
	float Bottom;
	FIntRect ViewRect;
	FSceneInterface* Scene = nullptr;
	FGameTime WorldTime;
	bool IsMobileMultiView = false;
	bool IsInstancedStereo = false;
	Noesis::Matrix4 ViewProj;
	Noesis::Matrix4 LeftEyeViewProj;
	Noesis::Matrix4 RightEyeViewProj;
	FMatrix ViewProjectionMatrix;
	FNoesisRenderDevice* RenderDevice = nullptr;
	float EngineGamma = 2.2f;
	float SlateContrast = 1.0f;
};

FNoesisSlateElement::FNoesisSlateElement(Noesis::Ptr<Noesis::IRenderer> InRenderer)
	: Renderer(InRenderer)
{
}

void FNoesisSlateElement::DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer)
{
	ViewRect = GViewRect;
	ViewProjectionMatrix = GViewProjectionMatrix;

	FTexture2DRHIRef ColorTarget = *(FTexture2DRHIRef*)InWindowBackBuffer;

	if (!GDepthStencilTarget.IsValid() || GDepthStencilTarget->GetSizeX() != ColorTarget->GetSizeX() || GDepthStencilTarget->GetSizeY() != ColorTarget->GetSizeY() || GDepthStencilTarget->GetNumSamples() != ColorTarget->GetNumSamples())
	{
		GDepthStencilTarget.SafeRelease();
		uint32 SizeX = ColorTarget->GetSizeX();
		uint32 SizeY = ColorTarget->GetSizeY();
		EPixelFormat Format = PF_DepthStencil;
		uint32 NumMips = 1;
		uint32 NumSamples = ColorTarget->GetNumSamples();
		ETextureCreateFlags TargetableTextureFlags = TexCreate_DepthStencilTargetable | TexCreate_Memoryless;
		ERHIAccess Access = ERHIAccess::DSVWrite;
		FClearValueBinding ClearValue(0.f, 0);
		const TCHAR* Name = TEXT("Noesis.RenderTarget.Onscreen_DS");
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		FRHIResourceCreateInfo CreateInfo(Name);
		CreateInfo.ClearValueBinding = ClearValue;
		GDepthStencilTarget = RHICreateTexture2D(SizeX, SizeY, (uint8)Format, NumMips, NumSamples, TargetableTextureFlags, Access, CreateInfo);
#else
		auto DepthStencilTargetDesc = FRHITextureCreateDesc::Create2D(Name)
			.SetExtent(SizeX, SizeY)
			.SetFormat(Format)
			.SetNumMips(NumMips)
			.SetNumSamples(NumSamples)
			.SetFlags(TargetableTextureFlags)
			.SetInitialState(Access)
			.SetClearValue(ClearValue);
		GDepthStencilTarget = RHICreateTexture(DepthStencilTargetDesc);
#endif
		NOESIS_BIND_DEBUG_TEXTURE_LABEL(GDepthStencilTarget, Name);
	}

	// Clear the stencil buffer
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_Draw);
	FRHIRenderPassInfo RPInfo(ColorTarget, ERenderTargetActions::Load_Store, GDepthStencilTarget,
		MakeDepthStencilTargetActions(ERenderTargetActions::DontLoad_DontStore, ERenderTargetActions::Clear_Store), FExclusiveDepthStencil::DepthNop_StencilWrite);

	check(RHICmdList.IsOutsideRenderPass());
	RHICmdList.BeginRenderPass(RPInfo, TEXT("NoesisOnScreen"));
	RHICmdList.SetViewport(Left, Top, 0.0f, Right, Bottom, 1.0f);
	EngineGamma = (!GIsEditor && (ColorTarget->GetFormat() == PF_FloatRGBA)/* && (Params.bIsHDR == false)*/) ? 1.0f : EngineGamma;
	RenderOnscreen(RHICmdList, false);
	RHICmdList.EndRenderPass();
}

void FNoesisSlateElement::UpdateRenderTree() const
{
	if ((Renderer == nullptr) || (RenderDevice == nullptr))
		return;

	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_UpdateRenderTree);
	Renderer->UpdateRenderTree();
}

void FNoesisSlateElement::RenderOffscreen(FRHICommandList& RHICmdList) const
{
	if ((Renderer == nullptr) || (RenderDevice == nullptr))
		return;

	// Make sure dynamic material cached uniform expressions are up to date before doing any rendering
	FMaterialRenderProxy::UpdateDeferredCachedUniformExpressions();

	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_DrawOffscreen);
	SCOPED_DRAW_EVENT(RHICmdList, Noesis_Offscreen);
	SCOPED_GPU_STAT(RHICmdList, NoesisOffscreen);
	RenderDevice->SetWorldTime(WorldTime);
	RenderDevice->SetScene(Scene);
	RenderDevice->SetRHICmdList(&RHICmdList);
	RenderDevice->SetGammaAndContrast(2.2f, 1.0f);
	Renderer->RenderOffscreen();
	RenderDevice->SetRHICmdList(nullptr);
}

void FNoesisSlateElement::RenderOnscreen(FRHICommandList& RHICmdList, bool WithViewProj) const
{
	if ((Renderer == nullptr) || (RenderDevice == nullptr))
		return;

	if (ViewRect.Width() > 0 && ViewRect.Height() > 0)
	{
		RenderDevice->CreateView(Left, Top, Right, Bottom, ViewRect, ViewProjectionMatrix);
	}

	SCOPED_DRAW_EVENT(RHICmdList, Noesis);
	SCOPED_GPU_STAT(RHICmdList, NoesisOnscreen);
	RenderDevice->SetWorldTime(WorldTime);
	RenderDevice->SetScene(Scene);
	RenderDevice->SetRHICmdList(&RHICmdList);
	RenderDevice->SetGammaAndContrast(EngineGamma, SlateContrast);
	Renderer->SetRenderRegion(0.f, 0.f, Right - Left, Bottom - Top);
	if (WithViewProj)
	{
		if (IsMobileMultiView || IsInstancedStereo)
		{
			Renderer->Render(ViewProj, LeftEyeViewProj, RightEyeViewProj);
		}
		else
		{
			Renderer->Render(ViewProj);
		}
	}
	else
	{
		Renderer->Render();
	}
	RenderDevice->DestroyView();
	RenderDevice->SetRHICmdList(nullptr);
}

void FNoesisSlateElement::RenderView(FRHICommandList& RHICmdList, const FViewInfo* View)
{
	if ((View->bIsMobileMultiViewEnabled || View->bIsInstancedStereoEnabled) && (View == View->GetInstancedSceneView()))
		return;

	const auto ViewFamily = View->Family;

	ViewRect = View->ViewRect;
	Left = ViewRect.Min.X;
	Top = ViewRect.Min.Y;
	Right = ViewRect.Max.X;
	Bottom = ViewRect.Max.Y;
	Scene = ViewFamily->Scene;
	WorldTime = ViewFamily->Time;
	IsMobileMultiView = View->bIsMobileMultiViewEnabled && View->StereoPass == EStereoscopicPass::eSSP_PRIMARY;
	IsInstancedStereo = View->bIsInstancedStereoEnabled && View->StereoPass == EStereoscopicPass::eSSP_PRIMARY;
	if (IsMobileMultiView || IsInstancedStereo)
	{
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		if (!View->bIsMultiViewEnabled)
		{
			ViewProj = UnrealToNoesisViewProj(ViewProjectionMatrix, Right - Left, Bottom - Top);

			auto LeftEyeViewProjectionMatrix = View->ViewMatrices.GetViewProjectionMatrix();
			LeftEyeViewProj = UnrealToNoesisViewProj(LeftEyeViewProjectionMatrix, Right - Left, Bottom - Top);

			auto InstancedView = (FViewInfo*)View->GetInstancedSceneView();
			const auto& InstancedViewRect = InstancedView->ViewRect;
			float InstancedLeft = InstancedViewRect.Min.X;
			float InstancedTop = InstancedViewRect.Min.Y;
			float InstancedRight = InstancedViewRect.Max.X;
			float InstancedBottom = InstancedViewRect.Max.Y;

			auto RightEyeViewProjectionMatrix = InstancedView->ViewMatrices.GetViewProjectionMatrix();
			RightEyeViewProj = UnrealToNoesisViewProj(RightEyeViewProjectionMatrix, InstancedRight - InstancedLeft, InstancedBottom - InstancedTop);

			RHICmdList.SetViewport(Left, Top, 0.0f, View->InstancedStereoWidth, Bottom, 1.0f);
		}
		else
#endif
		{
			ViewProj = UnrealToNoesisViewProj(ViewProjectionMatrix, Right - Left, Bottom - Top);

			auto LeftEyeViewProjectionMatrix = View->ViewMatrices.GetViewProjectionMatrix();
			LeftEyeViewProj = UnrealToNoesisViewProj(LeftEyeViewProjectionMatrix, Right - Left, Bottom - Top);

			auto InstancedView = (FViewInfo*)View->GetInstancedSceneView();
			const auto& InstancedViewRect = InstancedView->ViewRect;
			float InstancedLeft = InstancedViewRect.Min.X;
			float InstancedTop = InstancedViewRect.Min.Y;
			float InstancedRight = InstancedViewRect.Max.X;
			float InstancedBottom = InstancedViewRect.Max.Y;

			auto RightEyeViewProjectionMatrix = InstancedView->ViewMatrices.GetViewProjectionMatrix();
			RightEyeViewProj = UnrealToNoesisViewProj(RightEyeViewProjectionMatrix, InstancedRight - InstancedLeft, InstancedBottom - InstancedTop);

			RHICmdList.SetStereoViewport(Left, InstancedLeft, Top, InstancedTop, 0.0f, Right, InstancedRight, Bottom, InstancedBottom, 1.0f);
		}
	}
	else
	{
		auto MonoViewProjectionMatrix = View->ViewMatrices.GetViewProjectionMatrix();
		ViewProj = UnrealToNoesisViewProj(MonoViewProjectionMatrix, Right - Left, Bottom - Top);

		RHICmdList.SetViewport(Left, Top, 0.0f, Right, Bottom, 1.0f);
	}

	// We shouldn't use the versions of Render that use ViewProj if it's invalid, but we still need to call Render
	bool IsViewProjectionMatrixValid = FMath::Abs(ViewProjectionMatrix.Determinant()) >= UE_KINDA_SMALL_NUMBER;
	RenderOnscreen(RHICmdList, IsViewProjectionMatrixValid);
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

TMap<Noesis::IView*, UNoesisInstance*> ViewInstanceMap;

UNoesisInstance* UNoesisInstance::FromView(Noesis::IView* View)
{
	UNoesisInstance** InstancePtr = ViewInstanceMap.Find(View);
	if (InstancePtr != nullptr)
	{
		return *InstancePtr;
	}
	return nullptr;
}

UNoesisInstance::UNoesisInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), Scene(nullptr), WidgetComponent(nullptr)
{
	EnableKeyboard = true;
	EnableMouse = true;
	EmulateTouch = false;
	EnableTouch = true;
	EnableActions = false;
	PixelDepthBias = -1.0f;
}

void UNoesisInstance::InitInstance()
{
	if (!BaseXaml)
	{
		NS_LOG("Noesis View %s doesn't have a valid XAML. Please recompile.", TCHAR_TO_UTF8(*GetPathName()));
		return;
	}

	Xaml = Noesis::DynamicPtrCast<Noesis::FrameworkElement>(BaseXaml->LoadXaml());

	if (Xaml)
	{
		Xaml->SetDataContext(DataContext);

		XamlLoaded();

		XamlView = Noesis::GUI::CreateView(Xaml);

		if (XamlView)
		{
			ViewInstanceMap.Add(XamlView.GetPtr(), this);

			Noesis::Ptr<Noesis::IRenderer> Renderer(XamlView->GetRenderer());

			NoesisSlateElement = MakeShared<FNoesisSlateElement, ESPMode::ThreadSafe>(Renderer);

			ENQUEUE_RENDER_COMMAND(FNoesisInstance_InitRenderer)
			(
				[Renderer, Is3DWidget = Is3DWidget, NoesisSlateElement = NoesisSlateElement](FRHICommandListImmediate& RHICmdList)
				{
					FNoesisRenderDevice* RenderDevice = Is3DWidget ? FNoesisRenderDevice::GetLinear() : FNoesisRenderDevice::Get();
					Renderer->Init(RenderDevice);
					NoesisSlateElement->RenderDevice = RenderDevice;
					if (!Is3DWidget)
					{
						++GSlateElementCount;
					}
				}
			);

			CurrentTime = 0.0f;

			Xaml->Measure(Noesis::Size(FLT_INF, FLT_INF));
			auto DesiredSize = Xaml->GetDesiredSize();
			SetMinimumDesiredSize(FVector2D(DesiredSize.width, DesiredSize.height));

			FCoreDelegates::OnSafeFrameChangedEvent.AddUObject(this, &UNoesisInstance::ViewportResized);
		}

		Xaml->PreviewGotKeyboardFocus() += Noesis::MakeDelegate(this, &UNoesisInstance::OnPreviewGotKeyboardFocus);
		Xaml->PreviewLostKeyboardFocus() += Noesis::MakeDelegate(this, &UNoesisInstance::OnPreviewLostKeyboardFocus);

#if WITH_ENHANCED_INPUT
		auto ThisInputComponent = GetInputComponent();

		if (auto EnhancedInputComponent = Cast<UEnhancedInputComponent>(ThisInputComponent))
		{
			TPair<const TCHAR*, Noesis::Key> InputEvents[] = {
				{ TEXT("/NoesisGUI/EnhancedInput/Left"), Noesis::Key_GamepadLeft },
				{ TEXT("/NoesisGUI/EnhancedInput/Up"), Noesis::Key_GamepadUp },
				{ TEXT("/NoesisGUI/EnhancedInput/Right"), Noesis::Key_GamepadRight },
				{ TEXT("/NoesisGUI/EnhancedInput/Down"), Noesis::Key_GamepadDown },
				{ TEXT("/NoesisGUI/EnhancedInput/Accept"), Noesis::Key_GamepadAccept },
				{ TEXT("/NoesisGUI/EnhancedInput/Cancel"), Noesis::Key_GamepadCancel },
				{ TEXT("/NoesisGUI/EnhancedInput/Menu"), Noesis::Key_GamepadMenu },
				{ TEXT("/NoesisGUI/EnhancedInput/View"), Noesis::Key_GamepadView },
				{ TEXT("/NoesisGUI/EnhancedInput/PageUp"), Noesis::Key_GamepadPageUp },
				{ TEXT("/NoesisGUI/EnhancedInput/PageDown"), Noesis::Key_GamepadPageDown },
				{ TEXT("/NoesisGUI/EnhancedInput/PageLeft"), Noesis::Key_GamepadPageLeft },
				{ TEXT("/NoesisGUI/EnhancedInput/PageRight"), Noesis::Key_GamepadPageRight },
				{ TEXT("/NoesisGUI/EnhancedInput/Context1"), Noesis::Key_GamepadContext1 },
				{ TEXT("/NoesisGUI/EnhancedInput/Context2"), Noesis::Key_GamepadContext2 },
				{ TEXT("/NoesisGUI/EnhancedInput/Context3"), Noesis::Key_GamepadContext3 },
				{ TEXT("/NoesisGUI/EnhancedInput/Context4"), Noesis::Key_GamepadContext4 }
			};

			for (const auto& Event : InputEvents)
			{
				UInputAction* Action = LoadObject<UInputAction>(nullptr, Event.Key, nullptr, LOAD_NoWarn);

				if (Action != nullptr)
				{
					EnhancedInputComponent->BindAction(Action, ETriggerEvent::Triggered, this, &UNoesisInstance::OnEnhancedInputActionTriggered, Event.Value);
					EnhancedInputComponent->BindAction(Action, ETriggerEvent::Completed, this, &UNoesisInstance::OnEnhancedInputActionCompleted, Event.Value);
					EnhancedInputComponent->BindAction(Action, ETriggerEvent::Canceled, this, &UNoesisInstance::OnEnhancedInputActionCompleted, Event.Value);
				}
			}

			TPair<const TCHAR*, typename FEnhancedInputActionHandlerValueSignature::template TMethodPtr<UNoesisInstance>> InputValueEvents[] = {
				{ TEXT("/NoesisGUI/EnhancedInput/HorizontalScroll"), &UNoesisInstance::OnEnhancedInputActionHorizontalScroll },
				{ TEXT("/NoesisGUI/EnhancedInput/VerticalScroll"), &UNoesisInstance::OnEnhancedInputActionVerticalScroll }
			};

			for (const auto& Event : InputValueEvents)
			{
				UInputAction* Action = LoadObject<UInputAction>(nullptr, Event.Key, nullptr, LOAD_NoWarn);

				if (Action != nullptr)
				{
					EnhancedInputComponent->BindAction(Action, ETriggerEvent::Triggered, this, Event.Value);
				}
			}
		}
#endif
	}
}

void UNoesisInstance::SetDataContext(UObject* InDataContext)
{
	DataContext = Noesis::Ptr<Noesis::BaseComponent>(NoesisCreateComponentForUObject(InDataContext));

	if (Xaml)
	{
		Xaml->SetDataContext(DataContext);
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
	UWorld* World = GetWorld();
	if (World)
	{
		return World->GetTimeSeconds();
	}
	else if (GWorld)
	{
		return GWorld->GetTimeSeconds();
	}

	return -1.f;
}

void UNoesisInstance::UpdateWorldTime()
{
	UWorld* World = GetWorld();
	if (IsValid(World))
	{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
		WorldTime = FGameTime::CreateDilated(World->GetRealTimeSeconds(), 0.0f, World->GetTimeSeconds(), World->GetDeltaSeconds());
#else
		WorldTime = World->GetTime();
#endif
		Scene = World->Scene;
	}
	else if (IsValid(GWorld))
	{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
		WorldTime = FGameTime::CreateDilated(GWorld->GetRealTimeSeconds(), 0.0f, GWorld->GetTimeSeconds(), GWorld->GetDeltaSeconds());
#else
		WorldTime = GWorld->GetTime();
#endif
		Scene = GWorld->Scene;
	}
	else
	{
		Scene = nullptr;
	}
}

UInputComponent* UNoesisInstance::GetInputComponent()
{
	if (!InputComponent)
	{
		InitializeInputComponent();
	}

	return InputComponent;
}

void UNoesisInstance::RegisterInputAction(FInputActionBinding Binding)
{
	if (!InputComponent)
	{
		InitializeInputComponent();
	}

	if (InputComponent)
	{
		InputComponent->AddActionBinding(Binding);
	}
}

void UNoesisInstance::UnregisterInputAction(FInputActionBinding Binding)
{
	StopListeningForInputAction(Binding.GetActionName(), Binding.KeyEvent);
}

#if WITH_ENHANCED_INPUT
void UNoesisInstance::OnEnhancedInputActionTriggered(Noesis::Key Key)
{
	if (EnableActions && XamlView != nullptr)
	{
		XamlView->KeyDown(Key);
	}
}

void UNoesisInstance::OnEnhancedInputActionCompleted(Noesis::Key Key)
{
	if (EnableActions && XamlView != nullptr)
	{
		XamlView->KeyUp(Key);
	}
}

void UNoesisInstance::OnEnhancedInputActionHorizontalScroll(const struct FInputActionValue& Value)
{
	check(Value.GetValueType() == EInputActionValueType::Axis1D);

	if (EnableActions && XamlView != nullptr)
	{
		XamlView->HScroll(Value.Get<float>());
	}
}

void UNoesisInstance::OnEnhancedInputActionVerticalScroll(const struct FInputActionValue& Value)
{
	check(Value.GetValueType() == EInputActionValueType::Axis1D);

	if (EnableActions && XamlView != nullptr)
	{
		XamlView->Scroll(-Value.Get<float>());
	}
}
#endif

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

void UNoesisInstance::Update()
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_Update);

	if (Xaml && XamlView)
	{
		XamlView->SetSize(Width, Height);
		
		if (PixelDepthBias >= 0.f)
		{
			float D = PixelDepthBias / 1000.f;
			float W = D * Width;
			float H = D * Height;

			Noesis::Matrix4 Projection
			(
				PixelDepthBias,             0.0f, 0.0f, 0.0f,
				            0.0f, PixelDepthBias, 0.0f, 0.0f,
				        0.5f * W,         0.5f * H, 0.0f, D,
				            0.0f,             0.0f, 10.f, PixelDepthBias
			);

			XamlView->SetProjectionMatrix(Projection);
		}

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
		uint32 Flags = XamlView->GetFlags();
		if (EnablePPAA)
		{
			Flags |= Noesis::RenderFlags_PPAA;
		}
		else
		{
			Flags &= ~Noesis::RenderFlags_PPAA;
		}
		if (Is3DWidget)
		{
			Flags |= Noesis::RenderFlags_DepthTesting;
		}
		XamlView->SetFlags(Flags);
		XamlView->SetEmulateTouch(EmulateTouch);
		XamlView->Update(CurrentTime);
		UpdateWorldTime();
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

void UNoesisInstance::Init3DWidget(UWorld* World)
{
	AddToRoot();
	Is3DWidget = true;
	EnablePPAA = true;
	TessellationQuality = ENoesisTessellationQuality::High;
	SetPlayerContext(FLocalPlayerContext(World->GetFirstLocalPlayerFromController(), World));
	InitInstance();
	FWorldDelegates::OnWorldPostActorTick.AddUObject(this, &UNoesisInstance::Tick3DWidget);
	FWorldDelegates::OnWorldBeginTearDown.AddUObject(this, &UNoesisInstance::Term3DWidget);
	FCoreDelegates::OnSafeFrameChangedEvent.AddUObject(this, &UNoesisInstance::ViewportResized3DWidget);
	if (XamlView != nullptr)
	{
		ENQUEUE_RENDER_COMMAND(FNoesisInstance_Add3DSlateElement)
		(
			[NoesisSlateElement = NoesisSlateElement](FRHICommandListImmediate& RHICmdList)
			{
				GNoesis3DSlateElements.AddUnique(NoesisSlateElement.Get());
			}
		);
	}
}

void UNoesisInstance::Term3DWidget(UWorld* World)
{
	check(Is3DWidget);

	if (GetWorld() != World)
		return;

	if (XamlView != nullptr)
	{
		ENQUEUE_RENDER_COMMAND(FNoesisInstance_Add3DSlateElement)
		(
			[NoesisSlateElement = NoesisSlateElement](FRHICommandListImmediate& RHICmdList)
			{
				GNoesis3DSlateElements.Remove(NoesisSlateElement.Get());
			}
		);
	}
	TermInstance();
	FCoreDelegates::OnSafeFrameChangedEvent.RemoveAll(this);
	FWorldDelegates::OnWorldPostActorTick.RemoveAll(this);
	Is3DWidget = false;
	RemoveFromRoot();
}

void UNoesisInstance::Tick3DWidget(UWorld* World, ELevelTick TickType, float DeltaTime)
{
	check(Is3DWidget);

	if (GetWorld() != World)
		return;

	CurrentTime += DeltaTime;

	if (XamlView != nullptr)
	{
		APlayerController* PlayerController = GetOwningPlayer();
		if (PlayerController)
		{
			ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PlayerController->Player);
			if (LocalPlayer)
			{
				UGameViewportClient* ViewportClient = GWorld->GetGameViewport();

				if (ViewportClient != nullptr)
				{
					FSceneViewport* Viewport = ViewportClient->GetGameViewport();
					FSceneViewProjectionData ViewProjectionData;
					LocalPlayer->GetProjectionData(Viewport, ViewProjectionData, INDEX_NONE);
					auto UnscaledViewRect = ViewProjectionData.GetConstrainedViewRect();
					//auto UnconstrainedViewRect = ViewProjectionData.GetViewRect();
					Left = UnscaledViewRect.Min.X;
					Top = UnscaledViewRect.Min.Y;
					Width = (UnscaledViewRect.Max.X - Left);
					Height = (UnscaledViewRect.Max.Y - Top);

					auto StereoRenderingDevice = GEngine->StereoRenderingDevice.Get();
					if (GEngine->IsStereoscopic3D() && StereoRenderingDevice != nullptr)
					{
						auto WorldToMetersScale = PlayerController->GetWorldSettings()->WorldToMeters;
						FVector MonoLocation;
						FRotator MonoRotation;
						PlayerController->GetPlayerViewPoint(MonoLocation, MonoRotation);
						StereoRenderingDevice->CalculateStereoViewOffset(eSSE_MONOSCOPIC, MonoRotation, WorldToMetersScale, MonoLocation);
						const FMatrix ViewRotationMatrix = FInverseRotationMatrix(MonoRotation) * FMatrix(
							FPlane(0, 0, 1, 0),
							FPlane(1, 0, 0, 0),
							FPlane(0, 1, 0, 0),
							FPlane(0, 0, 0, 1));
						const FMatrix ViewMatrixForCulling = FTranslationMatrix(-MonoLocation) * ViewRotationMatrix;
						const FMatrix ViewProjForCulling = ViewMatrixForCulling * StereoRenderingDevice->GetStereoProjectionMatrix(eSSE_MONOSCOPIC);

						Noesis::Matrix4 ViewProj = UnrealToNoesisViewProj(ViewProjForCulling, Width, Height);

						ENQUEUE_RENDER_COMMAND(CopyViewProj)
						(
							[NoesisSlateElement = NoesisSlateElement, ViewProjectionMatrix = ViewProjForCulling](FRHICommandListImmediate& RHICmdList) mutable
							{
								NoesisSlateElement->ViewProjectionMatrix = ViewProjectionMatrix;
							}
						);
						XamlView->SetProjectionMatrix(ViewProj);
								}
					else
					{
						Noesis::Matrix4 ViewProj = UnrealToNoesisViewProj(ViewProjectionData.ComputeViewProjectionMatrix(), Width, Height);

						ENQUEUE_RENDER_COMMAND(CopyViewProj)
						(
							[NoesisSlateElement = NoesisSlateElement, ViewProjectionMatrix = ViewProjectionData.ComputeViewProjectionMatrix()](FRHICommandListImmediate& RHICmdList) mutable
							{
								NoesisSlateElement->ViewProjectionMatrix = ViewProjectionMatrix;
							}
						);
						XamlView->SetProjectionMatrix(ViewProj);
					}
				}
			}
		}

		Update();

		ENQUEUE_RENDER_COMMAND(FNoesisInstance_Tick3DWidget_UpdateSlateElement)
		(
			[NoesisSlateElement = NoesisSlateElement, Scene = Scene, WorldTime = WorldTime](FRHICommandListImmediate& RHICmdList)
			{
				NoesisSlateElement->Scene = Scene;
				NoesisSlateElement->WorldTime = WorldTime;
				NoesisSlateElement->UpdateRenderTree();
				NoesisSlateElement->RenderOffscreen(RHICmdList);
			}
		);
	}
}

void UNoesisInstance::ViewportResized()
{
}

void UNoesisInstance::ViewportResized3DWidget()
{
	check(Is3DWidget);

	Tick3DWidget(GetWorld(), LEVELTICK_TimeOnly, 0.0f);
}

static UNoesisInstance* Find3DInstanceForWorld(UWorld* World)
{
	for (auto ViewInstancePair : ViewInstanceMap)
	{
		UNoesisInstance* NoesisInstance = ViewInstancePair.Value;
		if (NoesisInstance->Is3DWidget && NoesisInstance->GetWorld() == World)
		{
			return NoesisInstance;
		}
	}

	return nullptr;
}

static UNoesisInstance* Get3DInstance(UWorld* World)
{
	UNoesisInstance* NoesisInstance = Find3DInstanceForWorld(World);
	if (NoesisInstance != nullptr)
	{
		return NoesisInstance;
	}

	NoesisInstance = NewObject<UNoesisInstance>(World);
	NoesisInstance->BaseXaml = LoadObject<UNoesisXaml>(nullptr, TEXT("/NoesisGUI/WorldUI.WorldUI"));
	NoesisInstance->Init3DWidget(World);

	return NoesisInstance;
}

void UNoesisInstance::Add3DElement(UWorld* World, Noesis::FrameworkElement* Element)
{
	auto NoesisInstance = Get3DInstance(World);

	auto Panel = NoesisInstance->Xaml->FindName<Noesis::Panel>("Root");
	if (Panel != nullptr)
	{
		auto Children = Panel->GetChildren();
		Children->Add(Element);
	}
}

void UNoesisInstance::Remove3DElement(UWorld* World, Noesis::FrameworkElement* Element)
{
	auto NoesisInstance = Find3DInstanceForWorld(World);
	if (NoesisInstance == nullptr)
		return;

	auto Panel = NoesisInstance->Xaml->FindName<Noesis::Panel>("Root");
	if (Panel != nullptr)
	{
		auto Children = Panel->GetChildren();
		Children->Remove(Element);
	}
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
	NoesisHitTestVisibleTester(): Hit(nullptr) { }

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

bool UNoesisInstance::HitTest(FVector2D Position) const
{
	NoesisHitTestVisibleTester HitTester;

	if (Xaml)
	{
		Noesis::Visual* root = Noesis::VisualTreeHelper::GetRoot(Xaml);
		Noesis::Point p = root->PointFromScreen(Noesis::Point(Position.X, Position.Y));
		Noesis::VisualTreeHelper::HitTest(root, p,
			MakeDelegate(&HitTester, &NoesisHitTestVisibleTester::Filter),
			MakeDelegate(&HitTester, &NoesisHitTestVisibleTester::Result));
	}

	return HitTester.Hit != nullptr;
}

void UNoesisInstance::TermInstance()
{
	if (XamlView)
	{
#if WITH_ENHANCED_INPUT
		auto ThisInputComponent = GetInputComponent();

		if (auto EnhancedInputComponent = Cast<UEnhancedInputComponent>(ThisInputComponent))
		{
#if UE_VERSION_OLDER_THAN(5, 1, 0)
			EnhancedInputComponent->ClearActionEventBindings();
			EnhancedInputComponent->ClearActionValueBindings();
#else
			EnhancedInputComponent->ClearBindingsForObject(this);
#endif
		}
#endif

		ViewInstanceMap.Remove(XamlView.GetPtr());
		ViewInstanceMap.Shrink();

		Noesis::Ptr<Noesis::IRenderer> Renderer(XamlView->GetRenderer());
		Xaml.Reset();
		XamlView.Reset();

		// Pass the slate element to the render thread so that it's deleted after it's shown for the last time
		ENQUEUE_RENDER_COMMAND(SafeDeleteNoesisSlateElement)
		(
			[Renderer, Is3DWidget = Is3DWidget, NoesisSlateElement = MoveTemp(NoesisSlateElement)](FRHICommandListImmediate& RHICmdList) mutable
			{
				NoesisSlateElement.Reset();

				if (!Is3DWidget)
				{
					if (--GSlateElementCount == 0)
					{
						if (GDepthStencilTarget.IsValid())
						{
							GDepthStencilTarget.SafeRelease();
						}
					}
				}
			}
		);
	}

	ITextInputMethodSystem* const TextInputMethodSystem = FSlateApplication::IsInitialized() ? FSlateApplication::Get().GetTextInputMethodSystem() : nullptr;
	if (TextInputMethodSystem)
	{
		for (auto TextInputMethodContextPair : TextInputMethodContexts)
		{
			auto TextInputMethodContext = TextInputMethodContextPair.Value;
			if (TextInputMethodSystem->IsActiveContext(TextInputMethodContext.ToSharedRef()))
			{
				TextInputMethodSystem->DeactivateContext(TextInputMethodContext.ToSharedRef());
			}
			TextInputMethodSystem->UnregisterContext(TextInputMethodContext.ToSharedRef());
		}
		TextInputMethodContexts.Empty();
	}
}

void UNoesisInstance::BeginDestroy()
{
	Super::BeginDestroy();

	TermInstance();
}

void UNoesisInstance::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	Ar.UsingCustomVersion(FNoesisCustomVersion::GUID);
}

void UNoesisInstance::PostLoad()
{
	Super::PostLoad();

#if WITH_EDITOR
	const int32 NoesisVer = GetLinkerCustomVersion(FNoesisCustomVersion::GUID);
	if (NoesisVer < FNoesisCustomVersion::BeforeCustomVersionWasAdded)
	{
		UClass* Class = GetClass();
		UNoesisBlueprint* NoesisBlueprint = Cast<UNoesisBlueprint>(Class->ClassGeneratedBy);
		if (NoesisBlueprint != nullptr)
		{
			BaseXaml = NoesisBlueprint->BaseXaml;
			EnablePPAA = NoesisBlueprint->EnablePPAA;
			TessellationQuality = NoesisBlueprint->TessellationQuality;
		}
	}
#endif
}

void UNoesisInstance::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	for (TObjectIterator<UWidgetComponent> It; It; ++It)
	{
		if (It->GetUserWidgetObject() == this)
		{
			WidgetComponent = *It;
			break;
		}
	}
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
#endif // WITH_EDITOR

bool UNoesisInstance::Initialize()
{
	SetDataContext(this);

	return Super::Initialize();
}

void UNoesisInstance::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	CurrentTime += InDeltaTime;

	FSlateRect SlateRect = MyGeometry.GetLayoutBoundingRect().Round();
	FVector2D SlateRectSize = SlateRect.GetSize();
	Left = SlateRect.Left;
	Top = SlateRect.Top;
	Width = SlateRectSize.X;
	Height = SlateRectSize.Y;

	Update();
}

bool GetHitResultAtScreenPositionAndCache(APlayerController* PlayerController, FVector2D ScreenPosition, FHitResult& HitResult)
{
	static int64 CachedFrame;
	static FVector2D CachedScreenPosition;
	static FHitResult CachedHitResult;

	UPrimitiveComponent* HitComponent = nullptr;

	if (GFrameNumber != CachedFrame || CachedScreenPosition != ScreenPosition)
	{
		CachedFrame = GFrameNumber;
		CachedScreenPosition = ScreenPosition;

		if (PlayerController)
		{
			if (PlayerController->GetHitResultAtScreenPosition(ScreenPosition, ECC_Visibility, true, CachedHitResult))
			{
				HitResult = CachedHitResult;
				return true;
			}
		}
	}
	else
	{
		HitResult = CachedHitResult;
		return true;
	}

	return false;
}

int32 UNoesisInstance::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	check(!Is3DWidget);
	int32 MaxLayer = Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	if (GetVisibility() == ESlateVisibility::SelfHitTestInvisible)
	{
		TSharedPtr<ICursor> PlatformCursor = FSlateApplication::Get().GetPlatformCursor();
		auto ScreenSpacePosition = PlatformCursor->GetPosition() - Args.GetWindowToDesktopTransform();
		FVector2D Position = AllottedGeometry.AbsoluteToLocal(ScreenSpacePosition) * AllottedGeometry.Scale;

		APlayerController* OwningPlayer = GetOwningPlayer();

		bool WidgetComponentHit = false;
		if (OwningPlayer != nullptr && WidgetComponent != nullptr && WidgetComponent->GetReceiveHardwareInput() &&
			WidgetComponent->GetCurrentDrawSize().X != 0 && WidgetComponent->GetCurrentDrawSize().Y != 0)
		{
			UWorld* World = GetWorld();
			UGameViewportClient* ViewportClient = World->GetGameViewport();

			if (ViewportClient != nullptr)
			{
				FSceneViewport* Viewport = ViewportClient->GetGameViewport();
				auto ViewportWidget = Viewport->GetViewportWidget();
				auto PinnedViewportWidget = ViewportWidget.Pin();
				if (PinnedViewportWidget.IsValid())
				{
					auto ViewportGeometry = PinnedViewportWidget->GetTickSpaceGeometry();
					FVector2D HitTestPosition = ViewportGeometry.AbsoluteToLocal(PlatformCursor->GetPosition()) * ViewportGeometry.Scale;
					FHitResult HitResult;
					if (GetHitResultAtScreenPositionAndCache(OwningPlayer, HitTestPosition, HitResult))
					{
						if ((UPrimitiveComponent*)WidgetComponent == HitResult.GetComponent())
						{
							// Get the "forward" vector based on the current rotation system.
							const FVector ForwardVector = WidgetComponent->GetForwardVector();

							// Make sure the player is interacting with the front of the widget
							if (FVector::DotProduct(ForwardVector, HitResult.ImpactPoint - HitResult.TraceStart) < 0.f)
							{
								WidgetComponent->GetLocalHitLocation(HitResult.Location, Position);
								WidgetComponentHit = true;
							}
						}
					}
				}
			}
		}

		bool Hit = false;
		if (WidgetComponent == nullptr || WidgetComponentHit)
		{
			Hit = HitTest(Position);
		}

		auto PinnedWidget = MyWidget.Pin();
		if (Hit)
		{
			if (PinnedWidget.IsValid())
			{
				auto& HittestGrid = Args.GetHittestGrid();
				PinnedWidget->SetVisibility(EVisibility::Visible);
#if UE_VERSION_OLDER_THAN(4, 27, 0)
				HittestGrid.AddWidget(PinnedWidget.ToSharedRef(), 0, LayerId, 0);
#elif UE_VERSION_OLDER_THAN(5, 0, 0)
				HittestGrid.AddWidget(PinnedWidget.ToSharedRef(), 0, LayerId, FSlateInvalidationWidgetSortOrder());
#else				
				HittestGrid.AddWidget(PinnedWidget.Get(), 0, LayerId, FSlateInvalidationWidgetSortOrder());
#endif
			}
		}
		else
		{
			if (XamlView)
			{
				XamlView->MouseMove(Position.X, Position.Y);
			}
			auto& HittestGrid = Args.GetHittestGrid();
			HittestGrid.RemoveWidget(PinnedWidget.Get());
			PinnedWidget->SetVisibility(EVisibility::SelfHitTestInvisible);
		}
	}

	if (XamlView != nullptr)
	{
		ENQUEUE_RENDER_COMMAND(FNoesisInstance_NativePaint_UpdateSlateElement)
		(
			[NoesisSlateElement = NoesisSlateElement, EngineGamma = GEngine ? GEngine->GetDisplayGamma() : 2.2f, SlateContrast = GSlateContrast,
			SlateRect = AllottedGeometry.GetLayoutBoundingRect().Round(),
			Scene = Scene, WorldTime = WorldTime](FRHICommandListImmediate& RHICmdList)
			{
				NoesisSlateElement->EngineGamma = EngineGamma;
				NoesisSlateElement->SlateContrast = SlateContrast;

				NoesisSlateElement->Left = SlateRect.Left;
				NoesisSlateElement->Top = SlateRect.Top;
				NoesisSlateElement->Right = SlateRect.Right;
				NoesisSlateElement->Bottom = SlateRect.Bottom;

				NoesisSlateElement->Scene = Scene;
				NoesisSlateElement->IsMobileMultiView = false;
				NoesisSlateElement->WorldTime = WorldTime;
				NoesisSlateElement->UpdateRenderTree();
				NoesisSlateElement->RenderOffscreen(RHICmdList);
			}
		);

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
	return KeyMap;
}

Noesis::Key* KeyToNoesisKey(FKey Key)
{
	static TMap<FKey, Noesis::Key> KeyMap = InitKeyMap();
	Noesis::Key* NoesisKey = nullptr;
	NoesisKey = KeyMap.Find(Key);
	return NoesisKey;
}

extern bool GNoesisIsEnteringText;

FReply UNoesisInstance::NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	SupportsKeyboardFocus = !EnableActions;

	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnKeyDown);
	if ((EnableKeyboard || GNoesisIsEnteringText) && XamlView)
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
	if ((EnableKeyboard || GNoesisIsEnteringText) && XamlView)
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

static Noesis::MouseButton GetNoesisMouseButton(FKey Button)
{
	if (Button == EKeys::LeftMouseButton) return Noesis::MouseButton_Left;
	if (Button == EKeys::RightMouseButton) return Noesis::MouseButton_Right;
	if (Button == EKeys::MiddleMouseButton) return Noesis::MouseButton_Middle;
	if (Button == EKeys::ThumbMouseButton) return Noesis::MouseButton_XButton1;
	return Noesis::MouseButton_XButton2;
}

FReply UNoesisInstance::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnMouseButtonDown);
	if (EnableMouse && XamlView)
	{
#if WITH_COMMON_UI
		ULocalPlayer* LocalPlayer = GetOwningLocalPlayer();
		if (LocalPlayer != nullptr)
		{
			if (UCommonInputSubsystem* CommonInputSubsystem = UCommonInputSubsystem::Get(GetOwningLocalPlayer()))
			{
				IsGamepadSimulatedClick = CommonInputSubsystem->GetIsGamepadSimulatedClick();
			}
		}
#endif

		if (IsGamepadSimulatedClick)
		{
			bool Handled = XamlView->KeyDown(Noesis::Key_GamepadAccept);

			if (Handled)
			{
				return FReply::Handled().PreventThrottling().CaptureMouse(MyWidget.Pin().ToSharedRef());
			}
		}
		else
		{
			FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
			bool Hit = HitTest(Position);

			Noesis::MouseButton MouseButton = GetNoesisMouseButton(MouseEvent.GetEffectingButton());
			bool Handled = XamlView->MouseButtonDown(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);

			if (Handled && Hit)
			{
				return FReply::Handled().PreventThrottling();
			}
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnMouseButtonUp);
	if (EnableMouse && XamlView)
	{
		if (IsGamepadSimulatedClick)
		{
			IsGamepadSimulatedClick = false;
			bool Handled = XamlView->KeyUp(Noesis::Key_GamepadAccept);

			if (Handled)
			{
				return FReply::Handled().PreventThrottling();
			}
		}
		else
		{
			FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
			bool Hit = HitTest(Position);

			Noesis::MouseButton MouseButton = GetNoesisMouseButton(MouseEvent.GetEffectingButton());
			bool Handled = XamlView->MouseButtonUp(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);

			if (Handled && Hit)
			{
				return FReply::Handled().PreventThrottling();
			}
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnMouseMove);
	if (EnableMouse && XamlView && !MouseEvent.GetCursorDelta().IsZero()) // Ignore synthetic events that are messing with the tooltip code.
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		bool Hit = HitTest(Position);

		bool Handled = XamlView->MouseMove(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y));

		if (Handled && Hit)
		{
			return FReply::Handled().PreventThrottling();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnMouseWheel);
	if (EnableMouse && XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		bool Hit = HitTest(Position);

		float WheelDelta = MouseEvent.GetWheelDelta();
		bool Handled = XamlView->MouseWheel(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), FPlatformMath::RoundToInt(WheelDelta * 120.f));

		if (Handled && Hit)
		{
			return FReply::Handled().PreventThrottling();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnTouchStarted(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnTouchStarted);
	if (EnableTouch && XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(TouchEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		bool Hit = HitTest(Position);

		uint32 PointerIndex = TouchEvent.GetPointerIndex();
		bool Handled = XamlView->TouchDown(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), PointerIndex);

		if (Handled && Hit)
		{
			return FReply::Handled().PreventThrottling();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnTouchMoved(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnTouchMoved);
	if (EnableTouch && XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(TouchEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		bool Hit = HitTest(Position);

		uint32 PointerIndex = TouchEvent.GetPointerIndex();
		bool Handled = XamlView->TouchMove(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), PointerIndex);

		if (Handled && Hit)
		{
			return FReply::Handled().PreventThrottling();
		}
	}

	return FReply::Unhandled();
}

FReply UNoesisInstance::NativeOnTouchEnded(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisInstance_OnTouchEnded);
	if (EnableTouch && XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(TouchEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		bool Hit = HitTest(Position);

		uint32 PointerIndex = TouchEvent.GetPointerIndex();
		bool Handled = XamlView->TouchUp(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), PointerIndex);

		if (Handled && Hit)
		{
			return FReply::Handled().PreventThrottling();
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
	if (EnableMouse && XamlView)
	{
		FVector2D Position = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale;
		bool Hit = HitTest(Position);

		Noesis::MouseButton MouseButton = GetNoesisMouseButton(MouseEvent.GetEffectingButton());
		bool Handled = XamlView->MouseDoubleClick(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);

		if (Handled && Hit)
		{
			return FReply::Handled().PreventThrottling();
		}
	}

	return FReply::Unhandled();
}

bool UNoesisInstance::NativeSupportsKeyboardFocus() const
{
	// SObjectWidget::OnKeyDown calls UNoesisInstance::NativeOnKeyDown. There we set SupportsKeyboardFocus = !EnableActions.
	// SObjectWidget::OnKeyDown then calls SCompundWidget::OnKeyDown, which calls this function.
	// If this function returns true, then SCompundWidget::OnKeyDown will handle de event, and it won't trigger actions.
	// SupportsKeyboardFocus is reset here so that every other call to this function returns true.
	bool Result = SupportsKeyboardFocus;
	SupportsKeyboardFocus = true;
	return Result;
}

void UNoesisInstance::NativeConstruct()
{
	Super::NativeConstruct();

	InitInstance();
}

void UNoesisInstance::NativeDestruct()
{
	TermInstance();

	Super::NativeDestruct();
}

// This is a copy of FMobileSceneRenderer::RequiresMultiPass
static bool RequiresMultiPass(EShaderPlatform ShaderPlatform, uint32 NumMSAASamples)
{
	// Vulkan uses subpasses
	if (IsVulkanPlatform(ShaderPlatform))
	{
		return false;
	}

	// All iOS support frame_buffer_fetch
	if (IsMetalMobilePlatform(ShaderPlatform) && GSupportsShaderFramebufferFetch)
	{
		return false;
	}

	// Some Androids support frame_buffer_fetch
	if (IsAndroidOpenGLESPlatform(ShaderPlatform) && (GSupportsShaderFramebufferFetch || GSupportsShaderDepthStencilFetch))
	{
		return false;
	}

	// Only Vulkan, iOS and some GL can do a single pass deferred shading, otherwise multipass
	if (IsMobileDeferredShadingEnabled(ShaderPlatform))
	{
		return true;
	}

	// Always render LDR in single pass
	if (!IsMobileHDR())
	{
		return false;
	}

	// MSAA depth can't be sampled or resolved, unless we are on PC (no vulkan)
	if (NumMSAASamples > 1 && !IsSimulatedPlatform(ShaderPlatform))
	{
		return false;
	}

	return true;
}

struct FRendererInfo
{
	EShadingPath ShadingPath;
	bool IsMobileShadingPath;
	ERHIFeatureLevel::Type FeatureLevel;
	EShaderPlatform ShaderPlatform;
	bool IsMobileDeferredShadingPath;
	int32 NumSceneColorMSAASamples;
	bool IsMobileMultiPass;
};

static FRendererInfo GetRendererInfo(const FViewInfo* View)
{
	FRendererInfo RendererInfo;

	const auto ViewFamily = View->Family;
	FSceneInterface* Scene = ViewFamily->Scene;

	RendererInfo.ShadingPath = Scene->GetShadingPath();
	RendererInfo.IsMobileShadingPath = RendererInfo.ShadingPath == EShadingPath::Mobile;
	RendererInfo.FeatureLevel = Scene->GetFeatureLevel();
	RendererInfo.ShaderPlatform = Scene->GetShaderPlatform();
	RendererInfo.IsMobileDeferredShadingPath = RendererInfo.IsMobileShadingPath && IsMobileDeferredShadingEnabled(RendererInfo.ShaderPlatform);
	RendererInfo.NumSceneColorMSAASamples = View->CachedViewUniformShaderParameters->NumSceneColorMSAASamples;
	RendererInfo.IsMobileMultiPass = RendererInfo.IsMobileShadingPath && RequiresMultiPass(RendererInfo.ShaderPlatform, RendererInfo.NumSceneColorMSAASamples);

	return RendererInfo;
}

static bool Render3DPostOpaque(const FRendererInfo& RendererInfo)
{
	return !RendererInfo.IsMobileShadingPath || RendererInfo.IsMobileDeferredShadingPath;
}

static void AddWorldUIRenderPass(FRDGBuilder& GraphBuilder, FRDGTexture* ColorTexture, FRDGTexture* DepthStencilTexture, const FViewInfo& View)
{
	FRenderTargetParameters* PassParameters = GraphBuilder.AllocParameters<FRenderTargetParameters>();
	{
		PassParameters->RenderTargets[0] = FRenderTargetBinding(ColorTexture, ERenderTargetLoadAction::ELoad);
		PassParameters->RenderTargets.DepthStencil = FDepthStencilBinding(DepthStencilTexture, ERenderTargetLoadAction::ELoad, ERenderTargetLoadAction::EClear, FExclusiveDepthStencil::DepthRead_StencilWrite);
	}
	GraphBuilder.AddPass(RDG_EVENT_NAME("NoesisTranslucentPass"), PassParameters, ERDGPassFlags::Raster | ERDGPassFlags::NeverCull,
		[&View](FRHICommandListImmediate& RHICmdList)
		{
			for (auto NoesisSlateElement : GNoesis3DSlateElements)
			{
				FNoesisRenderDevice* RenderDevice = NoesisSlateElement->RenderDevice;
				RenderDevice->IsWorldUI = true;
				NoesisSlateElement->RenderView(RHICmdList, (FViewInfo*)&View);
				RenderDevice->IsWorldUI = false;
			}
		}
	);
}

void NoesisDrawRenderThreadOverlay(FPostOpaqueRenderParameters& Params)
{
	const auto& View = (const FViewInfo&)*Params.View;
	const auto ViewFamily = View.Family;

	if (ViewFamily->Scene->IsEditorScene())
		return;

	if (GNoesis3DSlateElements.Num() == 0)
		return;

	if (ViewFamily->AllowTranslucencyAfterDOF())
		return;

	auto ColorTexture = Params.ColorTexture;
	auto DepthStencilTexture = Params.DepthTexture;

	if (ColorTexture == nullptr || DepthStencilTexture == nullptr)
		return;

	auto& GraphBuilder = *Params.GraphBuilder;
	AddWorldUIRenderPass(GraphBuilder, ColorTexture, DepthStencilTexture, View);
}

FDelegateHandle NoesisRegisterOverlayRender()
{
	return GetRendererModule().RegisterOverlayRenderDelegate(FPostOpaqueRenderDelegate::CreateStatic(&NoesisDrawRenderThreadOverlay));
}

void NoesisUnregisterOverlayRender(FDelegateHandle InOverlayRenderDelegateHandle)
{
	GetRendererModule().RemovePostOpaqueRenderDelegate(InOverlayRenderDelegateHandle);
}

class FNoesisSceneViewExtension : public FSceneViewExtensionBase
{
public:

	FNoesisSceneViewExtension(const FAutoRegister& AutoRegister)
		: FSceneViewExtensionBase(AutoRegister)
	{
	}

	virtual ~FNoesisSceneViewExtension()
	{
	}

	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override
	{
	}

	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override
	{
	}

	virtual void SetupViewPoint(APlayerController* Player, FMinimalViewInfo& InViewInfo) override
	{
	}

	virtual void SetupViewProjectionMatrix(FSceneViewProjectionData& InOutProjectionData) override
	{
	}

	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override
	{
	}

	virtual void PreRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily) override
	{
	}

	virtual void PreRenderView_RenderThread(FRDGBuilder& GraphBuilder, FSceneView& InView) override
	{
		// Figure out if any of our post process materials uses custom depth/stencil
		// Check GetCustomDepthStencilUsage in MobileShadingRenderer.cpp
	}

	virtual void PrePostProcessPass_RenderThread(FRDGBuilder& GraphBuilder, const FSceneView& InView, const FPostProcessingInputs& Inputs) override
	{
		const auto& View = (const FViewInfo&)InView;
		const auto ViewFamily = View.Family;

#if UE_VERSION_OLDER_THAN(5, 1, 0)
		if (!View.bIsSceneCapture)
#else
		if (!View.bIsSceneCapture && !View.bIsSceneCaptureCube)
#endif
		{
			GViewRect = View.ViewRect;
			GViewProjectionMatrix = View.ViewMatrices.GetProjectionMatrix();
		}

		if (ViewFamily->Scene->IsEditorScene())
			return;

		if (GNoesis3DSlateElements.Num() == 0)
			return;

		const FTranslucencyPassResources& PostDOFTranslucencyResources = Inputs.TranslucencyViewResourcesMap.Get(ETranslucencyPass::TPT_TranslucencyAfterDOF);

		auto ColorTexture = PostDOFTranslucencyResources.ColorTexture.Target;
		auto DepthStencilTexture = PostDOFTranslucencyResources.DepthTexture.Target;

		if (ColorTexture == nullptr || DepthStencilTexture == nullptr)
			return;

		AddWorldUIRenderPass(GraphBuilder, ColorTexture, DepthStencilTexture, View);
	}

	virtual void SubscribeToPostProcessingPass(EPostProcessingPass Pass, FAfterPassCallbackDelegateArray& InOutPassCallbacks, bool bIsPassEnabled) override
	{
	}

	virtual void PostRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily) override
	{
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		if (InViewFamily.Views[0]->bIsSceneCapture)
#else
		if (InViewFamily.Views[0]->bIsSceneCapture || InViewFamily.Views[0]->bIsSceneCaptureCube)
#endif
			return;

		if (InViewFamily.RenderTarget->GetRenderTargetTexture() == nullptr)
			return;

		FRDGTextureRef SceneColor = InViewFamily.RenderTarget->GetRenderTargetTexture(GraphBuilder);

		FRenderTargetParameters* PassParameters = GraphBuilder.AllocParameters<FRenderTargetParameters>();
		PassParameters->RenderTargets[0] = FRenderTargetBinding(SceneColor, ERenderTargetLoadAction::ELoad);
		GraphBuilder.AddPass(RDG_EVENT_NAME("NoesisGrabBackgroundImage"), PassParameters, ERDGPassFlags::Raster | ERDGPassFlags::NeverCull,
			[SceneColor](FRHICommandListImmediate& RHICmdList)
			{
				auto TextureRef = SceneColor->GetRHI();

				if (TextureRef != nullptr)
				{
					BackgroundImage::SetBackgroundImageTexture(TextureRef->GetTexture2D());
				}
			}
		);
	}

#if UE_VERSION_OLDER_THAN(5, 1, 0)
	virtual void PostRenderBasePass_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) override
#elif UE_VERSION_OLDER_THAN(5, 3, 0)
	virtual void PostRenderBasePassMobile_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) override
#else
	virtual void PostRenderBasePassMobile_RenderThread(FRHICommandList& RHICmdList, FSceneView& InView) override
#endif
	{
		if (GNoesis3DSlateElements.Num() == 0)
			return;

		check(InView.bIsViewInfo);
		const FViewInfo* View = (FViewInfo*)&InView;

		FRendererInfo RendererInfo = GetRendererInfo(View);
		if (Render3DPostOpaque(RendererInfo))
			return;

		// We need to clear the stencil buffer, since we're in the SceneColor pass
		const auto& ViewRect = View->ViewRect;
		auto Left = ViewRect.Min.X;
		auto Top = ViewRect.Min.Y;
		auto Right = ViewRect.Max.X;
		auto Bottom = ViewRect.Max.Y;
		RHICmdList.SetViewport(Left, Top, 0.0f, Right, Bottom, 1.0f);
		DrawClearQuad(RHICmdList, false, FLinearColor(), false, 0.f, true, 0);
		for (auto NoesisSlateElement : GNoesis3DSlateElements)
		{
			NoesisSlateElement->RenderView(RHICmdList, View);
		}
	}

	virtual int32 GetPriority() const override
	{
		return 0;
	}

protected:

	virtual bool IsActiveThisFrame_Internal(const FSceneViewExtensionContext& Context) const override
	{
		return true;
	}
};

static void StaticPreTick(float)
{
	ENQUEUE_RENDER_COMMAND(StaticPreTick)
	(
		[](FRHICommandListImmediate& RHICmdList)
		{
			auto& SceneTextureExtracts = GetSceneTextureExtracts();
			auto SceneTexturesUniformBuffer = SceneTextureExtracts.GetUniformBufferRef();
			auto MobileSceneTexturesUniformBuffer = SceneTextureExtracts.GetMobileUniformBufferRef();

			FNoesisRenderDevice* RenderDevice = FNoesisRenderDevice::Get();
			RenderDevice->SetSceneTexturesUniformBuffer(SceneTexturesUniformBuffer);
			RenderDevice->SetMobileSceneTexturesUniformBuffer(MobileSceneTexturesUniformBuffer);

			FNoesisRenderDevice* LinearRenderDevice = FNoesisRenderDevice::GetLinear();
			LinearRenderDevice->SetSceneTexturesUniformBuffer(SceneTexturesUniformBuffer);
			LinearRenderDevice->SetMobileSceneTexturesUniformBuffer(MobileSceneTexturesUniformBuffer);
		}
	);
}

TSharedPtr<ISceneViewExtension> NoesisRegisterSceneViewExtension()
{
	if (FSlateApplication::IsInitialized() && FApp::CanEverRender())
	{
		FSlateApplication::Get().OnPreTick().AddStatic(&StaticPreTick);
	}
	return FSceneViewExtensions::NewExtension<FNoesisSceneViewExtension>();
}

void NoesisUnregisterSceneViewExtension(TSharedPtr<class ISceneViewExtension>)
{

}

class FNoesisInputPreprocessor : public IInputProcessor
{
public:
	FNoesisInputPreprocessor()
	{
	}


	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor>) override
	{
	}

	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override
	{
		return false;
	}

	virtual bool HandleAnalogInputEvent(FSlateApplication& SlateApp, const FAnalogInputEvent& InAnalogInputEvent) override
	{
		return false;
	}

	virtual bool HandleMouseMoveEvent(FSlateApplication& SlateApp, const FPointerEvent& InPointerEvent) override
	{
		auto GameViewport = SlateApp.GetGameViewport();
		if (GameViewport.IsValid())
		{
			auto MyGeometry = GameViewport->GetTickSpaceGeometry();

			for (auto ViewInstancePair : ViewInstanceMap)
			{
				UNoesisInstance* NoesisInstance = ViewInstancePair.Value;
				if (NoesisInstance->Is3DWidget)
				{
					NoesisInstance->NativeOnMouseMove(MyGeometry, InPointerEvent);
				}
			}
		}
		return false;
	}

	virtual bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& InPointerEvent) override
	{
		auto GameViewport = SlateApp.GetGameViewport();
		if (GameViewport.IsValid())
		{
			auto MyGeometry = GameViewport->GetTickSpaceGeometry();
			
			for (auto ViewInstancePair : ViewInstanceMap)
			{
				UNoesisInstance* NoesisInstance = ViewInstancePair.Value;
				if (NoesisInstance->Is3DWidget)
				{
					NoesisInstance->NativeOnMouseButtonDown(MyGeometry, InPointerEvent);
				}
			}
		}
		return false;
	}

	virtual bool HandleMouseButtonUpEvent(FSlateApplication& SlateApp, const FPointerEvent& InPointerEvent) override
	{
		auto GameViewport = SlateApp.GetGameViewport();
		if (GameViewport.IsValid())
		{
			auto MyGeometry = GameViewport->GetTickSpaceGeometry();
			
			
			for (auto ViewInstancePair : ViewInstanceMap)
			{
				UNoesisInstance* NoesisInstance = ViewInstancePair.Value;
				if (NoesisInstance->Is3DWidget)
				{
					NoesisInstance->NativeOnMouseButtonUp(MyGeometry, InPointerEvent);
				}
			}
		}
		return false;
	}

	virtual bool HandleMouseButtonDoubleClickEvent(FSlateApplication& SlateApp, const FPointerEvent& InPointerEvent) override
	{
		return false;
	}

	virtual const TCHAR* GetDebugName() const override { return TEXT("NoesisInput"); }
};

TSharedPtr<class IInputProcessor> NoesisRegisterInputPreProcessor()
{
	if (FSlateApplication::IsInitialized())
	{
		auto InputPreProcessor = MakeShared<FNoesisInputPreprocessor>();
		FSlateApplication::Get().RegisterInputPreProcessor(InputPreProcessor, 0);
		return InputPreProcessor;
	}

	return nullptr;
}

void NoesisUnregisterInputPreProcessor(TSharedPtr<class IInputProcessor> InputPreProcessor)
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(InputPreProcessor);
	}
}
