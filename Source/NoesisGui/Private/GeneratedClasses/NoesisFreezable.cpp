////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisFreezable.h"

using namespace Noesis;
using namespace Gui;

UNoesisFreezable::UNoesisFreezable(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Freezable::StaticGetClassType();
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
	return CastChecked<UNoesisFreezable>(CreateClassFor(NoesisFreezable->Clone(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisFreezable* UNoesisFreezable::CloneCurrentValue()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisFreezable>(CreateClassFor(NoesisFreezable->CloneCurrentValue(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisFreezable>(CreateClassFor(NoesisFreezable->GetAsFrozen(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisFreezable* UNoesisFreezable::GetCurrentValueAsFrozen()
{
	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);
	return CastChecked<UNoesisFreezable>(CreateClassFor(NoesisFreezable->GetCurrentValueAsFrozen(), nullptr), ECastCheckedType::NullAllowed);
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
	check(NoesisFreezable);


}

void UNoesisFreezable::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	check(NoesisFreezable);


}

