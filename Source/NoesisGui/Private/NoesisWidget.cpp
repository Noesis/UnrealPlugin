////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisWidget.h"

// RenderCore includes
#include "RenderingThread.h"

// SlateCore includes
#include "Rendering/DrawElements.h"

// NoesisGui includes
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

	return FReply::Handled();
}

FReply SNoesisWidget::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	NoesisInstance->KeyDown(KeyEvent.GetKeyCode());

	return FReply::Handled();
}

FReply SNoesisWidget::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	NoesisInstance->KeyUp(KeyEvent.GetKeyCode());

	return FReply::Handled();
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

FCursorReply SNoesisWidget::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	//return FCursorReply::Unhandled();
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
