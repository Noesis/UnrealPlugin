////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisSolidColorBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisSolidColorBrush::UNoesisSolidColorBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisSolidColorBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SolidColorBrush* NoesisSolidColorBrush = NsDynamicCast<Noesis::Gui::SolidColorBrush*>(InNoesisComponent);
	check(NoesisSolidColorBrush);
}

FNoesisDrawingColor UNoesisSolidColorBrush::GetColor()
{
	Noesis::Gui::SolidColorBrush* NoesisSolidColorBrush = NsDynamicCast<Noesis::Gui::SolidColorBrush*>(NoesisComponent.GetPtr());
	check(NoesisSolidColorBrush);
	return FNoesisDrawingColor(NoesisSolidColorBrush->GetColor());
}

void UNoesisSolidColorBrush::SetColor(FNoesisDrawingColor InColor)
{
	Noesis::Gui::SolidColorBrush* NoesisSolidColorBrush = NsDynamicCast<Noesis::Gui::SolidColorBrush*>(NoesisComponent.GetPtr());
	check(NoesisSolidColorBrush);
	NoesisSolidColorBrush->SetColor(InColor.ToNoesis());
}

void UNoesisSolidColorBrush::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SolidColorBrush* NoesisSolidColorBrush = NsDynamicCast<Noesis::Gui::SolidColorBrush*>(NoesisComponent.GetPtr());
	check(NoesisSolidColorBrush)


}

void UNoesisSolidColorBrush::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SolidColorBrush* NoesisSolidColorBrush = NsDynamicCast<Noesis::Gui::SolidColorBrush*>(NoesisComponent.GetPtr());
	check(NoesisSolidColorBrush)


}

