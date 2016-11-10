////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGeometryGroup.h"

using namespace Noesis;
using namespace Gui;

UNoesisGeometryGroup::UNoesisGeometryGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGeometryGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GeometryGroup* NoesisGeometryGroup = NsDynamicCast<Noesis::Gui::GeometryGroup*>(InNoesisComponent);
	check(NoesisGeometryGroup);
}

class UNoesisGeometryCollection* UNoesisGeometryGroup::GetChildren()
{
	Noesis::Gui::GeometryGroup* NoesisGeometryGroup = NsDynamicCast<Noesis::Gui::GeometryGroup*>(NoesisComponent.GetPtr());
	check(NoesisGeometryGroup);
	return CastChecked<UNoesisGeometryCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisGeometryGroup->GetChildren()));
}

void UNoesisGeometryGroup::SetChildren(class UNoesisGeometryCollection* InChildren)
{
	Noesis::Gui::GeometryGroup* NoesisGeometryGroup = NsDynamicCast<Noesis::Gui::GeometryGroup*>(NoesisComponent.GetPtr());
	check(NoesisGeometryGroup);
	NoesisGeometryGroup->SetChildren(NsDynamicCast<GeometryCollection*>(InChildren->NoesisComponent.GetPtr()));
}

ENoesisFillRule UNoesisGeometryGroup::GetFillRule()
{
	Noesis::Gui::GeometryGroup* NoesisGeometryGroup = NsDynamicCast<Noesis::Gui::GeometryGroup*>(NoesisComponent.GetPtr());
	check(NoesisGeometryGroup);
	return (ENoesisFillRule)NoesisGeometryGroup->GetFillRule();
}

void UNoesisGeometryGroup::SetFillRule(ENoesisFillRule InFillRule)
{
	Noesis::Gui::GeometryGroup* NoesisGeometryGroup = NsDynamicCast<Noesis::Gui::GeometryGroup*>(NoesisComponent.GetPtr());
	check(NoesisGeometryGroup);
	NoesisGeometryGroup->SetFillRule((Noesis::Gui::FillRule)InFillRule);
}

void UNoesisGeometryGroup::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GeometryGroup* NoesisGeometryGroup = NsDynamicCast<Noesis::Gui::GeometryGroup*>(NoesisComponent.GetPtr());
	check(NoesisGeometryGroup)


}

void UNoesisGeometryGroup::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GeometryGroup* NoesisGeometryGroup = NsDynamicCast<Noesis::Gui::GeometryGroup*>(NoesisComponent.GetPtr());
	check(NoesisGeometryGroup)


}

