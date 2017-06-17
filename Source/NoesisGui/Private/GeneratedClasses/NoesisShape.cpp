////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisShape.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisShape::UNoesisShape(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Shape::StaticGetClassType();
}

void UNoesisShape::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(InNoesisComponent);
	check(NoesisShape);
}

class UNoesisBrush* UNoesisShape::GetFill()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisShape->GetFill(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisShape::SetFill(class UNoesisBrush* InFill)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetFill(NsDynamicCast<Brush*>(InFill->NoesisComponent.GetPtr()));
}

ENoesisStretch UNoesisShape::GetStretch()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return (ENoesisStretch)NoesisShape->GetStretch();
}

void UNoesisShape::SetStretch(ENoesisStretch InStretch)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStretch((Noesis::Gui::Stretch)InStretch);
}

class UNoesisBrush* UNoesisShape::GetStroke()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisShape->GetStroke(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisShape::SetStroke(class UNoesisBrush* InStroke)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStroke(NsDynamicCast<Brush*>(InStroke->NoesisComponent.GetPtr()));
}

FString UNoesisShape::GetStrokeDashArray()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return NsStringToFString(NoesisShape->GetStrokeDashArray());
}

void UNoesisShape::SetStrokeDashArray(FString InStrokeDashArray)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStrokeDashArray(StringCast<NsChar>(*InStrokeDashArray).Get());
}

ENoesisPenLineCap UNoesisShape::GetStrokeDashCap()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return (ENoesisPenLineCap)NoesisShape->GetStrokeDashCap();
}

void UNoesisShape::SetStrokeDashCap(ENoesisPenLineCap InStrokeDashCap)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStrokeDashCap((Noesis::Gui::PenLineCap)InStrokeDashCap);
}

float UNoesisShape::GetStrokeDashOffset()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return (float)NoesisShape->GetStrokeDashOffset();
}

void UNoesisShape::SetStrokeDashOffset(float InStrokeDashOffset)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStrokeDashOffset(InStrokeDashOffset);
}

ENoesisPenLineCap UNoesisShape::GetStrokeEndLineCap()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return (ENoesisPenLineCap)NoesisShape->GetStrokeEndLineCap();
}

void UNoesisShape::SetStrokeEndLineCap(ENoesisPenLineCap InStrokeEndLineCap)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStrokeEndLineCap((Noesis::Gui::PenLineCap)InStrokeEndLineCap);
}

ENoesisPenLineJoin UNoesisShape::GetStrokeLineJoin()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return (ENoesisPenLineJoin)NoesisShape->GetStrokeLineJoin();
}

void UNoesisShape::SetStrokeLineJoin(ENoesisPenLineJoin InStrokeLineJoin)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStrokeLineJoin((Noesis::Gui::PenLineJoin)InStrokeLineJoin);
}

float UNoesisShape::GetStrokeMiterLimit()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return (float)NoesisShape->GetStrokeMiterLimit();
}

void UNoesisShape::SetStrokeMiterLimit(float InStrokeMiterLimit)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStrokeMiterLimit(InStrokeMiterLimit);
}

ENoesisPenLineCap UNoesisShape::GetStrokeStartLineCap()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return (ENoesisPenLineCap)NoesisShape->GetStrokeStartLineCap();
}

void UNoesisShape::SetStrokeStartLineCap(ENoesisPenLineCap InStrokeStartLineCap)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStrokeStartLineCap((Noesis::Gui::PenLineCap)InStrokeStartLineCap);
}

float UNoesisShape::GetStrokeThickness()
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	return (float)NoesisShape->GetStrokeThickness();
}

void UNoesisShape::SetStrokeThickness(float InStrokeThickness)
{
	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);
	NoesisShape->SetStrokeThickness(InStrokeThickness);
}

void UNoesisShape::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);


}

void UNoesisShape::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Shape* NoesisShape = NsDynamicCast<Noesis::Gui::Shape*>(NoesisComponent.GetPtr());
	check(NoesisShape);


}

