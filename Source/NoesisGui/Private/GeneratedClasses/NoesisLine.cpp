////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisLine.h"

using namespace Noesis;
using namespace Gui;

UNoesisLine::UNoesisLine(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Line::StaticGetClassType();
}

void UNoesisLine::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(InNoesisComponent);
	check(NoesisLine);
}

float UNoesisLine::GetX1()
{
	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);
	return (float)NoesisLine->GetX1();
}

void UNoesisLine::SetX1(float InX1)
{
	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);
	NoesisLine->SetX1(InX1);
}

float UNoesisLine::GetX2()
{
	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);
	return (float)NoesisLine->GetX2();
}

void UNoesisLine::SetX2(float InX2)
{
	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);
	NoesisLine->SetX2(InX2);
}

float UNoesisLine::GetY1()
{
	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);
	return (float)NoesisLine->GetY1();
}

void UNoesisLine::SetY1(float InY1)
{
	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);
	NoesisLine->SetY1(InY1);
}

float UNoesisLine::GetY2()
{
	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);
	return (float)NoesisLine->GetY2();
}

void UNoesisLine::SetY2(float InY2)
{
	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);
	NoesisLine->SetY2(InY2);
}

void UNoesisLine::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);


}

void UNoesisLine::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine);


}

