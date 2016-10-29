////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiElasticEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiElasticEase::UNoesisGuiElasticEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiElasticEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(InNoesisComponent);
	check(NoesisElasticEase);
}

void UNoesisGuiElasticEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(NoesisComponent.GetPtr());
	check(NoesisElasticEase)


}

void UNoesisGuiElasticEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(NoesisComponent.GetPtr());
	check(NoesisElasticEase)


}

