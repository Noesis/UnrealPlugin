////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisWidget.h"

// NoesisRuntime includes
#include "NoesisInstance.h"

FNoesisSlateOffscreenElement::FNoesisSlateOffscreenElement(class UNoesisInstance* InNoesisInstance)
	: NoesisInstance(InNoesisInstance)
{
}

void FNoesisSlateOffscreenElement::DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer)
{
	if (NoesisInstance)
	{
		FTexture2DRHIRef& BackBuffer = *(FTexture2DRHIRef*)InWindowBackBuffer;
		NoesisInstance->DrawOffscreen_RenderThread(RHICmdList, 0, 0);
		SetRenderTarget(RHICmdList, BackBuffer, 0);
	}
}

FNoesisSlateElement::FNoesisSlateElement(class UNoesisInstance* InNoesisInstance)
	: NoesisInstance(InNoesisInstance)
{
}

void FNoesisSlateElement::DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer)
{
	if (NoesisInstance)
	{
		FTexture2DRHIRef& BackBuffer = *(FTexture2DRHIRef*)InWindowBackBuffer;

		uint32 SizeX = BackBuffer->GetSizeX();
		uint32 SizeY = BackBuffer->GetSizeY();
		uint8 Format = (uint8)PF_DepthStencil;
		uint32 NumMips = BackBuffer->GetNumMips();
		uint32 NumSamples = BackBuffer->GetNumSamples();
		uint32 TargetableTextureFlags = (uint32)TexCreate_DepthStencilTargetable;
		FRHIResourceCreateInfo CreateInfo;
		CreateInfo.ClearValueBinding = FClearValueBinding(0.f, 0);
		FTexture2DRHIRef DepthStencilTarget = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, TargetableTextureFlags, CreateInfo);

		SetRenderTarget(RHICmdList, BackBuffer, DepthStencilTarget);

		NoesisInstance->Draw_RenderThread(RHICmdList, BackBuffer, DepthStencilTarget);

		SetRenderTarget(RHICmdList, BackBuffer, 0);
	}
}

void SNoesisWidget::Construct(const FArguments& InArgs)
{
	NoesisSlateOffscreenElement = FNoesisSlateOffscreenElementPtr(new FNoesisSlateOffscreenElement(InArgs._NoesisInstance));
	NoesisSlateElement = FNoesisSlateElementPtr(new FNoesisSlateElement(InArgs._NoesisInstance));
	NoesisInstance = InArgs._NoesisInstance;
}

int32 SNoesisWidget::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	NoesisSlateElement->NoesisInstance->Update(MyClippingRect.Left, MyClippingRect.Top, MyClippingRect.Right - MyClippingRect.Left, MyClippingRect.Bottom - MyClippingRect.Top);

	FSlateDrawElement::MakeCustom(OutDrawElements, 0, NoesisSlateOffscreenElement);
	FSlateDrawElement::MakeCustom(OutDrawElements, LayerId, NoesisSlateElement);

	return LayerId;
}

FVector2D SNoesisWidget::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	return NoesisInstance->GetSize();
}

FReply SNoesisWidget::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& CharacterEvent)
{
	NoesisInstance->Char(CharacterEvent.GetCharacter());

	return SLeafWidget::OnKeyChar(MyGeometry, CharacterEvent);
}

uint32 KeyToNoesisKey(FKey Key)
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

	return (uint32)NoesisKey;
}

FReply SNoesisWidget::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	FKey Key = KeyEvent.GetKey();

	NoesisInstance->KeyDown(KeyToNoesisKey(Key));

	return SLeafWidget::OnKeyDown(MyGeometry, KeyEvent);
}

FReply SNoesisWidget::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	FKey Key = KeyEvent.GetKey();

	NoesisInstance->KeyUp(KeyToNoesisKey(Key));

	return SLeafWidget::OnKeyUp(MyGeometry, KeyEvent);
}

FReply SNoesisWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisInstance->MouseButtonDown(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale, MouseEvent.GetEffectingButton());

	return FReply::Handled();
}

FReply SNoesisWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisInstance->MouseButtonUp(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale, MouseEvent.GetEffectingButton());

	return FReply::Handled();
}

FReply SNoesisWidget::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisInstance->MouseMove(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale);

	return FReply::Handled();
}

FReply SNoesisWidget::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisInstance->MouseWheel(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale, MouseEvent.GetWheelDelta());

	return FReply::Handled();
}

FReply SNoesisWidget::OnTouchStarted(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	NoesisInstance->TouchDown(MyGeometry.AbsoluteToLocal(TouchEvent.GetScreenSpacePosition()) * MyGeometry.Scale, TouchEvent.GetPointerIndex());

	return FReply::Handled();
}
	
FReply SNoesisWidget::OnTouchMoved(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	NoesisInstance->TouchMove(MyGeometry.AbsoluteToLocal(TouchEvent.GetScreenSpacePosition()) * MyGeometry.Scale, TouchEvent.GetPointerIndex());

	return FReply::Handled();
}

FReply SNoesisWidget::OnTouchEnded(const FGeometry& MyGeometry, const FPointerEvent& TouchEvent)
{
	NoesisInstance->TouchUp(MyGeometry.AbsoluteToLocal(TouchEvent.GetScreenSpacePosition()) * MyGeometry.Scale, TouchEvent.GetPointerIndex());

	return FReply::Handled();
}

FCursorReply SNoesisWidget::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	return FCursorReply::Cursor(EMouseCursor::Default);
}

FReply SNoesisWidget::OnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisInstance->MouseDoubleClick(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale, MouseEvent.GetEffectingButton());

	return FReply::Handled();
}

bool SNoesisWidget::SupportsKeyboardFocus() const
{
	return true;
}
