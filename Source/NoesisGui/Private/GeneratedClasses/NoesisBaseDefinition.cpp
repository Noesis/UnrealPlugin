////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBaseDefinition.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseDefinition::UNoesisBaseDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBaseDefinition::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseDefinition* NoesisBaseDefinition = NsDynamicCast<Noesis::Gui::BaseDefinition*>(InNoesisComponent);
	check(NoesisBaseDefinition);
}

FString UNoesisBaseDefinition::GetSharedSizeGroup()
{
	Noesis::Gui::BaseDefinition* NoesisBaseDefinition = NsDynamicCast<Noesis::Gui::BaseDefinition*>(NoesisComponent.GetPtr());
	check(NoesisBaseDefinition);
	return NsStringToFString(NoesisBaseDefinition->GetSharedSizeGroup());
}

void UNoesisBaseDefinition::SetSharedSizeGroup(FString InSharedSizeGroup)
{
	Noesis::Gui::BaseDefinition* NoesisBaseDefinition = NsDynamicCast<Noesis::Gui::BaseDefinition*>(NoesisComponent.GetPtr());
	check(NoesisBaseDefinition);
	NoesisBaseDefinition->SetSharedSizeGroup(StringCast<NsChar>(*InSharedSizeGroup).Get());
}

void UNoesisBaseDefinition::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseDefinition* NoesisBaseDefinition = NsDynamicCast<Noesis::Gui::BaseDefinition*>(NoesisComponent.GetPtr());
	check(NoesisBaseDefinition)


}

void UNoesisBaseDefinition::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseDefinition* NoesisBaseDefinition = NsDynamicCast<Noesis::Gui::BaseDefinition*>(NoesisComponent.GetPtr());
	check(NoesisBaseDefinition)


}

