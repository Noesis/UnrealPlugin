////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisVisualBrush.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisVisualBrush::UNoesisVisualBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::VisualBrush::StaticGetClassType();
}

void UNoesisVisualBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualBrush* NoesisVisualBrush = NsDynamicCast<Noesis::Gui::VisualBrush*>(InNoesisComponent);
	check(NoesisVisualBrush);
}

class UNoesisVisual* UNoesisVisualBrush::GetVisual()
{
	Noesis::Gui::VisualBrush* NoesisVisualBrush = NsDynamicCast<Noesis::Gui::VisualBrush*>(NoesisComponent.GetPtr());
	check(NoesisVisualBrush);
	return CastChecked<UNoesisVisual>(CreateClassFor(NoesisVisualBrush->GetVisual(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisVisualBrush::SetVisual(class UNoesisVisual* InVisual)
{
	Noesis::Gui::VisualBrush* NoesisVisualBrush = NsDynamicCast<Noesis::Gui::VisualBrush*>(NoesisComponent.GetPtr());
	check(NoesisVisualBrush);
	NoesisVisualBrush->SetVisual(NsDynamicCast<Visual*>(InVisual->NoesisComponent.GetPtr()));
}

void UNoesisVisualBrush::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VisualBrush* NoesisVisualBrush = NsDynamicCast<Noesis::Gui::VisualBrush*>(NoesisComponent.GetPtr());
	check(NoesisVisualBrush);


}

void UNoesisVisualBrush::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VisualBrush* NoesisVisualBrush = NsDynamicCast<Noesis::Gui::VisualBrush*>(NoesisComponent.GetPtr());
	check(NoesisVisualBrush);


}

