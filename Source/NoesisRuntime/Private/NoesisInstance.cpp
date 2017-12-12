////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisInstance.h"

// NoesisRuntime includes
#include "NoesisBlueprintGeneratedClass.h"
#include "NoesisWidget.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisTypeClass.h"

UNoesisInstance::UNoesisInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
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
	if (XamlView)
	{
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
	if (XamlView)
	{
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(&RHICmdList);
		Noesis::IRenderer* Renderer = XamlView->GetRenderer();
		RHICmdList.SetViewport(Left, Top, 0.0f, Left + Width, Top + Height, 1.0f);
		Renderer->Render();
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(nullptr);
	}
}

void UNoesisInstance::MouseButtonDown(FVector2D Position, FKey Button)
{
	if (XamlView)
	{
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
	}
}

void UNoesisInstance::MouseButtonUp(FVector2D Position, FKey Button)
{
	if (XamlView)
	{
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
	}
}

void UNoesisInstance::MouseDoubleClick(FVector2D Position, FKey Button)
{
	if (XamlView)
	{
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
	}
}

void UNoesisInstance::MouseMove(FVector2D Position)
{
	if (XamlView)
	{
		XamlView->MouseMove(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y));
	}
}

void UNoesisInstance::MouseWheel(FVector2D Position, float WheelDelta)
{
	if (XamlView)
	{
		XamlView->MouseWheel(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), FPlatformMath::RoundToInt(WheelDelta * 120.f));
	}
}

void UNoesisInstance::KeyDown(uint32 Key)
{
	if (XamlView)
	{
		XamlView->KeyDown((Noesis::Key)Key);
	}
}

void UNoesisInstance::KeyUp(uint32 Key)
{
	if (XamlView)
	{
		XamlView->KeyUp((Noesis::Key)Key);
	}
}

void UNoesisInstance::Char(TCHAR Character)
{
	if (XamlView)
	{
		XamlView->Char(CharCast<char>(Character));
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

void UNoesisInstance::OnPreviewGotKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args)
{
	const Noesis::TypeClass* NewFocusClass = Args.newFocus->GetClassType();
	const Noesis::TypeClass* TextBoxClass = Noesis::TextBox::StaticGetClassType();
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

			TextInputMethodSystem->ActivateContext(TextInputMethodContext.ToSharedRef());
		}
	}
}

void UNoesisInstance::OnPreviewLostKeyboardFocus(Noesis::BaseComponent* Component, const Noesis::KeyboardFocusChangedEventArgs& Args)
{
	const Noesis::TypeClass* OldFocusClass = Args.oldFocus->GetClassType();
	const Noesis::TypeClass* TextBoxClass = Noesis::TextBox::StaticGetClassType();
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

	if (XamlView)
	{
		Noesis::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->Shutdown();
		XamlView.Reset();
		Xaml.Reset();
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

void UNoesisInstance::InitializeNativeClassData()
{
	Super::InitializeNativeClassData();

	InitInstance();
}

TSharedRef<SWidget> UNoesisInstance::RebuildWidget()
{
	return SNew(SNoesisWidget).NoesisInstance(this);
}
