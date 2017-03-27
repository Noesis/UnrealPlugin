////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisBaseSetter.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseSetter::UNoesisBaseSetter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BaseSetter::StaticGetClassType();
}

void UNoesisBaseSetter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseSetter* NoesisBaseSetter = NsDynamicCast<Noesis::Gui::BaseSetter*>(InNoesisComponent);
	check(NoesisBaseSetter);
}

void UNoesisBaseSetter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseSetter* NoesisBaseSetter = NsDynamicCast<Noesis::Gui::BaseSetter*>(NoesisComponent.GetPtr());
	check(NoesisBaseSetter);


}

void UNoesisBaseSetter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseSetter* NoesisBaseSetter = NsDynamicCast<Noesis::Gui::BaseSetter*>(NoesisComponent.GetPtr());
	check(NoesisBaseSetter);


}

