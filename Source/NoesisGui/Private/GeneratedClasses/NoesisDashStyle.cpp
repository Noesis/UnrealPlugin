////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDashStyle.h"

using namespace Noesis;
using namespace Gui;

UNoesisDashStyle::UNoesisDashStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDashStyle::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(InNoesisComponent);
	check(NoesisDashStyle);
}

FString UNoesisDashStyle::GetDashes()
{
	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(NoesisComponent.GetPtr());
	check(NoesisDashStyle);
	return NsStringToFString(NoesisDashStyle->GetDashes());
}

void UNoesisDashStyle::SetDashes(FString InDashes)
{
	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(NoesisComponent.GetPtr());
	check(NoesisDashStyle);
	NoesisDashStyle->SetDashes(StringCast<NsChar>(*InDashes).Get());
}

float UNoesisDashStyle::GetOffset()
{
	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(NoesisComponent.GetPtr());
	check(NoesisDashStyle);
	return (float)NoesisDashStyle->GetOffset();
}

void UNoesisDashStyle::SetOffset(float InOffset)
{
	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(NoesisComponent.GetPtr());
	check(NoesisDashStyle);
	NoesisDashStyle->SetOffset(InOffset);
}

void UNoesisDashStyle::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(NoesisComponent.GetPtr());
	check(NoesisDashStyle)


}

void UNoesisDashStyle::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DashStyle* NoesisDashStyle = NsDynamicCast<Noesis::Gui::DashStyle*>(NoesisComponent.GetPtr());
	check(NoesisDashStyle)


}

