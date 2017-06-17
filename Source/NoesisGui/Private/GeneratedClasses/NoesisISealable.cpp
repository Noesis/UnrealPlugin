////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisISealable.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisISealable::UNoesisISealable(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::ISealable::StaticGetClassType();
}

void UNoesisISealable::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ISealable* NoesisISealable = NsDynamicCast<Noesis::Gui::ISealable*>(InNoesisInterface);
	check(NoesisISealable);
}

bool UNoesisISealable::CanSeal()
{
	Noesis::Gui::ISealable* NoesisISealable = NsDynamicCast<Noesis::Gui::ISealable*>(NoesisInterface.GetPtr());
	check(NoesisISealable);
	return NoesisISealable->CanSeal();
}

bool UNoesisISealable::IsSealed()
{
	Noesis::Gui::ISealable* NoesisISealable = NsDynamicCast<Noesis::Gui::ISealable*>(NoesisInterface.GetPtr());
	check(NoesisISealable);
	return NoesisISealable->IsSealed();
}

void UNoesisISealable::Seal()
{
	Noesis::Gui::ISealable* NoesisISealable = NsDynamicCast<Noesis::Gui::ISealable*>(NoesisInterface.GetPtr());
	check(NoesisISealable);
	return NoesisISealable->Seal();
}

void UNoesisISealable::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ISealable* NoesisISealable = NsDynamicCast<Noesis::Gui::ISealable*>(NoesisInterface.GetPtr());
	check(NoesisISealable);


}

void UNoesisISealable::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ISealable* NoesisISealable = NsDynamicCast<Noesis::Gui::ISealable*>(NoesisInterface.GetPtr());
	check(NoesisISealable);


}

