////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisWrapPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisWrapPanel::UNoesisWrapPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisWrapPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(InNoesisComponent);
	check(NoesisWrapPanel);
}

float UNoesisWrapPanel::GetItemHeight()
{
	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel);
	return (float)NoesisWrapPanel->GetItemHeight();
}

void UNoesisWrapPanel::SetItemHeight(float InItemHeight)
{
	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel);
	NoesisWrapPanel->SetItemHeight(InItemHeight);
}

float UNoesisWrapPanel::GetItemWidth()
{
	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel);
	return (float)NoesisWrapPanel->GetItemWidth();
}

void UNoesisWrapPanel::SetItemWidth(float InItemWidth)
{
	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel);
	NoesisWrapPanel->SetItemWidth(InItemWidth);
}

ENoesisOrientation UNoesisWrapPanel::GetOrientation()
{
	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel);
	return (ENoesisOrientation)NoesisWrapPanel->GetOrientation();
}

void UNoesisWrapPanel::SetOrientation(ENoesisOrientation InOrientation)
{
	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel);
	NoesisWrapPanel->SetOrientation((Noesis::Gui::Orientation)InOrientation);
}

void UNoesisWrapPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel)


}

void UNoesisWrapPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel)


}

