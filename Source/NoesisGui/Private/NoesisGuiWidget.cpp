////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiWidget.h"

// RenderCore includes
#include "RenderingThread.h"

// NoesisGui includes
#include "NoesisGuiInstance.h"

FNoesisGuiSlateOffscreenElement::FNoesisGuiSlateOffscreenElement(class UNoesisGuiInstance* InNoesisGuiInstance)
	: NoesisGuiInstance(InNoesisGuiInstance)
{
}

void FNoesisGuiSlateOffscreenElement::DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer)
{
	if (NoesisGuiInstance)
	{
		FTexture2DRHIRef& BackBuffer = *(FTexture2DRHIRef*)InWindowBackBuffer;
		NoesisGuiInstance->DrawOffscreen_RenderThread(RHICmdList, 0, 0);
		SetRenderTarget(RHICmdList, BackBuffer, 0);
	}
}

FNoesisGuiSlateElement::FNoesisGuiSlateElement(class UNoesisGuiInstance* InNoesisGuiInstance)
	: NoesisGuiInstance(InNoesisGuiInstance)
{
}

void FNoesisGuiSlateElement::DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer)
{
	if (NoesisGuiInstance)
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

		NoesisGuiInstance->Draw_RenderThread(RHICmdList, BackBuffer, DepthStencilTarget);

		SetRenderTarget(RHICmdList, BackBuffer, 0);
	}
}

void SNoesisGuiWidget::Construct(const FArguments& InArgs)
{
	NoesisGuiSlateOffscreenElement = FNoesisGuiSlateOffscreenElementPtr(new FNoesisGuiSlateOffscreenElement(InArgs._NoesisGuiInstance));
	NoesisGuiSlateElement = FNoesisGuiSlateElementPtr(new FNoesisGuiSlateElement(InArgs._NoesisGuiInstance));
	NoesisGuiInstance = InArgs._NoesisGuiInstance;
}

int32 SNoesisGuiWidget::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	NoesisGuiSlateElement->NoesisGuiInstance->Update(MyClippingRect.Left, MyClippingRect.Top, MyClippingRect.Right - MyClippingRect.Left, MyClippingRect.Bottom - MyClippingRect.Top);

	FSlateDrawElement::MakeCustom(OutDrawElements, 0, NoesisGuiSlateOffscreenElement);
	FSlateDrawElement::MakeCustom(OutDrawElements, LayerId, NoesisGuiSlateElement);

	return LayerId;
}

FVector2D SNoesisGuiWidget::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	return NoesisGuiInstance->GetSize();
}

FReply SNoesisGuiWidget::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& CharacterEvent)
{
	NoesisGuiInstance->Char(CharacterEvent.GetCharacter());

	return FReply::Handled();
}

FReply SNoesisGuiWidget::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	NoesisGuiInstance->KeyDown(KeyEvent.GetKeyCode());

	return FReply::Handled();
}

FReply SNoesisGuiWidget::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	NoesisGuiInstance->KeyUp(KeyEvent.GetKeyCode());

	return FReply::Handled();
}

FReply SNoesisGuiWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisGuiInstance->MouseButtonDown(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale, MouseEvent.GetEffectingButton());

	return FReply::Handled();
}

FReply SNoesisGuiWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisGuiInstance->MouseButtonUp(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale, MouseEvent.GetEffectingButton());

	return FReply::Handled();
}

FReply SNoesisGuiWidget::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisGuiInstance->MouseMove(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale);

	return FReply::Handled();
}

FReply SNoesisGuiWidget::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisGuiInstance->MouseWheel(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale, MouseEvent.GetWheelDelta());

	return FReply::Handled();
}

FCursorReply SNoesisGuiWidget::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	//return FCursorReply::Unhandled();
	return FCursorReply::Cursor(EMouseCursor::Default);
}

FReply SNoesisGuiWidget::OnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	NoesisGuiInstance->MouseDoubleClick(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) * MyGeometry.Scale, MouseEvent.GetEffectingButton());

	return FReply::Handled();
}
