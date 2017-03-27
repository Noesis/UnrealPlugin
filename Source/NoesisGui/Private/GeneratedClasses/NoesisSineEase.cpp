////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisSineEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisSineEase::UNoesisSineEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::SineEase::StaticGetClassType();
}

void UNoesisSineEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SineEase* NoesisSineEase = NsDynamicCast<Noesis::Gui::SineEase*>(InNoesisComponent);
	check(NoesisSineEase);
}

void UNoesisSineEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SineEase* NoesisSineEase = NsDynamicCast<Noesis::Gui::SineEase*>(NoesisComponent.GetPtr());
	check(NoesisSineEase);


}

void UNoesisSineEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SineEase* NoesisSineEase = NsDynamicCast<Noesis::Gui::SineEase*>(NoesisComponent.GetPtr());
	check(NoesisSineEase);


}

