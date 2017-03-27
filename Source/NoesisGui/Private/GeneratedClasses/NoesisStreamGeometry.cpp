////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisStreamGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisStreamGeometry::UNoesisStreamGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::StreamGeometry::StaticGetClassType();
}

void UNoesisStreamGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StreamGeometry* NoesisStreamGeometry = NsDynamicCast<Noesis::Gui::StreamGeometry*>(InNoesisComponent);
	check(NoesisStreamGeometry);
}

ENoesisFillRule UNoesisStreamGeometry::GetFillRule()
{
	Noesis::Gui::StreamGeometry* NoesisStreamGeometry = NsDynamicCast<Noesis::Gui::StreamGeometry*>(NoesisComponent.GetPtr());
	check(NoesisStreamGeometry);
	return (ENoesisFillRule)NoesisStreamGeometry->GetFillRule();
}

void UNoesisStreamGeometry::SetFillRule(ENoesisFillRule InFillRule)
{
	Noesis::Gui::StreamGeometry* NoesisStreamGeometry = NsDynamicCast<Noesis::Gui::StreamGeometry*>(NoesisComponent.GetPtr());
	check(NoesisStreamGeometry);
	NoesisStreamGeometry->SetFillRule((Noesis::Gui::FillRule)InFillRule);
}

void UNoesisStreamGeometry::SetData(FString InData)
{
	Noesis::Gui::StreamGeometry* NoesisStreamGeometry = NsDynamicCast<Noesis::Gui::StreamGeometry*>(NoesisComponent.GetPtr());
	check(NoesisStreamGeometry);
	const NsChar* NoesisInData = StringCast<NsChar>(*InData).Get();
	return NoesisStreamGeometry->SetData(NoesisInData);
}

void UNoesisStreamGeometry::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::StreamGeometry* NoesisStreamGeometry = NsDynamicCast<Noesis::Gui::StreamGeometry*>(NoesisComponent.GetPtr());
	check(NoesisStreamGeometry);


}

void UNoesisStreamGeometry::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::StreamGeometry* NoesisStreamGeometry = NsDynamicCast<Noesis::Gui::StreamGeometry*>(NoesisComponent.GetPtr());
	check(NoesisStreamGeometry);


}

