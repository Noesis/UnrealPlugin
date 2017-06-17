////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisQuinticEase.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisQuinticEase::UNoesisQuinticEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::QuinticEase::StaticGetClassType();
}

void UNoesisQuinticEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::QuinticEase* NoesisQuinticEase = NsDynamicCast<Noesis::Gui::QuinticEase*>(InNoesisComponent);
	check(NoesisQuinticEase);
}

void UNoesisQuinticEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::QuinticEase* NoesisQuinticEase = NsDynamicCast<Noesis::Gui::QuinticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuinticEase);


}

void UNoesisQuinticEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::QuinticEase* NoesisQuinticEase = NsDynamicCast<Noesis::Gui::QuinticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuinticEase);


}

