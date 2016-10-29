////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBounceEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBounceEase::UNoesisGuiBounceEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBounceEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(InNoesisComponent);
	check(NoesisBounceEase);
}

void UNoesisGuiBounceEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(NoesisComponent.GetPtr());
	check(NoesisBounceEase)


}

void UNoesisGuiBounceEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(NoesisComponent.GetPtr());
	check(NoesisBounceEase)


}

