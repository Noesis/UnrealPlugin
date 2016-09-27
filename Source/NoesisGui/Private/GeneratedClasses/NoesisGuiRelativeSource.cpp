////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRelativeSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRelativeSource::UNoesisGuiRelativeSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRelativeSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(InNoesisComponent);
	check(NoesisRelativeSource);

}

int32 UNoesisGuiRelativeSource::GetAncestorLevel()
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	return NoesisRelativeSource->GetAncestorLevel();
}

void UNoesisGuiRelativeSource::SetAncestorLevel(int32 InAncestorLevel)
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	NoesisRelativeSource->SetAncestorLevel(InAncestorLevel);
}

class UNoesisGuiResourceKeyType* UNoesisGuiRelativeSource::GetAncestorType()
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	return CastChecked<UNoesisGuiResourceKeyType>(Instance->FindUnrealComponentForNoesisComponent(NoesisRelativeSource->GetAncestorType()));
}

void UNoesisGuiRelativeSource::SetAncestorType(class UNoesisGuiResourceKeyType* InAncestorType)
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	NoesisRelativeSource->SetAncestorType(NsDynamicCast<ResourceKeyType*>(InAncestorType->NoesisComponent.GetPtr()));
}

ENoesisGuiRelativeSourceMode UNoesisGuiRelativeSource::GetMode()
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	return (ENoesisGuiRelativeSourceMode)NoesisRelativeSource->GetMode();
}

void UNoesisGuiRelativeSource::SetMode(ENoesisGuiRelativeSourceMode InMode)
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	NoesisRelativeSource->SetMode((RelativeSourceMode)InMode);
}

	void UNoesisGuiRelativeSource::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	if (!NoesisRelativeSource)
		return;

}

