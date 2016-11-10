////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTextBlock.h"

using namespace Noesis;
using namespace Gui;

UNoesisTextBlock::UNoesisTextBlock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTextBlock::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(InNoesisComponent);
	check(NoesisTextBlock);
}

class UNoesisBrush* UNoesisTextBlock::GetBackground()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisTextBlock->GetBackground()));
}

void UNoesisTextBlock::SetBackground(class UNoesisBrush* InBackground)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetBackground(NsDynamicCast<Brush*>(InBackground->NoesisComponent.GetPtr()));
}

class UNoesisFontFamily* UNoesisTextBlock::GetFontFamily()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return CastChecked<UNoesisFontFamily>(Instance->FindUnrealComponentForNoesisComponent(NoesisTextBlock->GetFontFamily()));
}

void UNoesisTextBlock::SetFontFamily(class UNoesisFontFamily* InFontFamily)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetFontFamily(NsDynamicCast<FontFamily*>(InFontFamily->NoesisComponent.GetPtr()));
}

float UNoesisTextBlock::GetFontSize()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return (float)NoesisTextBlock->GetFontSize();
}

void UNoesisTextBlock::SetFontSize(float InFontSize)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetFontSize(InFontSize);
}

ENoesisFontStretch UNoesisTextBlock::GetFontStretch()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return (ENoesisFontStretch)NoesisTextBlock->GetFontStretch();
}

void UNoesisTextBlock::SetFontStretch(ENoesisFontStretch InFontStretch)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetFontStretch((Noesis::Gui::FontStretch)InFontStretch);
}

ENoesisFontStyle UNoesisTextBlock::GetFontStyle()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return (ENoesisFontStyle)NoesisTextBlock->GetFontStyle();
}

void UNoesisTextBlock::SetFontStyle(ENoesisFontStyle InFontStyle)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetFontStyle((Noesis::Gui::FontStyle)InFontStyle);
}

ENoesisFontWeight UNoesisTextBlock::GetFontWeight()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return (ENoesisFontWeight)(NoesisTextBlock->GetFontWeight() / 10);
}

void UNoesisTextBlock::SetFontWeight(ENoesisFontWeight InFontWeight)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetFontWeight((Noesis::Gui::FontWeight)(((int32)InFontWeight) * 10));
}

class UNoesisBrush* UNoesisTextBlock::GetForeground()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisTextBlock->GetForeground()));
}

void UNoesisTextBlock::SetForeground(class UNoesisBrush* InForeground)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetForeground(NsDynamicCast<Brush*>(InForeground->NoesisComponent.GetPtr()));
}

class UNoesisInlineCollection* UNoesisTextBlock::GetInlines()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return CastChecked<UNoesisInlineCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisTextBlock->GetInlines()));
}

float UNoesisTextBlock::GetLineHeight()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return (float)NoesisTextBlock->GetLineHeight();
}

void UNoesisTextBlock::SetLineHeight(float InLineHeight)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetLineHeight(InLineHeight);
}

FNoesisDrawingThickness UNoesisTextBlock::GetPadding()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return FNoesisDrawingThickness(NoesisTextBlock->GetPadding());
}

void UNoesisTextBlock::SetPadding(FNoesisDrawingThickness InPadding)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetPadding(InPadding.ToNoesis());
}

class UNoesisBrush* UNoesisTextBlock::GetStroke()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisTextBlock->GetStroke()));
}

void UNoesisTextBlock::SetStroke(class UNoesisBrush* InStroke)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetStroke(NsDynamicCast<Brush*>(InStroke->NoesisComponent.GetPtr()));
}

float UNoesisTextBlock::GetStrokeThickness()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return (float)NoesisTextBlock->GetStrokeThickness();
}

void UNoesisTextBlock::SetStrokeThickness(float InStrokeThickness)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetStrokeThickness(InStrokeThickness);
}

FString UNoesisTextBlock::GetText()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return NsStringToFString(NoesisTextBlock->GetText());
}

void UNoesisTextBlock::SetText(FString InText)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetText(StringCast<NsChar>(*InText).Get());
}

ENoesisTextAlignment UNoesisTextBlock::GetTextAlignment()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return (ENoesisTextAlignment)NoesisTextBlock->GetTextAlignment();
}

void UNoesisTextBlock::SetTextAlignment(ENoesisTextAlignment InTextAlignment)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetTextAlignment((Noesis::Gui::TextAlignment)InTextAlignment);
}

ENoesisTextTrimming UNoesisTextBlock::GetTextTrimming()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return (ENoesisTextTrimming)NoesisTextBlock->GetTextTrimming();
}

void UNoesisTextBlock::SetTextTrimming(ENoesisTextTrimming InTextTrimming)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetTextTrimming((Noesis::Gui::TextTrimming)InTextTrimming);
}

ENoesisTextWrapping UNoesisTextBlock::GetTextWrapping()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return (ENoesisTextWrapping)NoesisTextBlock->GetTextWrapping();
}

void UNoesisTextBlock::SetTextWrapping(ENoesisTextWrapping InTextWrapping)
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	NoesisTextBlock->SetTextWrapping((Noesis::Gui::TextWrapping)InTextWrapping);
}

void UNoesisTextBlock::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock)


}

void UNoesisTextBlock::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock)


}

