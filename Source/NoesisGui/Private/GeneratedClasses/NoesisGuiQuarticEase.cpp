////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiQuarticEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiQuarticEase::UNoesisGuiQuarticEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiQuarticEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::QuarticEase* NoesisQuarticEase = NsDynamicCast<Noesis::Gui::QuarticEase*>(InNoesisComponent);
	check(NoesisQuarticEase);
}

void UNoesisGuiQuarticEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::QuarticEase* NoesisQuarticEase = NsDynamicCast<Noesis::Gui::QuarticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuarticEase)


}

void UNoesisGuiQuarticEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::QuarticEase* NoesisQuarticEase = NsDynamicCast<Noesis::Gui::QuarticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuarticEase)


}

