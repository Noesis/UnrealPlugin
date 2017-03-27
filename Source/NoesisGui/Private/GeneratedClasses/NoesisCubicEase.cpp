////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisCubicEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisCubicEase::UNoesisCubicEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::CubicEase::StaticGetClassType();
}

void UNoesisCubicEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CubicEase* NoesisCubicEase = NsDynamicCast<Noesis::Gui::CubicEase*>(InNoesisComponent);
	check(NoesisCubicEase);
}

void UNoesisCubicEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CubicEase* NoesisCubicEase = NsDynamicCast<Noesis::Gui::CubicEase*>(NoesisComponent.GetPtr());
	check(NoesisCubicEase);


}

void UNoesisCubicEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CubicEase* NoesisCubicEase = NsDynamicCast<Noesis::Gui::CubicEase*>(NoesisComponent.GetPtr());
	check(NoesisCubicEase);


}

