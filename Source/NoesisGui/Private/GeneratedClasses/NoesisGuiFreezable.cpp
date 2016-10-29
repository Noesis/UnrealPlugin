////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiFreezable.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiFreezable::UNoesisGuiFreezable(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiFreezable::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(InNoesisComponent);
	check(NoesisFreezable);
}

bool UNoesisGuiFreezable::CanFreeze()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return NoesisFreezable->CanFreeze();
}

class UNoesisGuiFreezable* UNoesisGuiFreezable::Clone()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisGuiFreezable>(Instance->FindUnrealComponentForNoesisComponent(NoesisFreezable->Clone()));
}

class UNoesisGuiFreezable* UNoesisGuiFreezable::CloneCurrentValue()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisGuiFreezable>(Instance->FindUnrealComponentForNoesisComponent(NoesisFreezable->CloneCurrentValue()));
}

void UNoesisGuiFreezable::Freeze()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return NoesisFreezable->Freeze();
}

class UNoesisGuiFreezable* UNoesisGuiFreezable::GetAsFrozen()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisGuiFreezable>(Instance->FindUnrealComponentForNoesisComponent(NoesisFreezable->GetAsFrozen()));
}

class UNoesisGuiFreezable* UNoesisGuiFreezable::GetCurrentValueAsFrozen()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisGuiFreezable>(Instance->FindUnrealComponentForNoesisComponent(NoesisFreezable->GetCurrentValueAsFrozen()));
}

bool UNoesisGuiFreezable::IsFrozen()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return NoesisFreezable->IsFrozen();
}

void UNoesisGuiFreezable::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable)


}

void UNoesisGuiFreezable::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable)


}

