////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisRelativeSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisRelativeSource::UNoesisRelativeSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisRelativeSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(InNoesisComponent);
	check(NoesisRelativeSource);
}

int32 UNoesisRelativeSource::GetAncestorLevel()
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	return NoesisRelativeSource->GetAncestorLevel();
}

void UNoesisRelativeSource::SetAncestorLevel(int32 InAncestorLevel)
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	NoesisRelativeSource->SetAncestorLevel(InAncestorLevel);
}

class UNoesisResourceKeyType* UNoesisRelativeSource::GetAncestorType()
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	return CastChecked<UNoesisResourceKeyType>(Instance->FindUnrealComponentForNoesisComponent(NoesisRelativeSource->GetAncestorType()));
}

void UNoesisRelativeSource::SetAncestorType(class UNoesisResourceKeyType* InAncestorType)
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	NoesisRelativeSource->SetAncestorType(NsDynamicCast<ResourceKeyType*>(InAncestorType->NoesisComponent.GetPtr()));
}

ENoesisRelativeSourceMode UNoesisRelativeSource::GetMode()
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	return (ENoesisRelativeSourceMode)NoesisRelativeSource->GetMode();
}

void UNoesisRelativeSource::SetMode(ENoesisRelativeSourceMode InMode)
{
	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource);
	NoesisRelativeSource->SetMode((Noesis::Gui::RelativeSourceMode)InMode);
}

void UNoesisRelativeSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource)


}

void UNoesisRelativeSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RelativeSource* NoesisRelativeSource = NsDynamicCast<Noesis::Gui::RelativeSource*>(NoesisComponent.GetPtr());
	check(NoesisRelativeSource)


}

