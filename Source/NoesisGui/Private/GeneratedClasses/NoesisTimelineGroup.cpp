////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisTimelineGroup.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisTimelineGroup::UNoesisTimelineGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TimelineGroup::StaticGetClassType();
}

void UNoesisTimelineGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TimelineGroup* NoesisTimelineGroup = NsDynamicCast<Noesis::Gui::TimelineGroup*>(InNoesisComponent);
	check(NoesisTimelineGroup);
}

class UNoesisTimelineCollection* UNoesisTimelineGroup::GetChildren()
{
	Noesis::Gui::TimelineGroup* NoesisTimelineGroup = NsDynamicCast<Noesis::Gui::TimelineGroup*>(NoesisComponent.GetPtr());
	check(NoesisTimelineGroup);
	return CastChecked<UNoesisTimelineCollection>(CreateClassFor(NoesisTimelineGroup->GetChildren(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTimelineGroup::SetChildren(class UNoesisTimelineCollection* InChildren)
{
	Noesis::Gui::TimelineGroup* NoesisTimelineGroup = NsDynamicCast<Noesis::Gui::TimelineGroup*>(NoesisComponent.GetPtr());
	check(NoesisTimelineGroup);
	NoesisTimelineGroup->SetChildren(NsDynamicCast<TimelineCollection*>(InChildren->NoesisComponent.GetPtr()));
}

void UNoesisTimelineGroup::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TimelineGroup* NoesisTimelineGroup = NsDynamicCast<Noesis::Gui::TimelineGroup*>(NoesisComponent.GetPtr());
	check(NoesisTimelineGroup);


}

void UNoesisTimelineGroup::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TimelineGroup* NoesisTimelineGroup = NsDynamicCast<Noesis::Gui::TimelineGroup*>(NoesisComponent.GetPtr());
	check(NoesisTimelineGroup);


}

