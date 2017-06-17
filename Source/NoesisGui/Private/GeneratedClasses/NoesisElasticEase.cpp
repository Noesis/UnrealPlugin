////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisElasticEase.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisElasticEase::UNoesisElasticEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ElasticEase::StaticGetClassType();
}

void UNoesisElasticEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(InNoesisComponent);
	check(NoesisElasticEase);
}

int32 UNoesisElasticEase::GetOscillations()
{
	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(NoesisComponent.GetPtr());
	check(NoesisElasticEase);
	return NoesisElasticEase->GetOscillations();
}

void UNoesisElasticEase::SetOscillations(int32 InOscillations)
{
	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(NoesisComponent.GetPtr());
	check(NoesisElasticEase);
	NoesisElasticEase->SetOscillations(InOscillations);
}

float UNoesisElasticEase::GetSpringiness()
{
	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(NoesisComponent.GetPtr());
	check(NoesisElasticEase);
	return (float)NoesisElasticEase->GetSpringiness();
}

void UNoesisElasticEase::SetSpringiness(float InSpringiness)
{
	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(NoesisComponent.GetPtr());
	check(NoesisElasticEase);
	NoesisElasticEase->SetSpringiness(InSpringiness);
}

void UNoesisElasticEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(NoesisComponent.GetPtr());
	check(NoesisElasticEase);


}

void UNoesisElasticEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ElasticEase* NoesisElasticEase = NsDynamicCast<Noesis::Gui::ElasticEase*>(NoesisComponent.GetPtr());
	check(NoesisElasticEase);


}

