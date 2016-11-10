////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisFreezable.h"

using namespace Noesis;
using namespace Gui;

UNoesisFreezable::UNoesisFreezable(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisFreezable::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(InNoesisComponent);
	check(NoesisFreezable);
}

bool UNoesisFreezable::CanFreeze()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return NoesisFreezable->CanFreeze();
}

class UNoesisFreezable* UNoesisFreezable::Clone()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisFreezable>(Instance->FindUnrealComponentForNoesisComponent(NoesisFreezable->Clone()));
}

class UNoesisFreezable* UNoesisFreezable::CloneCurrentValue()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisFreezable>(Instance->FindUnrealComponentForNoesisComponent(NoesisFreezable->CloneCurrentValue()));
}

void UNoesisFreezable::Freeze()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return NoesisFreezable->Freeze();
}

class UNoesisFreezable* UNoesisFreezable::GetAsFrozen()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisFreezable>(Instance->FindUnrealComponentForNoesisComponent(NoesisFreezable->GetAsFrozen()));
}

class UNoesisFreezable* UNoesisFreezable::GetCurrentValueAsFrozen()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisFreezable>(Instance->FindUnrealComponentForNoesisComponent(NoesisFreezable->GetCurrentValueAsFrozen()));
}

bool UNoesisFreezable::IsFrozen()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return NoesisFreezable->IsFrozen();
}

void UNoesisFreezable::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable)


}

void UNoesisFreezable::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable)


}

