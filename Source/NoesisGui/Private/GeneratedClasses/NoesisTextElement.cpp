////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisTextElement.h"

using namespace Noesis;
using namespace Gui;

UNoesisTextElement::UNoesisTextElement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TextElement::StaticGetClassType();
}

void UNoesisTextElement::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(InNoesisComponent);
	check(NoesisTextElement);
}

class UNoesisBrush* UNoesisTextElement::GetBackground()
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisTextElement->GetBackground(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTextElement::SetBackground(class UNoesisBrush* InBackground)
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	NoesisTextElement->SetBackground(NsDynamicCast<Brush*>(InBackground->NoesisComponent.GetPtr()));
}

class UNoesisFontFamily* UNoesisTextElement::GetFontFamily()
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	return CastChecked<UNoesisFontFamily>(CreateClassFor(NoesisTextElement->GetFontFamily(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTextElement::SetFontFamily(class UNoesisFontFamily* InFontFamily)
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	NoesisTextElement->SetFontFamily(NsDynamicCast<FontFamily*>(InFontFamily->NoesisComponent.GetPtr()));
}

float UNoesisTextElement::GetFontSize()
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	return (float)NoesisTextElement->GetFontSize();
}

void UNoesisTextElement::SetFontSize(float InFontSize)
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	NoesisTextElement->SetFontSize(InFontSize);
}

ENoesisFontStretch UNoesisTextElement::GetFontStretch()
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	return (ENoesisFontStretch)NoesisTextElement->GetFontStretch();
}

void UNoesisTextElement::SetFontStretch(ENoesisFontStretch InFontStretch)
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	NoesisTextElement->SetFontStretch((Noesis::Gui::FontStretch)InFontStretch);
}

ENoesisFontStyle UNoesisTextElement::GetFontStyle()
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	return (ENoesisFontStyle)NoesisTextElement->GetFontStyle();
}

void UNoesisTextElement::SetFontStyle(ENoesisFontStyle InFontStyle)
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	NoesisTextElement->SetFontStyle((Noesis::Gui::FontStyle)InFontStyle);
}

ENoesisFontWeight UNoesisTextElement::GetFontWeight()
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	return (ENoesisFontWeight)(NoesisTextElement->GetFontWeight() / 10);
}

void UNoesisTextElement::SetFontWeight(ENoesisFontWeight InFontWeight)
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	NoesisTextElement->SetFontWeight((Noesis::Gui::FontWeight)(((int32)InFontWeight) * 10));
}

class UNoesisBrush* UNoesisTextElement::GetForeground()
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisTextElement->GetForeground(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTextElement::SetForeground(class UNoesisBrush* InForeground)
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	NoesisTextElement->SetForeground(NsDynamicCast<Brush*>(InForeground->NoesisComponent.GetPtr()));
}

class UNoesisBrush* UNoesisTextElement::GetStroke()
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisTextElement->GetStroke(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTextElement::SetStroke(class UNoesisBrush* InStroke)
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	NoesisTextElement->SetStroke(NsDynamicCast<Brush*>(InStroke->NoesisComponent.GetPtr()));
}

float UNoesisTextElement::GetStrokeThickness()
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	return (float)NoesisTextElement->GetStrokeThickness();
}

void UNoesisTextElement::SetStrokeThickness(float InStrokeThickness)
{
	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);
	NoesisTextElement->SetStrokeThickness(InStrokeThickness);
}

void UNoesisTextElement::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);


}

void UNoesisTextElement::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TextElement* NoesisTextElement = NsDynamicCast<Noesis::Gui::TextElement*>(NoesisComponent.GetPtr());
	check(NoesisTextElement);


}

